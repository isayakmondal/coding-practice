#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll xor1, maxm = 0;
        for (int i = 0; i < n; i++)
        {
            xor1 = n ^ i;
            maxm = max(xor1 * i, maxm);
        }
        cout << maxm << endl;
    }

    return 0;
}