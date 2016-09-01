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
  int c, nl, nw, nc, state;

  state = OUT;
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF){
    printf("%d.", nl + 1);
    ++nc;
    if (c == '\n')
    {
      ++nl;
      printf("[%d, %d]\n", nl, nw);
    }
    if (c == ' ' || c == '\n' || c == '\t')
    {
      state = OUT;
      printf("%c", c);
    }
    else if (state == OUT)
    {
      state = IN;
      ++nw;
    }
    else
    {
      printf("%c", c);
    }
  }
  printf("%d lines, %d words, %d characters\n", nl, nw, nc);
  return 0;
}
