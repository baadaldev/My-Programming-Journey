#include<stdio.h>
int main(){
    int n,key,i,count=0;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter elements:");  
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the search key:");
    scanf("%d",&key);
    for(i=0;i<n;i++){
         count++;
        if(arr[i]==key){
          
        }
    }
    printf("Element occurs %d times", count);
    return 0;
}          