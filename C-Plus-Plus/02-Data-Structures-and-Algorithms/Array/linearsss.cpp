#include<iostream>
using namespace std;
int linearsearch(int *arr,int n,int key){
    int i;
    for(i=0;i<n;i++){
    if(arr[i]==key){
        return i;
    }
   
}
 return -1;
}
int main(){
    int n;
    cout<<"Enter the size of array"<<endl;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cout<<"Enter the key to be searched"<<endl;
    cin>>key;
    int result = linearsearch(arr, n, key);
    if(result != -1){
        cout<<"Element found at index "<<result<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }
    return 0;

}