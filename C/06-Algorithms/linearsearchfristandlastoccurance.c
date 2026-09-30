#include<stdio.h>
int main(){

int n,searchkey,i,fristposition=-1,lastposition=-1;
printf("Enter the number of elements:");
scanf("%d",&n);

int arr[n];
  printf("Enter element :");
for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
printf("Search key:");
scanf("%d",&searchkey);

for(i=0;i<n;i++){
    if(arr[i]==searchkey){
        fristposition=i;
        break;
    }
    }
    for(i=n-1;i>=0;i--){
    if(arr[i]==searchkey){
        lastposition=i;
        break;
    }


}

if(fristposition==-1){
    printf("Element not found");
} else {
    printf("First occurrence at index %d\n", fristposition);
    printf("Last occurrence at index %d\n", lastposition);
}
    return 0;
}