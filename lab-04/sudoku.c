/*********************/
/* Nathaniel McBride */
/* October 3, 2016   */
/* CS-241-002        */
/*********************/
#include <stdio.h>
#include <stdbool.h>

void printBoard(int *sudokuBoard)
{
  int i;
  for(i = 0; i < 81; i++)
  {
    if((i % 3 == 0) && (i != 0))
    {
      printf("|");
    }
    if(i %9 == 0)
    {
      printf("\n");
    }
    if((i == 27) || (i==45) )
    {
      printf("------------\n");
    }
    printf("%c", sudokuBoard[i]);
  }
  printf("\n");
}

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

bool verifyCol(int *sudokuBoard, int col)
{
  int i, j;
  for(i = col; i < (9 * 7) + col; i += 9)
  {
    for(j = i + 9; j < (9 * 8) + col; j += 9)
    {
      if((sudokuBoard[i] == sudokuBoard[j]) && (i != j) && (sudokuBoard[i] != '.'))
      {
        printf("col not valid\n");
        return false;
      }
    }
  }
  return true;
}

bool verifyRow(int *sudokuBoard, int row)
{
  int i,j;
  for(i = row * 9; i < (row * 9) + 7; i++)
  {
    for(j = i + 1 ; j < (row * 9) + 8; j++)
    {
      if((sudokuBoard[i] == sudokuBoard[j]) && (i != j) && (sudokuBoard[i] != '.'))
      {
        printf("row not valid\n");
        return false;
      }
    }
  }
  return true;
}

bool verifyBox(int *sudokuBoard, int row, int col)
{
  int r, c;
  bool foundNumber[10];

  for(r = (row/3) * 3; r < ((row/3)*3) + 3; r++)
  {
    for(c = (col/3) * 3; c < ((row/3)*3) + 3; c++)
    {
      if(foundNumber[sudokuBoard[r*9+c]])
      {
        printf("box not valid\n");
        return false;
      }
      if(sudokuBoard[r*9+c] != '.')
      {
        foundNumber[sudokuBoard[r*9+c]] = true;
      }
    }
  }
  return true;
}
bool fullIsValid(int *sudokuBoard)
{
  int row = 0;
  int col = 0;

  for(row = 0; row < 9; row++)
  {
    if(!verifyRow(sudokuBoard, row))
    {
      return false;
    }
  }
  for(col = 0; col < 9; col ++)
  {
    if(!verifyCol(sudokuBoard, col))
    {
      return false;
    }
  }
  for(row = 0; row < 9; row += 3)
  {
    for(col = 0; col < 9; col += 3)
    {
      if(!verifyBox(sudokuBoard, row, col))
      {
        return false;
      }
    }
  }
  return true;
}

bool isValid(int *sudokuBoard, int postion)
{
  int row = postion / 9;
  int col = postion % 9;
  if(verifyRow(sudokuBoard, row) &&
    verifyCol(sudokuBoard, col) &&
    verifyBox(sudokuBoard, row, col))
    {
      printf("valid\n");
      return true;
    }
    else
    {
      printf("not valid\n");
      printBoard(sudokuBoard);
      return false;
    }
}

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
    else
    {
      isValid(sudokuBoard, 0);
      /*solve board*/
      /*print solution*/
      /*if no soulution print no solution*/

    }
    printf("\n");
  }
  return 0;
}
