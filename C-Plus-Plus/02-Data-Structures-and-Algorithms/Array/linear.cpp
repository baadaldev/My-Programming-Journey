#include<iostream>
using namespace std;
int main(){
    int arr[]={2,4,6,8,10,12,14,16};
    int i;
    int key;
    int count=0;
    cin>>key;
    int n=sizeof(arr)/sizeof(int);
    for(int i=0;i<n;i++){
        if(key==arr[i]){
            cout<<"key found in  "<<arr[i] <<"index"<<endl;
            count =count+1;
            return 0;

        }
    }
   
    cout<<"key is not found"<<endl;
    
    return 0;
}