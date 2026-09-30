#include<stdio.h>
int main(){

int n,searchkey,i,fristposition=-1;
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
printf("Element found at index %d",fristposition);
if(fristposition==-1){
    printf("Element not found");
}
    return 0;
}