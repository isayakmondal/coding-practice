#include <bits/stdc++.h>

using namespace std;
const long long H = 1e6 + 10;
long long heights[H];

bool isSufficeintHeight(long long h, long long n, long long m)
{

    long long woods = 0;
    for (long long i = 0; i < n; i++)
    {
        if (heights[i] >= h)
        {
            woods += heights[i] - h;
        }
    }

    return woods >= m;
}

int main(int argc, char const *argv[])
{
    long long n, m;
    cin >> n >> m;

    for (long long i = 0; i < n; i++)
    {
        cin >> heights[i];
    }

    long long low = 0, hi = 1e9, mid;

    while (hi - low > 1)
    {
        mid = (hi + low) / 2;

        if (isSufficeintHeight(mid, n, m))
        {
            low = mid;
        }
        else
        {

            hi = mid - 1;
        }
    }

    if(isSufficeintHeight(hi,n,m))
    cout << hi << endl;
    else cout<<low<<endl;

    return 0;
}
