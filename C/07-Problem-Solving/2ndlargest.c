#include<stdio.h>
int main()
{
    int arr[10]={5,9,12,7,15,10,3,8,14,11};
   int  largest=arr[0];
   int secondlargest=arr[0];


    for(int i=0;i<10;i++){

        if(arr[i] > largest)
{
    secondlargest = largest;
    largest = arr[i];
}
else if  (arr[i] > secondlargest){

    secondlargest=arr[i];
}
    }

 printf(" Second largest number is: %d",secondlargest);


    return 0;
}
