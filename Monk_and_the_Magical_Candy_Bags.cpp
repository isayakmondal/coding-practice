#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        multiset<long long> bag;
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            long long ele;
            cin >> ele;
            bag.insert(ele);
        }

        long long s = 0;
        while (k--)
        {
            auto it = bag.end();
            it--;

            s += (*it);
            long long temp = (*it) / 2;
            if (it != bag.end())
                bag.erase(it);
            bag.insert(temp);
        }
        cout << s << endl;
    }
}