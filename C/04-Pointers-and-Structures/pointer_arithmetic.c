#include<stdio.h>
int main(){

int myNumbers[5] = {10, 20, 30, 40, 50};
int *start = myNumbers; // points to 20
int *end = myNumbers;   // points to 50

printf("%ld\n", end - start); // 3 elements apart



return 0;
}




