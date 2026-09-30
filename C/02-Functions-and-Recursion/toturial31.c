#include<stdio.h>
void rakib(int *a,int *b){
 *a=25;
 *b=40;
}
int main()
{

    int a=10;
    int b=20;

    printf("The value of a and b is : %d %d\n",a,b);
    rakib(&a,&b);
    printf("The value of adress a and b is: %d %d",a,b);
    return 0;

}
