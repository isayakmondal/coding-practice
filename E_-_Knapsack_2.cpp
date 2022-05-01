#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define M 1e6 + 10;

long long wt[105];
long long val[105];

long long dp[105][100005];

long long func(int indx, int val_left)
{
    if (val_left == 0)
        return 0;
    if (indx < 0)
        return 1e15;

    if(dp[indx][val_left]!=-1) return dp[indx][val_left];    
    // Do not choose element of the current index
    long long ans = func(indx - 1, val_left);

    // Choose element of the current index
    if (val_left - val[indx] >= 0) // If any value is left
        ans = min(ans, func(indx - 1, val_left - val[indx]) + wt[indx]);
    return dp[indx][val_left] = ans;
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
        for (int i = 100005; i >= 0; i--)
        {
            if (func(n - 1, i) <= w)
            {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}