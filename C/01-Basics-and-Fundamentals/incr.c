#include<stdio.h>
int a(int n){
if (n==0)
    return 0;

return a(n-1);
printf("%d",n);


}

int main(){
int n;
printf("Enter the value:");
scanf("%d",&n);
a(n);
gets(0);

return 0;
}

