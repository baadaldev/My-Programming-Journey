#include<stdio.h>

void printNum(int n){
    if(n==10)   // Base Case
        return;
        printNum(n+1);

    printf("%d ", n);

     // Recursive Call
}

int main(){
    printNum(1);
}
