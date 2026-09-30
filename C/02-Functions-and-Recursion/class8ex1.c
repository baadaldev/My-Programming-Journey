#include <stdio.h>

int main ()
{
int a;
printf("Enter a number:");
scanf("%d",&a);

printf("Table of %d:\n", a);
printf(" %d x 1 = %d\n", a, a * 1);
printf(" %d x 2 = %d\n", a, a * 2);
printf(" %d x 3 = %d\n", a, a * 3);
printf(" %d x 4 = %d\n", a, a * 4);
printf(" %d x 5 = %d\n", a, a * 5);
printf(" %d x 6 = %d\n", a, a * 6);
printf(" %d x 7 = %d\n", a, a * 7);
printf(" %d x 8 = %d\n", a, a * 8);
printf(" %d x 9 = %d\n", a, a * 9);
printf(" %d x 10 = %d\n", a, a * 10);

    return 0;

}