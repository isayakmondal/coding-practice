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
        string str1,str2;
        long long c=0;
        for(int i=0;i<str1.length();i++){

            if(str1==str2) c++;
            else if(str1[i]=='?') c++;
            else if(str2[i]=='?') c++;

        }
        if(c==str1.length()) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;

    }

    return 0;
}