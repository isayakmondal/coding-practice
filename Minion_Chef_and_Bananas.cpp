#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool isKEnough(vector<ll> arr, ll n, ll h, ll k)
{

    ll s = 0;
    // vector<ll> arr(n);
    // copy(a.begin(),a.end(),arr.begin());
   
    for (ll i = 0; i < n; i++)
    {

        if (h == 0)
            break;

        if (arr[i] == k)
        {
            arr[i] = 0;
        }
        else if (arr[i] > k)
        {
            s = arr[i] - k;
            arr[i] = s;
            --i;
        }
        else
        {

            arr[i] = 0;
        }
        h--;
    }
    // cout << accumulate(arr, arr + n, 0) << endl;
    return accumulate(arr.begin(), arr.end(), 0) == 0;
}



// bool isKEnough(vector<ll> arr, ll n, ll h, ll k)
// {

//     ll time = 0;
   
//     for (ll i = 0; i < n; i++)
//     {
//         ll x,y;
//         x = arr[i]/k;
//         y = arr[i]%k;

//         if(y) x++;
         
//         time+=x; 
//     }
   
//     return time<=h;
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, h;
        cin >> n >> h;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(a.begin(),a.end());
        ll lo = 1, hi = a[n-1], mid;
        //  cout << accumulate(a, a + n, 0) << endl;
        // cout<<isKEnough(a, n, h, 4)<<endl;
        ll ans=-1;
        while (hi-lo>=1)
        {
            mid = (hi + lo) / 2;
            if (isKEnough(a, n, h, mid))
            {   
                
                hi = mid;
                
            }
            else
            {
                lo = mid + 1;
            }
        }
        if (isKEnough(a, n, h, lo))
            cout<<lo<<endl;
        else cout<<hi<<endl;    
    }

    return 0;
}