#include <bits/stdc++.h>

using namespace std;

#define ll long long

int wt[105];
long long val[105];

long long dp[105][100005];

long long func(int indx, int wt_left)
{

    if (wt_left == 0)
        return 0;
    if (indx < 0)
        return 0;
    if (dp[indx][wt_left] != -1)
        return dp[indx][wt_left];
    long long ans = func(indx - 1, wt_left);
    if (wt_left - wt[indx] >= 0)
        ans = max(ans, func(indx - 1, wt_left - wt[indx]) + val[indx]);
    return dp[indx][wt_left] = ans;
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
        int n, w;
        cin >> n >> w;
        for (int i = 0; i < n; i++)
        {
            cin >> wt[i] >> val[i];
        }
        memset(dp, -1, sizeof(dp));
        cout << func(n - 1, w) << endl;
    }

    return 0;
}