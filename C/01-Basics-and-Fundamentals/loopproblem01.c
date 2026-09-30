#include<stdio.h>
int main()
{
int digit;
int fact=1;
printf("Enter a digit:");
scanf("%d",&digit);

for(int i=1;i<=digit;i++)
{

   fact=fact*i;
   printf("%d\n",fact);
}



    return 0;
}