#include<stdio.h>
int main(){

int i , n, fact=1;
printf("Input a number:");
scanf("%d",&n);
for(int i=1;i<=n;i++){


    fact=fact*i;

}
printf("The factorial of %d is %d",n,fact);

return 0;
}
