
// Extra modification for storing the connected componenets;
#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int N = 1e5;
vector<int> graph[N];
vector<bool> visited(N, 0);
vector<int> connected_ele;

void dfs(int v)
{

    visited[v] = true;
    connected_ele.push_back(v);
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

        vector<vector<int>> cc;
        int ct = 0;
        for (int i = 1; i <= n; i++)
        {
            connected_ele.clear();
            if (!visited[i])
            {
                dfs(i);
                cc.push_back(connected_ele);
                ct++;
            }
        }

        cout << cc.size() << endl;

        for (auto &&each_cc : cc)
        {
            for (auto &&each_ele : each_cc)
            {
                cout << each_ele << " ";
            }
            cout << endl;
        }
    }

    return 0;
}