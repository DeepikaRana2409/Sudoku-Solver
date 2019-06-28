//Sudoku Solver using recursion and Back-tracking

#include<iostream>
#include<cmath>

using namespace std;


//Function to backtrack if number being placed is at correct position

bool IsPosssibleToPlace(int matrix[][9],int matrix_size,int row,int column,int number)
{
    for(int row_or_column=0;row_or_column<matrix_size;row_or_column++)
    {
        //To check that the entire row or column does not coincides with number

        if(matrix[row][row_or_column]==number||matrix[row_or_column][column]==number)
        {
            return false;
        }
    }

    //For the smaller matrix_size boxes
    matrix_size=sqrt(matrix_size);


    //To obtain the starting row and column number of the smaller box
    int row_start=(row/matrix_size)*matrix_size;
    int col_start=(column/matrix_size)*matrix_size;


    for(int row_number=row_start;row_number<row_start+matrix_size;row_number++)
    {
        for(int col_number=col_start;col_number<col_start+matrix_size;col_number++)
        {
            //To check that the sqrt(matrix_size)*sqrt(matrix_size) does not have the same number already

            if(matrix[row_number][col_number]==number)
            {
                return false;
            }
        }
    }

    //Since none of the conditions is true then it is possible to place the number
    return true;
}

//Function for solving Sudoku

bool SolvedSudoku(int matrix[][9],int matrix_size,int row,int column)
{

    //Base Case

    //End of the  sudoku
    if(row==matrix_size)
    {
        //Solved Sudoku being printed
        for(int row_number=0;row_number<matrix_size;row_number++)
        {
            //Horizontal dashes suitable only for 9X9 sudoku
            cout<<"\n  ___ ___ ___ ___ ___ ___ ___ ___ ___\n";

            for(int col_number=0;col_number<matrix_size;col_number++)
            {
                cout<<" | "<<matrix[row_number][col_number];
            }

        }
        cout<<"\n";
        return true;
    }

    //End of the column is reached so row number being incremented
    if(column==matrix_size)
    {
        return SolvedSudoku(matrix,matrix_size,row+1,0);
    }

    //Cell is not empty so column number being incremented
    if(matrix[row][column]!=0)
    {
        return SolvedSudoku(matrix,matrix_size,row,column+1);
    }


    //Recursive Case
    for(int number=1;number<=matrix_size;number++)
    {
        if(IsPosssibleToPlace(matrix,matrix_size,row,column,number))
        {
            matrix[row][column]=number;

            bool IsRestSolved=SolvedSudoku(matrix,matrix_size,row,column+1);

            if(IsRestSolved)
            {
                return true;
            }
        }
        matrix[row][column]=0;
    }
    //Since none of the conditions is true then false being returned
    return false;
}
int main()
{
    //Here is a sample matrix
    int matrix[9][9]={
        {5,3,0,0,7,0,0,0,0},
		{6,0,0,1,9,5,0,0,0},
		{0,9,8,0,0,0,0,6,0},
		{8,0,0,0,6,0,0,0,3},
		{4,0,0,8,0,3,0,0,1},
		{7,0,0,0,2,0,0,0,6},
		{0,6,0,0,0,0,2,8,0},
		{0,0,0,4,1,9,0,0,5},
		{0,0,0,0,8,0,0,7,9}};

	//Cell which is empty has to be given 0 input


	//Here the size of sudoku is taken as 9
    cout<<"\n The solution of the the sample SUDOKU \n";

    SolvedSudoku(matrix,9,0,0);


//If specific sudoku has to be solved


//	int matrix_size;
//  cout<<"Enter Sudoku Size ";
//  cin>>matrix_size;
//	int matrix[9][9];
//  cout<<"Enter Sudoku ";

//	for(int row=0;row<matrix_size;row++)
//    {
//        for(int column=0;column<matrix_size;column++)
//        {
//            cin>>matrix[row][column];
//        }
//    }

//    cout<<" The solution of the the SUDOKU entered ";

//    SolvedSudoku(matrix,9,0,0);

	return 0;

}


