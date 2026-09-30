#include<iostream>
using namespace std;
int main(){
    int arr[5]={1,4,3,4,5};
    int max=arr[0];
    for(int i=0;i<5;i++){
        if(arr[i]>max){
           max=arr[i]; 
        }
    }
    cout<<max<<endl;

    return 0;
}