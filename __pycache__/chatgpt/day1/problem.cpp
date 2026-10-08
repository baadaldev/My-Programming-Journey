#include <iostream>
using namespace std;

int main() {
    int arr[] = {4, 7, 2, 9, 5};
    int n = 5;

    // তোমার logic এখানে লিখবে
    int max=arr[0];
    for(int i=1; i<n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    cout << "Maximum element is: " << max << endl;

    return 0;
}