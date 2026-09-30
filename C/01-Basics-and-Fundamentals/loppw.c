#include <stdio.h>

int main()
{
    int i;

    printf("Numbers from 1 to 50:\n\n");

    for(i = 1; i <= 50; i++)
    {
        // 7 এর গুণিতক হলে Skip করবে
        if(i % 7 == 0)
        {
            continue;
        }

        // 40 এর বেশি হলে Loop বন্ধ হবে
        if(i > 40)
        {
            break;
        }

        // Even না Odd তা বের করবে
        if(i % 2 == 0)
        {
            printf("%d is Even\n", i);
        }
        else
        {
            printf("%d is Odd\n", i);
        }
    }

    printf("\nLoop Finished.\n");

    return 0;
}