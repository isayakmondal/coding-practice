#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 2 * 1e5 + 10;
int hsh[N];
ll multiple_ct[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        hsh[x]++;
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            multiple_ct[i] += hsh[j];
        }
    }

    ll t = 1;
    cin >> t;
    while (t--)
    {
        int p, q;
        cin >> p >> q;
        ll lcm = (p * 1LL * q) / __gcd(p, q);
        ll ans = multiple_ct[p] + multiple_ct[q];
        if (lcm < N)
            ans = ans - multiple_ct[lcm];

        cout << ans << endl;
    }

    return 0;
}