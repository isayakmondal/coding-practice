#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool canPlaceCows(ll stall[], ll n, ll c, ll md)
{

    ll lastPos = -1;
    for (ll i = 0; i < n; i++)
    {

        if (stall[i] - lastPos >= md || lastPos == -1)
        {
            c--;
            lastPos = stall[i];
        }

        if (c == 0)
            break;
    }

    return c == 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, c;
        cin >> n >> c;
        ll stall[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> stall[i];
        }

        sort(stall, stall + n);

        ll low = 0, high = 1e9, mid;

        while (high - low > 1)
        {
            mid = (high + low) / 2;

            if (canPlaceCows(stall, n, c, mid))
            {

                low = mid;
            }
            else
            {

                high = mid - 1;
            }
        }

        if (canPlaceCows(stall, n, c, high))
            cout << high << endl;
        else
            cout << low << endl;
    }

    return 0;
}