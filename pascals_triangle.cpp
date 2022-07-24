// O(1) extra space O(n^2) time complexity
#include <iostream>

using namespace std;

int main()
{

    int n = 5;
    for (int i = 1; i <= n; i++)
    {

        for (int k = n - 1; k >= i; k--)
        {
            cout << " ";
        }

        int coef = 1;

        for (int j = 1; j <= i; j++)
        {

            cout << coef << " ";

            coef = coef * (i - j) / j;
        }

        cout << endl;
    }

    return 0;
}