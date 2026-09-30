#include<stdio.h>
int main(){
    int n,key,i,lastposition=-1;
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
        if(arr[i]==key){
            lastposition=i;
        }
    }
    printf("Element found at index %d", lastposition);
    if(lastposition==-1){
        printf("Element not found");
    }
    return 0;
}