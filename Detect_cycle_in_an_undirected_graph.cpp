
// Extra modification for storing the connected componenets;
#include <bits/stdc++.h>

using namespace std;

#define ll long long
const static int N = 1e5;
vector<int> graph[N];
bool visited[N];

bool dfs(int V, int parent)
{

    visited[V] = true;
    bool isLoopExists = false;
    for (auto &&child : graph[V])
    {
        if (visited[child] && child != parent)
            return true;
        if (visited[child])
            continue;
        isLoopExists |= dfs(child, V);
    }
    return isLoopExists;
}

bool isCycle(int V)
{
    // Code here

    bool isLoopExists = false;
    for (int i = 0; i <= V; i++)
    {
        if (visited[i])
            continue;
        if (dfs(i, -1))
        {
            isLoopExists = true;
            break;
        }
    }
    return isLoopExists;
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

        // vector<vector<int>> cc;
        cout << isCycle(n) << endl;

        // cout << cc.size() << endl;

        //     for (auto &&each_cc : cc)
        //     {
        //         for (auto &&each_ele : each_cc)
        //         {
        //             cout << each_ele << " ";
        //         }
        //         cout << endl;
        //     }
    }

    return 0;
}