#include<iostream>
using namespace std;
void maxsubarr(int *arr,int n){
    for(int start=0;start<n;start++){
        for(int end=start;end<n;end++){
            int sum=0;
            for(int k=start;k<=end;k++){
                sum+=arr[k];
            }
            cout<<sum<<",";
        }
        cout<<endl;
    }
}
int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(int);
    maxsubarr(arr,n);
    return 0;
}