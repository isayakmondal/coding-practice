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
        int a = 4, b=9;
        // a ^ a = 0, a^0 = a, a^b = b^a
        a = a^b;
        b = b^a;
        a = a^b;

        cout<<a<<" "<<b;

    }

    return 0;
}