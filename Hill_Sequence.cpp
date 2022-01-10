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

    long long t;
    cin >> t;
    while (t--)
    {

        long long n, ele;
        bool isGreater = false;
        cin >> n;

        vector<long long> v;
        map<long long, long long> m;

        for (auto i = 0; i < n; i++)
        {
            cin >> ele;
            m[ele] = m[ele] + 1;
        }

        for (auto value : m)
        {
            if (value.second > 2)
            {
                isGreater = true;
                break;
            }
            v.push_back(value.first);
        }

        sort(v.begin(), v.end());

    //    long long lastElement = v[v.size() - 1];

        if (isGreater || m[v[v.size() - 1]] == 2)
        {

            cout << "-1";
        }
        else
        {

            for (auto i = 0; i < v.size(); i++)
            {
                if (m[v[i]] == 2)
                {
                    cout << v[i] << " ";
                }
            }
            for (long long j = v.size() - 1; j >= 0; j--)
            {
                cout << v[j] << " ";
            }
        }

        cout << endl;
    }
    return 0;
}