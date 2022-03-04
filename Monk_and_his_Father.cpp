#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t ;
    cin >> t;
    while (t--)
    {
        ll p;
        cin>>p;
        cout<<__builtin_popcountll(p)<<endl;

    }

    return 0;
}