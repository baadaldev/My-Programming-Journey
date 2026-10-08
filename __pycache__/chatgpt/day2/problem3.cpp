#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 5, 30, 25};
    int n = 5;
    int largest = arr[0];
    int secondLargest = arr[1];
    for(int i=0; i<n; i++){
        if(arr[i] > largest){
            secondLargest = largest;
            largest = arr[i];
        } else if(arr[i] > secondLargest && arr[i] != largest){
            secondLargest = arr[i];
        }
    }

    // তোমার variables এখানে


    // এখানে loop চালাবে


    // এখানে condition দিয়ে
    // second largest বের করবে


    // answer print করবে


    return 0;
}