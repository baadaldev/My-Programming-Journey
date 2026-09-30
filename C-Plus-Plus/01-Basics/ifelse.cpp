#include<iostream>
using namespace std;
int main (){
    int age;
    cout<<"Enter your age: ";
    cin>>age;
    if(age>=18){
        cout<<"You are adult."<<endl;
    }
    else{
        cout<<"You are not adult."<<endl;
    }
}