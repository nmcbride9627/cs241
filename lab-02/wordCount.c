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
  printf("%d.", nl + 1);
  while ((c = getchar()) != EOF){
    ++nc;

    if (c == ' ' || c == '\n' || c == '\t')
    {
      state = OUT;
      if (c == '\n')
      {
        ++nl;
        printf("[%d, %d]", nl, nw);
        printf("%c", c);
        printf("%d.", nl + 1);
      }
      else
      {
        printf("%c", c);
      }
    }
    else if (state == OUT)
    {
      state = IN;
      ++nw;
      printf("%c", c);
    }
    else{
      printf("%c", c);
    }
  }
  printf("%d lines, %d words, %d characters\n", nl, nw, nc);
  return 0;
}
