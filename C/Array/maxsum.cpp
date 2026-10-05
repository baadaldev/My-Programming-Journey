#include <iostream>
#include <climits>
using namespace std;

void maxsum(int *arr, int n)
{
    int currsum = 0;
    int maximum = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        currsum += arr[i];

        maximum = max(maximum, currsum);

        if(currsum < 0)
        {
            currsum = 0;
        }
    }

    cout << maximum << endl;
}

int main()
{
    int arr[6] = {-2,1,-3,4,-1,2};

    int n = sizeof(arr)/sizeof(int);

    maxsum(arr,n);

    return 0;
}