//Leetcode
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countPrimes(int n)
    {

        vector<bool> isPrime(n + 1, 1);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i < n; i++)
        {
            if (isPrime[i] == true)
            {
                for (int j = 2 * i; j < n; j += i)
                {

                    isPrime[j] = false;
                }
            }
        }
        int ct = count(isPrime.begin(), isPrime.end() - 1, 1);

        return ct;
    }
};