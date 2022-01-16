#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <ctime>
#include <cmath>
#include <stdio.h>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cassert>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        long long x,y;
        cin>>x>>y;
        if(x==0 && y==0){cout<< "NO"<<endl;}
        // long long totalX= x*1;
        // long long totalY= y*2;
        // if(((totalX+totalY)%2==0)&&(x%2==0 && y%2==0)) cout<<"YES"<<endl;
        // else cout<<"NO"<<endl;
        else if(x%2==0 && y%2==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        if(x==0 || x%2==1) cout<<"NO"<<endl;
        else cout<<"YES";

    }

    return 0;
}