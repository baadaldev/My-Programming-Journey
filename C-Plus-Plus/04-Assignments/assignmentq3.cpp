#include <iostream>
using namespace std;
int main()
{
    float p, r, t;
    cout << "Enter the principal amount: ";
    cin >> p;
    cout << "Enter the rate of interest: ";
    cin >> r;
    cout << "Enter the time in years: ";
    cin >> t;
    float simple_interest = (p * r * t) / 100;
    cout << "Simple interest is: " << simple_interest << endl;

    return 0;
}