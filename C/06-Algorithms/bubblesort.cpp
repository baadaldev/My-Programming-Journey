#include<iostream>
using namespace std;
void printArray(int arr[], int size)
{
    for (int i=0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        bool isSwap=false;
        for (int j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
                isSwap=true;
                printArray(arr, n);
        }
        if(isSwap==false)
            break;
    }
}
int main ()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(int); 
 
    bubbleSort(arr, n);
 
    return 0;
}