#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll M = 1e9 + 7;

// Recursion using binary exponentiation
ll calc_power_rec(int a, int b)
{

    if (b == 0)
        return 1;
    ll res = calc_power_rec(a, b / 2);

    if (b % 2 == 0)
    {
        return (res * res) % M;
    }
    else
    {
        return (a * calc_power_rec(a, b - 1)) % M;
    }
}

// Iterative using binary exponentiation
ll calc_power_iter(ll a, ll b)
{

    ll ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans * a) % M;
        }
        a *= a % M;
        b >>= 1;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    // cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        cout << calc_power_iter(a, b) << endl;
    }

    return 0;
}