#include <iostream>
using namespace std;

int main() {
    int arr[] = {2, 7, 4, 9, 6};
    int n = 5;
    int even = 0;
    int odd = 0;

    // Step 1: দুইটা variable নাও


    // Step 2: পুরো array-তে loop চালাও
    for(int i = 0; i < n; i++){
        if(arr[i] % 2 == 0){
            // even number
            even ++;
        } else {
            // odd number
            odd ++;
        }
       


        // Step 3: even নাকি odd check করো


        // Step 4: সেই অনুযায়ী count update করো

    }
     cout << "Even count: " << even << ", Odd count: " << odd << endl;

    // Step 5: even এবং odd count print করো


    return 0;
}