#include <stdio.h>

int main()
{
    int age;

    printf("Enter your age: ");
    scanf("%d", &age);

    switch (age)
    {
        case 2:
            printf("You are 2\n");
            break;

        case 19:
            printf("You are 19\n");
            break;

        default:
            printf("You are not 2 or 19\n");
            break;
    }

    return 0;
}