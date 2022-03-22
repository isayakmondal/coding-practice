#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1e4 + 10;

vector<int> g[N];
int dis[N];
bool vis[N];

void bfs(int src)
{

    queue<int> q;
    q.push(src);
    dis[src] = 0;
    vis[src] = true;
    while (!q.empty())
    {
        int cur_v = q.front();
        q.pop();

        for (auto &&child : g[cur_v])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                dis[child] = dis[cur_v] + 1;
            }
        }
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
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        int src, des;
        cin >> src >> des;
        bfs(src);
        cout << dis[des] -1 << endl;
    }

    return 0;
}