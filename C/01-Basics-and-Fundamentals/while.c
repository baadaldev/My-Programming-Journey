#include <stdio.h>
int main()
{
    int i;
    i=0;
    while (i < 10 && i != 5 )
    {
        printf("%d\n", i);
        i++;
    }
    return 0;
}