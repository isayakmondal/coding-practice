#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1e5 + 10;
int parent[N];
int size[N];
multiset<int> m;

void make_set(int v)
{
    parent[v] = v;
    size[v] = 1;
    m.insert(size[v]);
}

int find(int v)
{

    if (parent[v] == v)
        return v;
    return (parent[v] = find(parent[v]));
}

void addSize(int a, int b)
{

    m.erase(m.find(size[a]));
    m.erase(m.find(size[b]));

    m.insert(size[a] + size[b]);
}

void union_set(int a, int b)
{

    a = find(a);
    b = find(b);

    if (a != b)
    {

        if (size[b] > size[a])
            swap(a, b);
        parent[b] = a;
        addSize(a, b);
        size[a] += size[b];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    // cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        for (int i = 1; i <= n; i++)
        {
            make_set(i);
        }
        while (q--)
        {
            int a, b;
            cin >> a >> b;
            union_set(a, b);

            if (m.size() == 1)
            {
                cout << 0 << endl;
            }
            else
            {
                int mn = *m.begin();
                int mx = *(--m.end());

                cout << mx - mn << endl;
            }
        }
    }

    return 0;
}