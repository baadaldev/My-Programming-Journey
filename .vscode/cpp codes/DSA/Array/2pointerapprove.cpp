#include<iostream>
using namespace std;
int main(){
    int arr[]={2,4,5,7,8,0};
    int n=sizeof(arr)/sizeof(int);
    int start=0;
    int end=n-1;
     while (start < end) {
        swap(arr[start], arr[end]);

        start++;
        end--;
     }
     for(int i=0;i<n;i++){
        cout<<arr[i]<<",";

     }
     cout<<endl;
    return 0;
}