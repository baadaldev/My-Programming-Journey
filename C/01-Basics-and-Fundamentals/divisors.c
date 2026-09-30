#include<stdio.h>
int main()
{
int digit,sum=0,original;
printf("Enter a digit:");
scanf("%d",&digit);
 original=digit;

for(int i=1;i<digit;i++)
{

  if(digit%i==0)
  {
    sum=sum+i;
  }
  
}
    if(sum==original)
    {
    printf("%d is a perfect number\n",original);
    }
  else if(sum!=original)
   {
    printf("%d is not a perfect number\n",original);
  }
     


    return 0;
}