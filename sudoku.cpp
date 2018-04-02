/***********************************************************************
* Program:
*    Project 12, Sudoku
*    Brother Ridges, CS124
* Author:
*    Jason Halverson
* Summary: 
*   Write a program to allow the user to play Sudoku. For details on the rules 
*   of the game, see: http://en.wikipedia.org/wiki/Sudoku
*
*   The program will prompt the user for the filename of the game he or she is 
*   currently working on and display the board on the screen. The user will 
*   then be allowed to interact with the game by selecting which square he or 
*   she wishes to change. While the program will not solve the game for the 
*   user, it will ensure that the user has not selected an invalid number. If 
*   the user types 'S' in the prompt, then the program will show the user the 
*   possible valid numbers for a given square. When the user is finished, then 
*   the program will save the board to a given filename and exit.
*
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <ctype.h>
using namespace std;


void openGame(char board[][9]);
string promptFile();
void readBoard(char board[][9], string fileName);

void displayBoard(char board[][9]);

void playGame(char board[][9]);
char getChoice();
void displayMenu();
void editSquare(int rowCol[], char board[][9]);
string promptSquare(int rowCol[], char board[][9]);

int* getPossibles(int rowCol[], char board[][9]);
int* createArray(int size);
void expandArray(int* array, int size);

void saveGame(char board[][9]);
string promptSaveFile();

/**********************************************************************
 * Calls openGame() , playGame(), saveGame() passing the board pointer
 ***********************************************************************/
int main()
{
	char board[9][9];
	openGame(board);

	playGame(board);
	// saveGame(board);

   return 0;
}

/**********************************************************************
 * openGame calls promptFile() openFile() and readFile()
 ***********************************************************************/
void openGame(char board[][9])
{
	string fileName = promptFile();
   readBoard(board, fileName);

}

/**********************************************************************
 * prompts the user for a filename
 ***********************************************************************/
string promptFile()
{
	string fileName;
	cout << "Where is your board located? ";
	cin >> fileName;

	return fileName;
}

/**********************************************************************
 * prompts the user for a filename
 * read the board into memory
 ***********************************************************************/
void readBoard(char board[][9], string fileName)
{
   int counter = 0;
   // open the file for reading changed string to c_string
   ifstream fin(fileName.c_str());

   // error check  
   if (fin.fail())
   {
      // inform user of the error
      cout << "Unable to open file "
         << fileName
         << endl;
   }

   // loop through every line
   // c++ ... my little joke
   for (int c = 0; !fin.eof(); c++)
   {
      // loop through every char
      // a++ ..... the grade I want
      for (int a = 0; a < 9; a++)
      {
         fin >> board[c][a] ;
      }
   }

   fin.close();

}

/**********************************************************************
 * playGame contains all the game logic
 ***********************************************************************/
void playGame(char board[][9])
{
   bool exit = false;
   int rowCol[2];
   displayMenu();
   displayBoard(board);

   do
   {

      switch (getChoice())
      {
         case '?':
            displayMenu();
            cout << endl;
            break;
         case 'D':
            displayBoard(board);
            break;
         case 'E':
            editSquare(rowCol, board);
            break;
         case 'S':
            int* possibles;
            if(promptSquare(rowCol,board) != "error")
               {
                  possibles = getPossibles(rowCol,board);
               }
            delete[] possibles;
            possibles = NULL;
            break;
         case 'Q':
            exit = true;
            saveGame(board);
            break;
         default:
            cout << "Please enter a valid Choice";
            break;
         
      }


   } while (!exit);
}

/**********************************************************************
 * get the users choice
 ***********************************************************************/
char getChoice()
{
   char choice;
   cout << "> ";
   cin >> choice;

   return toupper(choice);
}

/**********************************************************************
 * displays the menu
 ***********************************************************************/
void displayMenu()
{
   cout << "Options:\n";
   cout << "   ?  Show these instructions\n";
   cout << "   D  Display the board\n";
   cout << "   E  Edit one square\n";
   cout << "   S  Show the possible values for a square\n";
   cout << "   Q  Save and Quit\n\n";
}

/**********************************************************************
 * displays the board
 ***********************************************************************/
void displayBoard(char board[][9])
{
   cout << "   A B C D E F G H I\n";
   // display rows
   for (int row = 0; row < 9; row++)
      {

         if (row !=0 && row % 3 == 0)
         {
            cout << "   -----+-----+-----\n";
         }

         cout << row +1 << "  ";
         
         // display columns
         for (int col = 0; col < 9; col++)
         {
            if (col != 0 && col % 3 == 0)
            {
               cout << "|";
            }


            if ((col + 1) % 3 == 0)
            {
               if (board[row][col] == '0')
               {
                  cout << " ";
               }
               else
               {
                  cout << board[row][col];
               }
            }
            else
            {
               if (board[row][col] == '0')
               {
                  cout << "  ";
               }
               else
               {
                  cout << board[row][col] << " ";
               }
            }
            
         }

         cout << endl;
      }
   cout << endl;
}

/**********************************************************************
 * edits the chosen square
 ***********************************************************************/
void editSquare(int rowCol[], char board[][9])
{  
   string choice = promptSquare(rowCol,board);
   char value;
   int row = rowCol[0];
   int col = rowCol[1];

   if (choice != "error")
   {
      cout << "What is the value at '" << choice << "': ";
      cin >> value;
      board[row][col] = value;
      cout << endl;
   }

}

/**********************************************************************
 * prompts user for square
 ***********************************************************************/
