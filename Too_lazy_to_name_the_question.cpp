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
#include <cstdlib>
#include <cassert>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int LCM(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int a, b, c;
    cin >> a >> b >> c;
    int i = 2;
    while (true)
    {
        if ((i % a == 0) || (i % b == 0))
        {
            c--;
        }
        if (c == 0)
            break;
        i++;
    }

    while (i >= 0)
    {
        cout << i << " ";
        if ((i % a == 0) && (i % b == 0))
            i = i - LCM(a, b);
        else if (i % a == 0)
            i -= a;
        else if (i % b == 0)
            i -= b;
    }

    return 0;
}