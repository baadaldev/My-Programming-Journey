#include<stdio.h>
int a(int x,int n){
if (x>n)
    return 0;
printf(" %d",x);
return a(x+1,n);


}

int main(){
int n;
printf("Enter the value:");
scanf("%d",&n);
a(1,n);
gets(0);

return 0;
}
