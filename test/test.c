#include <stdio.h>

void  main(void)

{
long a[] = {7, 13, 17};

long *x = a;

printf("sizeof(long )=%lu ", sizeof(long ));

printf("x=%p, x[0]=%ld\n", x, x[0]);

x = x + 2;

printf("x=%p, x[0]=%ld\n", x, x[0]);

}
