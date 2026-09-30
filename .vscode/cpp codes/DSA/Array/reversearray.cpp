#include<iostream>
using namespace std;
int main(){
    int arr[]={5,4,3,9,2};
    int n=sizeof(arr)/sizeof(int);
    for(int i=n-1;i>=0;i--){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}