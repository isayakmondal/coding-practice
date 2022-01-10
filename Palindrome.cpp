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

const int N = 1e5 + 10;
int hsh[27][N];

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
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            hsh[s[i] - 'a'][i + 1]++;
        }
        for (int i = 0; i < 26; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                hsh[i][j] += hsh[i][j - 1];
            }
        }

        while (q--)
        {
            int l, r;
            cin >> l >> r;

            int oddCount = 0;
            for (int i = 0; i < 26; i++)
            {
                int charCount = hsh[i][r]-hsh[i][l-1];
        
                if (charCount % 2 != 0)
                {
                    oddCount++;
                }
            }
            if (oddCount <= 1)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}