#include <bits/stdc++.h>
using namespace std;

const long long N = 1e5 + 10;
// long long arr[N];
// long long forwrd[N];
// long long backward[N];


int main(int argc, char const *argv[])
{
    int t;
    cin >> t;

    while (t--)
    {

        int n, q;
        cin >> n >> q;
        
        int arr[n + 10];
        int forward[n + 10];
        int backward[n + 10];

        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        forward[0] = backward[n + 1] = 0;

        for (int i = 1; i <= n; i++)
        {
            forward[i] = __gcd(forward[i - 1], arr[i]);
        }

        for (int i = n; i >= 1; i--)
        {
            backward[i] = __gcd(backward[i + 1], arr[i]);
        }

        while (q--)
        {
            int l, r;
            cin >> l >> r;
            cout << __gcd(forward[l - 1], backward[r + 1]) << endl;
        
        }
    }
    return 0;
}
