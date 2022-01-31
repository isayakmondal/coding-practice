#include <bits/stdc++.h>

using namespace std;

#define ll long long

// const long double PI=3.14159265358979323846264338327950;
const long double PI = acos(-1.0);

bool isVolEnough(long double volume[],int n, int f,long double mid){

    int fr=0 ;

    // if(mid==0) return false;

    for (int i = 0; i < n; i++)
    {
        fr+=(int)(volume[i]/mid);
    }

    return fr>=f;
    

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t ;
    cin >> t;
    while (t--)
    {
        int f,n;
        cin>>n>>f;
        f++;
        int arr[n];
        long double volume[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        for (int i = 0; i < n; i++)
        {
            volume[i] = arr[i]*arr[i]*PI;
        }

        long double lo = 1.0, hi = volume[n-1],mid=0.0;

        while (hi-lo>=1e-6)
        {
            mid = (hi+lo)/2;
            if(isVolEnough(volume,n,f,mid)){
                lo = mid;
            }else{
                hi = mid-1;
            }
        }

        // if(isVolEnough(volume,n,f,hi)) printf("%.4f \n",hi);
        // else printf("%.4f \n",lo);


        if(isVolEnough(volume,n,f,hi)) cout<<hi<<endl;
        else cout<<lo<<endl;
        
        
        
        

    }

    return 0;
}