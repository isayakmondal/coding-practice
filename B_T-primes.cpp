#include <bits/stdc++.h>

using namespace std;

#define ll  long long

const ll N = 1e12 + 10;

vector<vector<int>> divisors(N);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int i = 1; i < N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            divisors[j].push_back(i);
        }
    }

    ll t = 1;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> vn(n);
        for (int i = 0; i < n; i++)
        {
            cin >> vn[i];
        }

        for (int i = 0; i < n; i++)
        {

            ll ct = divisors[vn[i]].size();

            if (ct == 3)
            {
                cout << "YES" << endl;
            }
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}