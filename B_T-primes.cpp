#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll N = 1e6 + 10;

vector<bool> prime(N, 1);

bool isPrime(ll n)
{   

    return prime[n];
}

bool isPerfectSqr(ll n)
{

    if (n >= 0)
    {
        ll d = sqrt(n);
        return (d * d == n);
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    prime[0]=prime[1]=false;
    for (int i = 2; i < N; i++)
    {
        if (prime[i] == true)
        {
            for (int j = 2 * i; j < N; j += i)
            {
                prime[j] = false;
            }
        }
    }

    ll t = 1;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> vn(n);
        for (int i = 0; i < n; i++)
        {
            cin >> vn[i];
        }

        for (int i = 0; i < n; i++)
        {

            if (isPerfectSqr(vn[i]) && isPrime(floor(sqrt(vn[i]))))
            {
                cout << "YES" << endl;
            }
            else
                cout << "NO" << endl;
        }
    }

    return 0;
}