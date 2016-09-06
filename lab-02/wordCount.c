/*********************/
/* Nathaniel McBride */
/* September 9, 2016 */
/* CS-241-002        */
/*********************/

#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

/* count lines, words, and characters in input */
int main()
{
  int c, totalLines, totalWords, totalChars, state;
  int currentLineWC, currentLineCC;

  state = OUT;
  totalLines = totalWords = totalChars = 0;
  currentLineWC = currentLineCC = 0;
  printf("%d.", totalLines + 1);
  while ((c = getchar()) != EOF){
    currentLineCC++;
    if (c == ' ' || c == '\n' || c == '\t') //Check for spaces, newlines, and tabs
    {
      state = OUT;
      if (c == '\n') //Singles out newlines
      {
        ++totalLines;
        printf("[%d, %d]", currentLineWC, currentLineCC);
        printf("%c", c); //echos newline characters
        printf("%d.", totalLines + 1); //Print the line number for the next line
        totalChars += currentLineCC;
        totalWords += currentLineWC;
        currentLineWC = currentLineCC = 0;
      }
      else
      {
        printf("%c", c); //echos spaces and tabs
      }
    }
    else if (state == OUT)
    {
      state = IN;
      ++currentLineWC;
      printf("%c", c); //Prints the first letter coming into a word

    }
    else{
      printf("%c", c); //echos everything but spaces, tabs, and new lines
    }
  }
  printf("%d lines, %d words, %d characters\n", totalLines, totalWords, totalChars);
  return 0;
}
