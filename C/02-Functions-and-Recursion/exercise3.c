#include<stdio.h>
int main()
{
    int num;
    printf("Enter a value:");
    scanf("%d",&num);
    printf("Multiplication of the number %d is:\n",num);
    for (int i=1; i<=10; i++)
    {
        printf("%d x %d = %d\n", num, i, num*i);
    }
    return 0;
}