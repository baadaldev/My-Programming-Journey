#include<stdio.h>
int main(){
char str[]="My name is rakibul islam \0";
int i;
while(str[i]!='\0'){
    printf("%c",str[i]);
    i++;

}

return 0;
}





