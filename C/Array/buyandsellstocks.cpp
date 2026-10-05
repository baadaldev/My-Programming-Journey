#include <iostream>
#include <climits>
using namespace std;
void maxprofit(int *arr, int n)
{
  int bestbuy[100000] ;
  bestbuy[0] = INT_MAX; 
  for(int i=1;i<n;i++)
  {
    bestbuy[i] = min(bestbuy[i-1],arr[i-1]);
    cout<<bestbuy[i]<<" ";
  }
  int maxprofit = 0;
  for(int i=0;i<n;i++)
  {
    maxprofit = max(maxprofit, arr[i] - bestbuy[i]);
  }
  cout << "\n" << maxprofit << endl;
}
int main()
{
int arr[6] = {7,1,5,3,6,4};
int n=sizeof(arr)/sizeof(int);
maxprofit(arr,n);

    return 0;
}