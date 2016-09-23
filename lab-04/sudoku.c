/*********************/
/* Nathaniel McBride */
/* October 3, 2016   */
/* CS-241-002        */
/*********************/
#include <stdio.h>
#include <stdbool.h>

void printBoard(char *sudokuBoard)
{
  int i;
  for(i = 0; i < 81; i++)
  {
    if(i % 9 == 0)
    {
      printf("\n");
    }
    printf("%c", sudokuBoard[i]);
  }
  printf("\n");
}

int getNextBoard(char *sudokuBoard)
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
bool isValid(char *sudokuBoard, int postion)
{
  int row = postion / 9;
  int col = postion % 9;
  int i,j;
  for(i = row * 9; i < (row * 9) + 7; i++)
  {
    for(j = i + 1 ; j < (row * 9) + 8; j++)
    {
      if((sudokuBoard[i] == sudokuBoard[j]) && (i != j) && (sudokuBoard[i] != '.'))
      {
        printf("found duplicate in row\n");
        printBoard(sudokuBoard);
        return false;
      }
    }
  }
  for(i = col; i < (9 * 7) + col; i += 9)
  {
    for(j = i + 9; j < (9 * 8) + col; j += 9)
    {
      if((sudokuBoard[i] == sudokuBoard[j]) && (i != j) && (sudokuBoard[i] != '.'))
      {
        printf("found duplicate in col\n");
        printBoard(sudokuBoard);
        return false;
      }
    }
  }
  printf("no dupes\n");
  return true;
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
  char sudokuBoard[81];
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
      isValid(sudokuBoard, 9);
      isValid(sudokuBoard, 18);
      isValid(sudokuBoard, 27);
      isValid(sudokuBoard, 36);
      isValid(sudokuBoard, 45);
      isValid(sudokuBoard, 54);
      isValid(sudokuBoard, 63);
      isValid(sudokuBoard, 72);

      isValid(sudokuBoard, 1);
      isValid(sudokuBoard, 2);
      isValid(sudokuBoard, 3);
      isValid(sudokuBoard, 4);
      isValid(sudokuBoard, 5);
      isValid(sudokuBoard, 6);
      isValid(sudokuBoard, 7);
      isValid(sudokuBoard, 8);
      /*solve board*/
      /*print solution*/
      /*if no soulution print no solution*/

    }
    printf("\n");
  }
  return 0;
}
