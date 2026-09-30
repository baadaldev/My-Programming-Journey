#include<stdio.h>
#include<string.h>
int main(){
char str[30];//="My name is rakibul islam";
//printf("%s",str);
//puts(str);
scanf("%[^\n]s",str);
printf("Your input is : %s",str);
//gets(str);
return 0;
}
