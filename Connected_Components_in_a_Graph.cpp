#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int N = 1e5;
vector<int> graph[N];
vector<bool> visited(N, 0);

void dfs(int v)
{

    visited[v] = true;
    for (auto &&child : graph[v])
    {
        if (visited[child])
            continue;

        dfs(child);
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
        int n, e;
        cin >> n >> e;
        for (int i = 0; i < e; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int ct = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                dfs(i);
                ct++;
            }
        }

        cout << ct << endl;
    }

    return 0;
}