#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int N = 1e5 + 10;
int h[N];
int dp[N];

int func(int n){

    // N-> N-1,N-2
    if(n==1 || n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    int cost = INT_MAX;
    cost = min(cost, func(n-1)+ abs(h[n-1]-h[n]));
    if(n>=2)
    cost = min(cost, func(n-2)+ abs(h[n-2]-h[n]));

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
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> h[i];
        }
        memset(dp,-1, sizeof(dp));
        // int cost = 0;
        // for (int i = 1; i <= n;)
        // {
        //     int d1, d2, temp;
        //     if (i + 1 <= n && i + 2 <= n)
        //     {

        //         d1 = abs(h[i] - h[i + 1]);
        //         d2 = abs(h[i] - h[i + 2]);

        //         if (d1 < d2)
        //         {

        //             cost += d1;
        //             i++;
        //         }
        //         else if(d2<d1)
        //         {

        //             cost += d2;
        //             i += 2;
        //         }
        //     }
        //     else i++;
        // }

        cout << func(n) << endl;
    }

    return 0;
}