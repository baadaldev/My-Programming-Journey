#include<stdio.h>
int main()
{
    int i,sum=0,f;
    f=0;
    for(i=0;i<=100 ;f++){
      printf("%d %d\n",i,f);
      sum=sum+i+f;
      i=i+5;

    }

  printf("\nSum=%d",sum);

}
