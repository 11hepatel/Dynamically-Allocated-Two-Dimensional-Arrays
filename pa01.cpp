/**
Implement the main here to match input and output.
**/

#include "matrix_search.h"

int main()
{

  int rows; //declared variable for rows
  int cols; //declared variable for columns
  int cases; //declared variable for number of cases
  //declared variable for array size

  int sol[4]; //declaring the sol array
  string word; //declare variable for a string word

  cin >> cases; //gets input for number of cases

  for(int i = 0; i < cases; i++) //iterats for however many number of cases
  {
    cin >> rows >> cols; //gets input for number of rows and columns

    char **arr = NULL; //intizing the pointer array to null
    arr = build_matrix(rows,cols); //calling the build_matrix function

    fill_matrix(rows, cols, arr); //calling the fill_matrix function
      
    cin >> word; //gets input for word being searched in the matrix

    matrix_search(sol, word, rows, cols, arr); //calling the matrix_search

    //outputs the word that is being searched with the case number
    cout << "Searching for \""<< word << "\" in matrix " 
                                     << i << " yields: " << endl;

    //checks if sol[0] (start row) is equal to 0
    if(sol[0] == -1)
    {
      cout << "The pattern was not found." << endl; //outputs message below
      cout << endl; //another endl for the space between the outputs
    }
    else //else it will output the start and end index of the word being
                // searched for in the matrix using the following format
    {
      cout << "Start pos:(" << sol[0] << ", " << sol[1] << ") to End pos:(" 
                                << sol[2] << ", " << sol[3] << ")" << endl;
      cout << endl;
    }
    delete_matrix(rows, arr); //calls the delete_matrix function to delete 
                             //the 2d matrix
  }
  
  return 0; //returns 0
}
