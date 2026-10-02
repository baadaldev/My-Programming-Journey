#include<iostream>
using namespace std;
int bsearch(int *arr,int n,int key){
  int mid,st=0,end=n-1;
  while(st<=end){
    mid=(st+end)/2;
    if(arr[mid]==key){
        return mid;
    }
    else if(arr[mid]<key){
        st=mid+1;
    }
    else{
        end=mid-1;
    }
  }
  return -1;
}
int main(){
    int key;
    cin>>key;
     int arr[]={2,4,6,8,10,12,14,16};
     int n=sizeof(arr)/sizeof(int);
     int result=bsearch(arr,n,key);
     if(result!=-1){
        cout<<"Element found at index "<<result<<endl;
     }
     else{
        cout<<"Element not found"<<endl;
     }

return 0;
}