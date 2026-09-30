#include<iostream>
using namespace std;
int main (){
int n=10829;
int sum=0;
int digit;
while(n!=0){
    digit=n%10;
    sum=sum+digit;
    n=n/10;
}
cout<<sum<<endl;
    return 0;
}