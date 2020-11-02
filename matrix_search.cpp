/**
Here in the .cpp you should define and implement the functions that are declared in the .h file.
It is not recommended to add extra functions on this assignment.
**/

#include "matrix_search.h"


// We're giving you this one the first time, and you should copy it into all
// future assignments.
// Change the information to your own email handle (S&T username)
void get_identity(string &my_id)
{
  my_id = "hdpg4c"; //setting my_id to my mst username
}

//Builds a two dimensional dynamic array of the given size
char ** build_matrix(int rows, int cols)
{

  char **array; //matrix array pointer declared

  array = new char* [rows]; //dynamic array of pointers to char
  for(int i = 0; i < rows; i++) //for loop to point to dynamic array
    array[i] = new char[cols]; //each i-th pointer is pointing to 2d array 
                               //of char values

  return array; //returns a char pointer for matrix
}

//Fills the matrix using the cin
void fill_matrix(int rows, int cols, char **matrix)
{
  //for loop to get fill each index of the matrix using the input
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < cols; j++)
      cin >> matrix[i][j]; //gets the inputs via cin to fill the matrix
  }
  return; //returns nothing since its void
}

//Function to print the filled array
void print_matrix(int rows, int cols, char **matrix)
{
 //for loop for outputing the filled matrix
  for(int i = 0; i < rows; i++)//loops on the rows
  {
    for(int j = 0; j < cols; j++)//loops on the columns
    {
      cout << matrix[i][j] << ' '; //outputs the filled matrix
    }
    cout << endl;
  }
  return; //returns nothing since its a void
}

//Function to delete a dynamically allocated 2D array
void delete_matrix(int rows, char **matrix)
{
  for(int i = 0; i < rows; i++) //deleting each rows array
  {
    delete[] matrix[i];
  }
  delete[] matrix; //deleting the entire matrix
}

