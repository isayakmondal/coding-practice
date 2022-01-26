#include<bits/stdc++.h>

using namespace std;

const double eps = 1e-6;

double nthProduct(double mid,int n){

    for (int i = 0; i < n; i++)
    {
        mid*=mid;
    }
    
    return mid;
}

int main(int argc, char const *argv[])
{
    double x;
    int n;
    cin>>x>>n;

    double low = 1, high = x,mid;

    while(high-low>eps){

        mid = (high+low)/2;
        if(nthProduct(mid,n)>x){
            high = mid;
        }
        else{
            low = mid;
        }
    }

    cout<<high<<endl;
    return 0;
}
