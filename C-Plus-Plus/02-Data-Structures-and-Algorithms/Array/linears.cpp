#include<iostream>
using namespace std;
int linearsearch(int *arr,int n,int key){
    int i;
    for(i=0;i<n;i++){
    if(arr[i]==key){
        return i;
    }
    
}
 cout<<"Element not found"<<endl;
 return -1;
}
int main(){
   
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(int);
    cout<<linearsearch(arr,n,3)<<endl;
    return 0;
} 