#include<stdio.h>
int main(){
int a,b,c;
a=10;
b=20;
c=30;

if(a>b && b>c){
    printf("%d is the second highest number",b);
}
else if (c>a && a>b){
    printf("%d is the second highest number",a);

}
else if (b>c && c>a) {
    printf("%d is the second highest number",c);
}
return 0;
}

