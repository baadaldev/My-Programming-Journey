#include<stdio.h>
int arrsum(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        sum+=arr[i];
    }
    printf("%d",sum);
    return 0;
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    arrsum(arr,n);
    return 0;
}