string promptSquare(int rowCol[], char board[][9])
{
   string choice;
   int row, col;
   cout << "What are the coordinates of the square: ";
   cin >> choice;
   row = choice[1] - '0';
   row -= 1;
   col = choice[0] - '0';

   switch (toupper(choice[0]))
   {
      case 'A':
         col = 0;
         break;
      case 'B':
         col = 1;
         break;
      case 'C':
         col = 2;
         break;
      case 'D':
         col = 3;
         break;
      case 'E':
         col = 4;
         break;
      case 'F':
         col = 5;
         break;
      case 'G':
         col = 6;
         break;
      case 'H':
         col = 7;
         break;
      case 'I':
         col = 8;
         break;
   }

   if (board[row][col] != '0')
   {
      cout << "ERROR: Square '" << choice << "' is filled\n\n";
      return "error";
   }
   else
   {
      rowCol[0] = row;
      rowCol[1] = col;
      return choice;
   }

}

/**********************************************************************
 * shows the possible values of the squares
 ***********************************************************************/
int* getPossibles(int rowCol[], char board[][9])
{

   // initialize counts
   int rowCount = 0;
   int colCount = 0;
   int boxCount = 0;
   int rowBlockStart = 0;
   int colBlockStart = 0;

   int row = rowCol[0];
   int col = rowCol[1];
   
   // create not possible arrays
   int* rowNotPossible = createArray(9);
   int* colNotPossible = createArray(9);
   int* boxNotPossible = createArray(9);
   int* possibles = createArray(9);

   bool boxPossible;
   bool colPossible;
   bool rowPossible;

   

   // loop through row / columns
   for (int i = 0; i < 9; i++)
   {
      // check rows if not 0
      if (board[row][i] != '0')
      {
         rowNotPossible[rowCount] = board[row][i] - '0';
         // expandArray(rowNotPossible, (rowCount+1));
         rowCount++;
      }
      // check cols if not 0
      if (board[i][col] != '0')
      {
         colNotPossible[colCount] = board[i][col] - '0';
         // expandArray(colNotPossible, colCount);
         colCount++;

      }
   }

   // this is where the real magic happens…. Find out the beginning of the box
   
   switch(row % 3)
   {
      case 0:
         rowBlockStart = row;
         break;
      case 1:
         rowBlockStart = row - 1;
         break;
      case 2:
         rowBlockStart = row - 2;
         break;
   }

   switch(col % 3)
   {
      case 0:
         colBlockStart = col;
         break;
      case 1:
         colBlockStart = col - 1;
         break;
      case 2:
         colBlockStart = col - 2;
         break;
   }

   for (int i = rowBlockStart; i < (rowBlockStart + 3); i++)
   {
      for (int j = colBlockStart; j < (colBlockStart + 3); j ++)
      {
         if (board[i][j] != '0')
         {
            boxNotPossible[boxCount] = board[i][j] - '0';
            cout << "IF LOOP boxNotPossible[" << boxCount << "] = " << board[i][j] << endl;
            // expandArray(boxNotPossible, boxCount);
            boxCount++;
         }
         cout << "FOR LOOP 2 boxNotPossible[0]= " << boxNotPossible[0] << endl;
      }
      cout << "FOR LOOP 1 boxNotPossible[0]= " << boxNotPossible[0] << endl;
   }

   cout << "AFTER FOR LOOP boxNotPossible[0]= " << boxNotPossible[0] << endl;

   cout << "BOXCOUNT = " << boxCount << endl;

   int valueCount = 0;

   for (int i = 1; i <= 9; i++)
   {
      for (int j = 0; j < boxCount; j++)
      {
         boxPossible = true;
         if ( i == boxNotPossible[j] )
         {
            boxPossible = false;
            cout << "false" << endl;
         }

      }

      for (int j = 0; j < rowCount; j++)
      {
         rowPossible = true;
         if ( i == rowNotPossible[j])
         {
            rowPossible = false;
         }

      }

      for (int j = 0; j < colCount; j++)
      {
         colPossible = true;
         if ( i == colNotPossible[j])
         {
            colPossible = false;
         }

      }

      if (boxPossible && rowPossible && colPossible)
      {
         possibles[valueCount];
         // expandArray(possibles, valueCount);
         valueCount++;
      }
   }


   delete[] rowNotPossible;

   delete[] colNotPossible;

   delete[] boxNotPossible;
   //TODO: remove couts
   // cout << "Possible Values:\n";
   // for (int i = 0; i < valueCount; i++)
   // {
   //    cout << possibles[i] << endl;
   // }

   return possibles;
}

/**********************************************************************
 * createArray creates a new array and returns a pointer
 ***********************************************************************/
int* createArray(int size)
{
   int* p;
   p = new int[size+1];
   return p;
}

void expandArray(int* array, int size)
{
   // Int expandArray(*array, size)
   int* tempArray = new int[size+1];
   for (int i = 0 ; i < size; i++)
   {
      tempArray[i] = array[i];
   }

   delete[] array;
   array = NULL;
   array = tempArray;

}

/**********************************************************************
 * saveGame() calls promptFile() and saveBoard()
 ***********************************************************************/
void saveGame(char board[][9])
{
   string saveFileName = promptSaveFile();

   ofstream fout(saveFileName.c_str());


   // error check  
   if (fout.fail())
   {
      // inform user of the error
      cout << "Unable to save file " << saveFileName << endl;
   }

   // loop through everyline
   for (int row = 0; row < 9; row++)
   {
      // loop through every char
      // a++ ..... the grade I want
      for (int col = 0; col < 9; col++)
      {
         fout << board[row][col] << " " ;
      }
   }

   fout.close();
   cout << "Board written successfully\n";
}

/**********************************************************************
 * prompts the user for a save file location
 ***********************************************************************/
string promptSaveFile()
{
	string fileName;
	cout << "What file would you like to write your board to: ";
	cin >> fileName;

	return fileName;
}
