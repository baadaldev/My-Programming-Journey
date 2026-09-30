#include<iostream>
using namespace std;
int main (){
    int arr[5];
    int n;
    cout<<"enter the length of array:";
    cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
      for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
      }

    return 0;
}