#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll M = 1e9 + 7;
const ll N = 1e5 + 10;
ll fact[N];

long long calc_power_iter(long long a, long long b)
{

    long long ans = 1;
    a = a % M;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans * a) % M;
        }
        a = (a * a) % M;
        b >>= 1;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fact[0] = 1;
    for (ll i = 1; i < N; i++)
    {
        fact[i] = (fact[i - 1] * i) % M;
    }

    ll t = 1;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        // kCn--> k!/((k-n)! n!)

        ll ans = fact[k];
        ll deno = fact[k - n];
        ans = (ans * calc_power_iter(deno, M - 2)) % M;
        cout << ans << endl;
    }

    return 0;
}