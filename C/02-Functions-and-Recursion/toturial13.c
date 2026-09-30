#include<stdio.h>
int main(){

int num;
int index;
index = 0;
printf("Enter a number: ");
scanf("%d", &num);
do{
printf("%d\n", index+1);
index=index+1;
}while(index<num);
printf("goodbye");

    return 0;
}