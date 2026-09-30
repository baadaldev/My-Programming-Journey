#include<stdio.h>
int main(){
int n,even,odd;
even=0;
odd=0;
printf("Enter a number:");
scanf("%d",&n);
while(n>0){
 int digit=n%10;
    if(digit%2==0)
    {
        even=even +1;
    }
    else{

        odd=odd+1;
    }
    n=n/10;



}
printf(" Total even is: %d\n",even);
printf(" Total odd is: %d",odd);


return 0;
}

