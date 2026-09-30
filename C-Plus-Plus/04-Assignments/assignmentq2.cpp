#include<iostream>
using namespace std;
int main (){
float pencil,pen,eraser;
cout<<"Enter the price of pencil: ";
cin>>pencil;
cout<<"Enter the price of pen: ";
cin>>pen;
cout<<"Enter the price of eraser";
cin>>eraser;
float total_cost=18*(pencil+pen+eraser)/100+(pencil+pen+eraser);
cout<<"Total bill is :"<<total_cost<<endl;
    
    return 0;
}