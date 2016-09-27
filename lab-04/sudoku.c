/*********************/
/* Nathaniel McBride */
/* October 3, 2016   */
/* CS-241-002        */
/*********************/
#include <stdio.h>
#include <stdbool.h>
/* prints a formatted representation of the board */
void printBoard(int *sudokuBoard)
{
  int i;
  for(i = 0; i < 81; i++)
  {
    if((i % 3 == 0) && (i % 9 != 0))
    {
      printf("|");
    }
    if(i %9 == 0)
    {
      printf("\n");
    }
    if((i == 27) || (i==54) )
    {
      printf("------------\n");
    }
    printf("%c", sudokuBoard[i]);
  }
  printf("\n");
}
/* cans in the game board from a file
 * and does preliminary validiy checks */
int getNextBoard(int *sudokuBoard)
{
  int i = 0;
  int c = 0;
  bool hasInvalidCharacter = false;

  while((c = getchar()) != EOF)
  {
    printf("%c", c);
    if(c == '\n')
    {
      if (hasInvalidCharacter)
      {
        return 3;
      }
      else if (i < 81)
      {
        return 1;
      }
      else if (i > 81)
      {
        return 2;
      }
      else
      {
        return 0;
      }
    }
    else if(c != '.' && (c < '1' || c > '9'))
    {
      hasInvalidCharacter = true;
    }
    sudokuBoard[i] = c;
    i++;
  }
  return -1;
}
/* verifies columns by comparing every element with each other */
bool verifyCol(int *sudokuBoard, int col)
{
  int i, j;
  for(i = col; i < (9 * 7) + col; i += 9)
  {
    for(j = i + 9; j < (9 * 8) + col; j += 9)
    {
      if((sudokuBoard[i] == sudokuBoard[j]) && (i != j) && (sudokuBoard[i] != '.'))
      {
        return false;
      }
    }
  }
  return true;
}
/* verifies row by comparing every element with each other */
bool verifyRow(int *sudokuBoard, int row)
{
  int i,j;
  for(i = row * 9; i < (row * 9) + 7; i++)
  {
    for(j = i + 1 ; j < (row * 9) + 8; j++)
    {
      if((sudokuBoard[i] == sudokuBoard[j]) && (i != j) && (sudokuBoard[i] != '.'))
      {
        return false;
      }
    }
  }
  return true;
}
/* algorithm for the box checking ported from
 * www.cs.ucf.edu/~dmarino/hs/apcsa/hmk/sol/sudokode.java */
bool verifyBox(int *sudokuBoard, int row, int col)
{
  int r, c;
  bool foundNumber[10] = {0,0,0,0,0,0,0,0,0,0};

  for(r = (row/3) * 3; r < ((row/3)*3) + 3; r++)
  {
    for(c = (col/3) * 3; c < ((col/3)*3) + 3; c++)
    {
      if(foundNumber[sudokuBoard[(r*9)+c] - '0'])
      {
        return false;
      }
      if(sudokuBoard[r*9+c] != '.')
      {
        foundNumber[sudokuBoard[(r*9)+c] - '0'] = true;
      }
    }
  }
  return true;
}
/* checks the board at a given position for validity */
bool isValid(int *sudokuBoard, int postion)
{
  int row = postion / 9;
  int col = postion % 9;
  if(verifyRow(sudokuBoard, row) &&
    verifyCol(sudokuBoard, col) &&
    verifyBox(sudokuBoard, row, col))
    {
      return true;
    }
    else
    {
      return false;
    }
}
/* verfies the full board by calling
 * isValid diagonaly across the board */
bool fullIsValid(int *sudokuBoard)
{
  int i;
  for(i = 0; i < 81; i++)
  {
    if(!isValid(sudokuBoard, i))
    {
      return false;
    }
  }
  return true;
}
bool findUnassigned(int *sudokuBoard, int *postion)
{
  int i;
  for(i = 0; i < 81; i++)
  {
    if(sudokuBoard[i] == '.')
    {
      *postion = i;
      return true;
    }
  }
  return false;
}
bool solveSudoku(int *sudokuBoard)
{
  int position;
  int i;

  printBoard(sudokuBoard);
  if(!findUnassigned(sudokuBoard, &position))
  {
    return true;
  }
  for(i = 1; i <= 9; i++)
  {
    sudokuBoard[position] = i + '0';
    if(isValid(sudokuBoard, position))
    {
      if(solveSudoku(sudokuBoard))
      {
        return true;
      }
    }
    sudokuBoard[position] = '.';
  }
  return false;
}
/*TODO this program does stuff*/
int main(int argc, char const *argv[]) {
  /* Error codes:
   * -1 = EOF
   *  0 = None
   *  1 = Board too short
   *  2 = Board too long
   *  3 = Invalid character
   *  4 = Invalid board
   */
  int errorCode = 0;
  int sudokuBoard[81];
  while(errorCode != -1)
  {
    errorCode = getNextBoard(sudokuBoard);

    if(errorCode && errorCode != -1)
    {
      printf("Error\n");
    }
    else if(!fullIsValid(sudokuBoard))
    {
      printf("Error\n");
    }
    else if(!solveSudoku(sudokuBoard))
    {
      printf("No solution\n");
    }
    printBoard(sudokuBoard);

      /*TODO*/
      /*solve board*/
      /*print solution*/
      /*if no soulution print no solution*/
    printf("\n");
  }
  return 0;
}
