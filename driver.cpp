#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <ctype.h>
using namespace std;

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

   delete array;
   array = tempArray;

}

int* getPossibles(int rowCol[], char board[][9])
{

// initialize counts
   int rowCount = 0;
   int colCount = 0;
   int boxCount = 0;

   int row = rowCol[0];
   int col = rowCol[1];
// create not possible arrays
   int* rowNotPossible = createArray(9);
   int* colNotPossible = createArray(colCount);
   int* boxNotPossible = createArray(boxCount);
   int* possibles = createArray(0);

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
         // expandArray(rowNotPossible, rowCount);
         rowCount++;
      }
      // // check cols if not 0
      // if (board[i][col] != '0')
      // {
      //    colNotPossible[colCount] = board[i][col] - '0';
      //    expandArray(colNotPossible, colCount);
      //    colCount++;

      // }
   }

// // this is where the real magic happens…. Find out the beginning of the box
   // int rowBlockStart, colBlockStart;
   // switch(row % 3)
   // {
   //    case 0:
   //       rowBlockStart = row;
   //       cout << "RowBlock: " << row << endl;
   //       break;
   //    case 1:
   //       rowBlockStart = row - 1;
   //       cout << "RowBlock: " << row -1 << endl;
   //       break;
   //    case 2:
   //       rowBlockStart = row - 2;
   //       cout << "RowBlock: " << row -2 << endl;
   //       break;
   // }

   // switch(col % 3)
   // {
   //    case 0:
   //       colBlockStart = col;
   //       cout << "ColBlock: " << col << endl;
   //       break;
   //    case 1:
   //       colBlockStart = col - 1;
   //       cout << "ColBlock: " << col -1 << endl;
   //       break;
   //    case 2:
   //       colBlockStart = col - 2;
   //       cout << "ColBlock: " << col -2 << endl;
   //       break;
   // }

//    for (int i = rowBlockStart; i < rowBlockStart + 2; i++)
//    {
//       for (int j = colBlockStart; j < colBlockStart + 2; j ++)
//       {
//          if (board[i][j] != 0)
//          {
//             boxNotPossible[boxCount] = board[i][j];
//             expandArray(boxNotPossible, boxCount);
//             boxCount++;
//          }
//       }

//    }

//    int valueCount = 0;

//    for (int i = 1; i < 9; i++)
//    {
//       for (int j = 0; j < boxCount; j++)
//       {
//          boxPossible = true;
//          if ( i == boxNotPossible[j])
//          {
//             boxPossible = false;
//          }

//       }

//       for (int j = 0; j < rowCount; j++)
//       {
//          rowPossible = true;
//          if ( i == rowNotPossible[j])
//          {
//             rowPossible = false;
//          }

//       }

//       for (int j = 0; j < colCount; j++)
//       {
//          colPossible = true;
//          if ( i == colNotPossible[j])
//          {
//             colPossible = false;
//          }

//       }

//       if (boxPossible && rowPossible && colPossible)
//       {
//          possibles[valueCount];
//          expandArray(possibles, valueCount);
//          valueCount++;
//       }
//    }


   delete[] rowNotPossible;

   delete[] colNotPossible;

   delete[] boxNotPossible;

   return possibles;
}

int main ()
{

   return 0;
}