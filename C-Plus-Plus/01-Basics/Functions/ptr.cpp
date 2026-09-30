#include<iostream>
using namespace std;
void changea(int *ptr){
    *ptr=20;
    cout<<*ptr<<endl;
//pass by reference using pointer
}
int main(){
   int a=10;
   changea(&a);
    return 0;
}