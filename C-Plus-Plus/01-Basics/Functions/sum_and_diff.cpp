#include<iostream>
using namespace std;
int sum(int a ,int b)
{
    int sum=a+b;
    return sum;
}
int diff(int a , int b){
    int diff=a-b;
    return diff;
}
int main (){
   
    int a=sum(10,20);
    int b=diff(20,30);
    cout<<a<<endl;
    cout<<b<<endl;

    return 0;
}