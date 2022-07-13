#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    // cin >> t;
    while (t--)
    {
        int r, unit, n;
        int arr[n+10];

        cin>>r>>unit>>n;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
            
        }
        int total = r*unit;
        int ct = 0;
        for (int i = 0; i < n; i++)
        {
            sum+=arr[i];
            ct++;
            if(sum>=total) break;
        }
        if(n==0) cout<<"-1"<<endl;
        else if(ct>n) cout<<"0"<<endl;
        else cout<<ct<<endl;



    }

    return 0;
}