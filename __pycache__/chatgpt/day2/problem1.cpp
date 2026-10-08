#include <iostream>
using namespace std;

int main() {
    int arr[] = {2, 5, 3, 7, 4};
    int n = 5;

    // তোমার code
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    cout<<sum<<endl;
    return 0;
}