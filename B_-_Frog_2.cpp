#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1e5 + 10;
int h[N];
int dp[N];
int k;

int func(int n)
{

    // N-> N-1,N-2
    if (n == 1 || n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int cost = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        if (n - i >= 1)
            cost = min(cost, func(n - i) + abs(h[n - i] - h[n]));
    }

    return dp[n] = cost;
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

        int n;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> h[i];
        }
        memset(dp, -1, sizeof(dp));
        cout << func(n) << endl;
    }

    return 0;
}