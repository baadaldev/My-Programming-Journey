#include <stdio.h>

int main()
{
    int n, temp, reverse = 0, digit;

    printf("Enter a number: ");
    scanf("%d", &n);

    temp = n;

    while (n > 0)
    {
        digit = n % 10;
        reverse = reverse * 10 + digit;
        n = n / 10;
    }

    printf("Reverse Number = %d\n", reverse);

    if (temp == reverse)
    {
        printf("Palindrome\n");
    }
    else
    {
        printf("Not Palindrome\n");
    }

    return 0;
}
