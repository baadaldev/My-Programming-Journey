#include<stdio.h>
struct student
{
    int id;
    float cgpa;
};

int main(){
struct student s1;
s1.id= 1;
s1.cgpa=3.50;

printf("Student 1 id is %d\n",s1.id);
printf("Student 1 cgpa is %.2f\n",s1.cgpa);


return 0;


}
