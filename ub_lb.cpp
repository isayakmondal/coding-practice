#include<bits/stdc++.h>

using namespace std;


int lowerBound(vector<int> &v, int ele){

    int low = 0;
    int n;
    int high = v.size()-1;
    n=high;

    while (high>=low)
    {       
        int mid = (high+low)/2;

        if(ele==v[mid]) return mid;
        else if(ele>v[mid]){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }

    if(low<=n && v[low]>ele) return low;
    // if(high<=n && v[high]>ele) return high;

    return -1;

}


int main(int argc, char const *argv[])
{
    vector<int> v={2,4,5,7,9,11,12};
    int lb= lowerBound(v,11);
    // cout<<(lb<v.size()-1?lb:-1)<<endl;
    cout<<lb<<endl;

    return 0;
}
