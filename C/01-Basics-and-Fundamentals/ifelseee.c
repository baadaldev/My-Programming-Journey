#include<stdio.h>
int main()
{
    int a;
    printf("Enter a number:");
    scanf("%d",&a);
    if(a%2==0)
    {
        printf("%d is Even",a);
    }
    else
    {
        printf("%d is Odd",a);
    }
    return 0;
}