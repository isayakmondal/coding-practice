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
        long long n;
        cin >> n;
        vector<long long> arr(n, 0);
        for (long long i = 0; i < n; i++){
            cin >> arr[i];
        }
        long long ans = 0;
        for (long long j = 0; j <= 61; j++)
        {
            long long one = 0;
            for (long long i = 0; i < n; i++)
                if ((1ll << j) & arr[i])
                    one++;
            if (one % 2 == 0)
                continue;
            if (j == 61)
            {
                ans = -1;
                break;
            }
            ans += (1ll << j);
            for (long long i = 0; i < n; i++)
                arr[i] += (1ll << j);
        }
        cout << ans << endl;
    }
}

