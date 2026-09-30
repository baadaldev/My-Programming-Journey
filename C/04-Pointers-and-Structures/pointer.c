#include<stdio.h>
int main(){
int a=45;
int* p;
p=&a;
printf("The address of the value is %d\n",a);
printf("The address of the value is %d\n",p);
printf("The address of the value is %d\n",&a);
printf("The address of the value is %d\n",*p);


return 0;
}
