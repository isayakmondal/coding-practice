#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define INF 1e9 + 10;
const int N = 1e5;
vector<pair<int, int>> g[N];
unordered_map<string, int> mp;
int dist[N];
bool vis[N];

void dijkstra(int src)
{

    multiset<pair<int, int>> m;
    m.insert({0, src});
    dist[src] = 0;

    while (m.size() > 0)
    {
        auto it = m.begin();
        int wt = it->first;
        int v = it->second;
        m.erase(it);
        if (vis[v])
            continue;
        vis[v] = true;

        for (auto &&child : g[v])
        {
            int child_v = child.first;
            int child_wt = child.second;

            if (dist[v] + child_wt < dist[child_v])
            {
                dist[child_v] = wt + child_wt;
                m.insert({dist[child_v], child_v});
            }
        }
    }
}

void reset()
{

    for (int i = 0; i < N; i++)
    {
        dist[i] = INF;
        vis[i] = false;
        mp.clear();
        g->clear();
    }
}
void reset2()
{

    for (int i = 0; i < N; i++)
    {
        dist[i] = INF;
        vis[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;
    while (t--)
    {
        reset();
        int n, i = 1;
        cin >> n;
        while (n--)
        {
            string name;
            cin >> name;
            mp.insert({name, i});
            int p;
            cin >> p;
            while (p--)
            {
                int v, w;
                cin >> v >> w;
                g[i].push_back({v, w});
            }
            i++;
        }
        int ct;
        cin >> ct;
        while (ct--)
        {
            string src_name, dest_name;
            cin >> src_name >> dest_name;
            int src = mp[src_name];
            int dest = mp[dest_name];
            reset2();
            dijkstra(src);

            cout << dist[dest] << endl;
        }
    }

    return 0;
}