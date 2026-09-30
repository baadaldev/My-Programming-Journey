#include<stdio.h>
int main()
{
    int a;
    printf("Select any option: \n 1.Buy ticket \n 2.Show available sit \n 3.Exit\n Enter:");
    scanf("%d",&a);
    switch(a){

case 1:
    {
        printf("Types of sit available: \n 1.Front sit \n 2.Rare sit");
        break;
    }

case 2:
    {

        printf("There is no sit available");
        break ;

    }
case 3:
    {
        printf("Thank you");
        break ;
    }
default:

    printf("You have entered the wrong number");
    }


    return 0;
}