//Function to search the inputed word from the allocated 2d array
void matrix_search(int sol[], string word, int rows, int cols, char **matrix)
{
  bool wordFound = false; //boolean set to false
  int charplace; //variable declaration for character index in the string

  //search matrix from left to right
  if(!wordFound)
  {
    charplace = 0;// charplace set to 0; we want it to start from index 0

    for(int i = 0; i < rows; i++) //loop through the rows
    {
      for(int j = 0; j < cols; j++) //loop through the columns
      {
        if(word[charplace] == matrix[i][j]) //if the character is equal to
                             // the matrix array row and column character
        {
          if(word.size() == charplace + 1)//if the word size is equal
                                          // to the charplace + 1
          {
            wordFound = true; //word found is set to true
            sol[2] = i; //end row array is set to the row
            sol[3] = j; //end column array is set to the column
          }
          else if(charplace == 0) //if charplace is 0 then
          {
            sol[0] = i; //start row array is set to the row
            sol[1] = j; //start column array is set to the column
            charplace++;
          }
          else //else
          {
            charplace++; //charplace is incremented by 1
          }
        }
        else //else
        {
          charplace = 0; //charplace is set to 0
        }
      }
    }
  }

  //Search matrix from right to left
  if(!wordFound)
  {
    charplace = 0; //setting charplace to zero
    for(int i = 0; i < rows; i++) //itreates through each rows
    {
      for(int j = 0; j < cols; j++) //iterates throught each columns
      {
        charplace = 0; //sets charplace to zero

        //checks if word charplace is equal to matrix[row][column] and
        //wordfound to be false
        if(word[charplace] == matrix[i][j] && j - 1 >= 0 && !wordFound)
        {
          charplace++; //increment charplace
          int c = j - 1; //newvariable for column and set to j - 1
          sol[0] = i; //sets the start row to i
          sol[1] = j; //sets the start column

          //goes through the loop while the word is not found and
          //word charplace is equal to matrix[i][j]
          while(!wordFound && word[charplace] == matrix[i][c])
          {
            //checks if the word size is equal to charplace + 1
            if(word.size() == charplace + 1)
            {
              wordFound = true; //sets wordfound to true
              sol[2] =  i; //sets the end row
              sol[3] = c; //sets the end column
            }
            else
            {
              c--; //decrement column c( j - 1)
              charplace++; //increment charplace
            }
          }
        }
      }
    }
  }

  //search matrix from up to down
  if(!wordFound)
  {
    charplace = 0; //sets charplace to zero
    for(int i = 0; i < cols; i++) //iterates throught each rows
    {
      for(int j = 0; j < rows; j++)//iterates throught each columns
      {
        //checks if word charplace is equal to matrix[row][column]
        if(word[charplace] == matrix[j][i])
        {
          if(word.size() == charplace + 1) //checks if word size is equal to
                                           //charplace + 1
          {
            wordFound = true; //yes, then sets the wordfound to true
            sol[2] = j; //sets end row
            sol[3] = i; //sets end column
          }
          else if(charplace == 0) //check if charplace is equal to zero
          {
            sol[0] = j; //yes, then sets the start row
            sol[1] = i; //sets the end column
            charplace++; //increments the charplace
          }
          else //if none of the previous condition work, then it goes and
               //increments the charplace
          {
            charplace++; //increments the charplace
          }
        }
        else
        {
          charplace = 0; //sets the charplace to zero
        }
      }
    }
  }

  //Search matrix from down to up
  if(!wordFound)
  {
    charplace = 0; //sets charplace to zero
    for(int i = cols - 1; i >= 0; i--) //iterates throught each rows
    {
      for(int j = rows - 1; j >= 0; j--) //iterates throught each columns
      {
        //checks if word charplace is equal to matrix[row][column]
        if(word[charplace] == matrix[j][i])
        {
          if(word.size() == charplace + 1) //checks if word size is equal to
                                           //charplace + 1
          {
            wordFound = true; //if yes, then sets wordfound to true
            sol[2] = j; //sets the end row
            sol[3] = i; //sets the end column
          }
          else if(charplace == 0) //checks if charplace is equal to zero
          {
            sol[0] = j; //sets the start row
            sol[1] = i; //sets the start column
            charplace++; //increments the charplace by 1
          }
          else
          {
            charplace++; //increments the charplace by 1
          }
        }
        else
        {
          charplace = 0; //charplace is set to 0
        }
      }
    }
  }

  //searched the matrix from left to right diagonally
  if(!wordFound)
  {
    for(int i = 0; i < rows; i++) //iterates throught each rows
    {
      for(int j = 0; j < cols; j++) //iterates throught each columns
      {
        //checks if word charplace is equal to matrix[row][column]
        if(word[charplace] == matrix[i][j])
        {
         if(charplace == 0) //checks if charplace is equal to zero
          {
            sol[0] = i; //sets the start row
            sol[1] = j; //sets the start column
            charplace++; //increments the charplace by 1

            //checks if (row + 1) is less than inputed rows &
            //(cols + 1) is less than inputed column &
            //row - 1 is greater than or equal to 0
            //checks if the its in the matrix boundry
            if((i + 1 < rows) && (j + 1 < cols) && (i - 1 >= 0) )
            {
              //checks if word charplace is equal to matrix[row][column]
              if(word[charplace] == matrix[i+1][j+1])
              {
                int r = i + 1; //new variable to store i + 1 value
                int c = j + 1; //new variable to store j + 1 value

                //loops while r is less than rows & c is less than cols &
                //checks if word charplace is equal to matrix[r][c]
                while(r < rows && c < cols &&
                                       (word[charplace] == matrix[r][c]))
                {
                  //checks if word size is equal to charplace
                  if(word.size() == charplace)
                  {
                    sol[2] = r; //sets the end row
                    sol[3] = c; //sets the end column
                    wordFound = true; //wordfound is set to true
                    break; //break
                  }

                  //checks if wordplace is not equal to matrix[r][c]
                  else if(word[charplace] != matrix[r][c])
                  {
                    charplace = 0; //sets charplace to zero
                  }
                  else
                  {
                    charplace++; //increments the charplace by 1
                    r++; //increments the r by 1
                    c++; //increments the c by 1
                  }
                }
              }

              //checks if wordcharplace is equal to matrix[row -1][column + 1]
              else if(word[charplace] == matrix[i-1][j+1])
              {
                int r = i - 1; //new variable to store the i - 1 value
                int c = j + 1; //new variable to store the j + 1 value

                //loops while r is less than rows & c is less than cols &
                //checks if word charplace is equal to matrix[r][c]
                while(r < rows && c < cols &&
                                     (word[charplace] == matrix[r][c]))
                {
                  //checks if word size is equal to charplace + 1
                  if(word.size() == charplace + 1)
                  {
                    sol[2] = r; //set the end row
                    sol[3] = c; //sets the end column
                    wordFound = true; //sets the wordfound to true
                    break;
                  }
                  //checks if word[charplace] is not equal to matrix[r][c]
                  else if(word[charplace] != matrix[r][c])
                  {
                    charplace = 0; //sets charplace to zero
                  }
                  else
                  {
                    charplace++; //increments the charplace by 1
                    r--; //decrements the r by 1
                    c++; //incerements the c by 1
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  //Search the matrix from Right to left diagonally
  if(!wordFound)
  {
    charplace = 0; //sets charplace to 0
    for(int i = 0; i < rows; i++) //iterates throught each rows
    {
      for(int j = 0; j < cols; j++) //iterates throught each columns
      {
        //checks if word charplace is equal to matrix[row][column]
        if(word[charplace] == matrix[i][j])
        {
          if(charplace == 0) //checks if charplace is equal to zero.
                            // yes, then
          {
            sol[0] = i; //sets the start row to i
            sol[1] = j; //set the start column to j
            charplace++;  //increments the charplace by 1

            //checks if (row + 1) is less than inputed rows &
            //(cols + 1) is less than inputed column &
            //row - 1 is greater than or equal to 0 &
            //column - 1 is greater then or equal to 0
            //checks if the its in the matrix boundry
            if((i + 1 < rows) && (j + 1 < cols) &&
                                     (i - 1 >= 0) && (j - 1 >= 0))
            {
              //checks if the word[charplace] is equal to matrix[i+1][j-1]
              if(word[charplace] == matrix[i+1][j-1])
              {
                int r = i + 1; //new variable to store i + 1
                int c = j - 1; //new variable to store j - 1

                //loops while r is less than rows & c is less than cols &
                //checks if word charplace is equal to matrix[r][c]
                while(r < rows && c < cols &&
                                    (word[charplace] == matrix[r][c]))
                {
                  //checks if word size is equal to charplace + 1
                  if(word.size() == charplace + 1)
                  {
                    sol[2] = r; //sets the end row
                    sol[3] = c; //sets the end column
                    wordFound = true; //wordfound set to true
                    break;
                  }
                  else
                  {
                    charplace++; //increments the charplace by 1
                    r++; //increments the r by 1
                    c--; //derements the c by 1
                  }
                }
              }

              //checks if work[wordcharplace] is equal to matrix[row-1][col-1]
              else if(word[charplace] == matrix[i-1][j-1])
              {
                int r = i - 1; //new variable to store i - 1 value
                int c = j - 1; // new varaible to store j - 1 value

                //loops while r is less than rows & c is less than cols &
                //checks if word charplace is equal to matrix[r][c]
                while(r < rows && c < cols &&
                             (word[charplace] == matrix[r][c]))
                {
                  if(word.size() == charplace + 1)
                  {
                    sol[2] = r; //sets end row to r
                    sol[3] = c; //sets end column to c
                    wordFound = true; //wordfound set to true
                    break;
                  }
                  else
                  {
                    charplace++; //increments charplace by 1
                    r--; //decrements the r by 1
                    c--; //decrements the c by 1
                  }
                }
              }

              //checks if word[charplace] is not equal to matrix[row-1][col-1]
              if(word[charplace] != matrix[i-1][j-1] && word[charplace]
                                                      != matrix[i+1][j+1])
              {
                charplace = 0; //charplace is set to zero
              }
            }
          }
        }
      }
    }
  }

  //if the word is not found then sets all of the sol arrays to -1
  if(!wordFound)
  {
    sol[0] = -1; //set start row to -1
    sol[1] = -1; //set start column to -1
    sol[2] = -1; //set end row to -1
    sol[3] = -1; //set end column to -1
  }

  return; //returns nothing sinze its void
}
