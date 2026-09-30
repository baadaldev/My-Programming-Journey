#include <stdio.h>

int main() {
    int age;
    printf("Enter your age:");
    scanf("%d",&age);
    printf("You have entered %d your age\n",age);


    if (age>= 18) {
        printf("You are eligible to vote\n");
    } 
    else if (age>10){
        printf("You can vote but not eligible for certain positions\n");
    }
    else {
        printf("You are not eligible to vote\n");
    }

    return 0;
}