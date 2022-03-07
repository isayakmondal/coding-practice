#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string ss = "aeiou";

    ll t;
    cin >> t;
    while (t--)
    {
        vector<int> ct(5, 0);

        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {

            string s;
            cin >> s;
            for (int j = 0; j < ss.length(); j++)
            {
                ct[j] += (count(s.begin(), s.end(), ss[j])) ? 1 : 0;
            }
        }

        auto maxm = max_element(ct.begin(), ct.end());
        int ways = *maxm;
        int ctt = count(ct.begin(),ct.end(), ways);
        // ll ans = fact[*maxm]/(fact[(*maxm) - 3] * fact[3]);
        ll ans = (ways * (ways - 1) * (ways - 2)) / 6;
        cout << ans*ctt << endl;
    }

    return 0;
}