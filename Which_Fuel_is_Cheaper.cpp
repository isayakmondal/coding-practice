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
        int x,y,a,b,k;
        cin>>x>>y>>a>>b>>k;
        while(k--){
            x+=a;
            y+=b;
        }

        if(x==y)cout<<"SAME PRICE"<<endl;
        else if(x<y)cout<<"PETROL"<<endl;
        else cout<<"DIESEL"<<endl;

    }

    return 0;
}