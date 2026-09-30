#include<iostream>
using namespace std;
int main (){
    int marks;
    cout<<"Enter your marks:"<<endl;
    cin>>marks;
    if(marks>=80){
        cout<<"You got A+"<<endl;
    }
    else if(marks>=70){
        cout<<"You got A"<<endl;
    }
    else if(marks>=60){
        cout<<"You got A-"<<endl;
    }
    else if(marks>=50){
        cout<<"You got B"<<endl;
    }
    else if(marks>=40){
        cout<<"You got C"<<endl;
    }
    else{
        cout<<"You are fail."<<endl;
    }
}