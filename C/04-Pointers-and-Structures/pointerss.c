#include<stdio.h>
int main(){

int a[]={4,3,5,6,2,6};
int *ptr= a;
int i;
for (i=0;i<=5;i++){


    printf("%d\n",*(a+i));
}




return 0;
}
