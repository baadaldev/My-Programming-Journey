#include<stdio.h>
int main(){
int arr[10];
for(int i=0;i<=9;i++){

    printf("Enter the number of the student %d:\n",i+1);
    scanf("%d",&arr[i]);


}

for(int i=1;i<=10;i++){
        if(arr[i]<35){
            printf("%d ",i);
        }

}

return 0;
}
