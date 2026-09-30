#include<stdio.h>
int main(){
    int a,b;
    printf("Enter the numbers of rows: ");
    scanf("%d",&a);
    printf("Enter the numbers of collums: ");
    scanf("%d",&b);
    int arr[a][b];
for(int i=0;i<a;i++)
{
    for(int j=0;j<b;j++)
    {
       scanf("%d",&arr[i][j]);
    }

printf("\n");
}
    for(int i=0;i<a;i++){
    for(int j=0;j<b;j++)
    {
       printf("%d ",arr[i][j]);
}

printf("\n");
    }


return 0;

}
