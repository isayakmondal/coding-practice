#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll M = 1e9 +7;

ll calc_power(int a, int b){

    if(b==0) return 1;
    ll res = calc_power(a,b/2);
    
    if(b%2==0){
        return (res*res)%M;
    }
    else{
        return (a * calc_power(a,b-1))%M;
    }
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
        int a,b;
        cin>>a>>b;
        cout<<calc_power(a,b)%M<<endl;

    }

    return 0;
}