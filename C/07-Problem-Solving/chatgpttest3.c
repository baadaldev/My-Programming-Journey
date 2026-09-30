#include<stdio.h>
int main(){

int n;
int i;
printf("Number of students:");
scanf("%d",&n);
int marks[n];
for(int i=0;i<n;i++){

    printf("Marks of student %d is: ",i+1);
    scanf("%d",&marks[i]);


}
   printf("\nAll marks are:\n");

    for(int i=0; i<n; i++){
        printf("%d ", marks[i]);
    }
    if(marks[i]>=80 && marks[i]<=100){

    }





return 0;
}
