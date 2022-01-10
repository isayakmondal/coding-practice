#include <bits/stdc++.h>
using namespace std;

int main()
{

    int withdraw;
    float balance;
    float trans_amt = 0.50;

    cin >> withdraw >> balance;

    if (withdraw % 5 != 0 || withdraw + trans_amt > balance)
    {
        printf("%0.2f \n", balance);
    }
    else
    {
        printf("%0.2f \n", balance - withdraw - trans_amt);
    }
}