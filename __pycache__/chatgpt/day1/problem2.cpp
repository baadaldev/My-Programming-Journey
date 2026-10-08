#include <iostream>
using namespace std;

int main() {
    int arr[] = {2, 5, 2, 7, 2, 9,10,1};
    int n = 8;

    // তোমার logic এখানে
    int count=0;
    for(int i=0; i<n; i++){
        if(arr[i] == 2){
            count++;
        }
    }
    cout<<count<<endl;

    return 0;
}