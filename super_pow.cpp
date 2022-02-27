#include<bits/stdc++.h>
using namespace std;
//Using ETF and Euler's Theorem
class Solution
{
public:
    const long long M = 1337;
    const long long m = 1140;// ETF(1337) = 1140

    long long calc_power_iter(long long a, long long b)
    {

        long long ans = 1;
        a = a % M;
        while (b > 0)
        {
            if (b & 1)
            {
                ans = (ans * a) % M;
            }
            a = (a * a) % M;
            b >>= 1;
        }

        return ans;
    }

    int superPow(int a, vector<int> &v)
    {

        long long num = 0;

        for (int val : v)
        {
            num = (num * 10 + val) % m;
        }

        return calc_power_iter((long long)a, num);
    }
};