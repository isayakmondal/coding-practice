#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 2e3 + 10;

int size[N], parent[N];

void make_set(int x)
{

    parent[x] = x;
    size[x] = 1;
}

int find_set(int x)
{

    if (parent[x] == x)
        return x;
    return (parent[x] = find_set(parent[x]));
}

void union_set(int a, int b)
{

    a = find_set(a);
    b = find_set(b);

    if (a != b)
    {

        if (size[b] > size[a])
            swap(a, b);
        parent[b] = a;
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
        int n;
        cin >> n;
        vector<pair<int, int>> cities(n + 1);
        vector<int> c(n + 1);
        vector<int> k(n + 1);

        for (int i = 1; i <= n; i++)
        {
            int x, y;
            cin >> x >> y;
            cities[i].first = x;
            cities[i].second = y;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> c[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> k[i];
        }

        vector<pair<long long, pair<int, int>>> mst;

        for (int i = 1; i <= n; i++)
        {
            mst.push_back({c[i], {0, i}});
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                int dist = abs(cities[i].first - cities[j].first) + abs(cities[i].second - cities[j].second);
                long long wt = dist * 1LL * (k[i] + k[j]);
                mst.push_back({wt, {i, j}});
            }
        }
        for (int i = 0; i <= n; i++)
        {
            make_set(i);
        }

        vector<int> city;
        vector<pair<int, int>> connections;
        sort(mst.begin(), mst.end());
        long long total_cost = 0;
        for (auto &&edge : mst)
        {
            int wt = edge.first;
            int u = edge.second.first;
            int v = edge.second.second;
            if (find_set(u) == find_set(v))
                continue;
            union_set(u, v);
            total_cost += wt;
            if (u == 0 || v == 0)
            {

                city.push_back(max(u, v));
            }
            else
            {
                connections.push_back({u, v});
            }
        }
        cout << total_cost << endl;
        cout << city.size() << endl;

        for (auto &&e : city)
        {
            cout << e << " ";
        }
        cout << endl
             << connections.size() << endl;
        for (auto &&e : connections)
        {
            cout << e.first << " " << e.second << endl;
        }
    }

    return 0;
}