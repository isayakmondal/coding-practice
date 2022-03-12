#include <bits/stdc++.h>

using namespace std;

#define ll long long
int const N = 1e5;
vector<int> tree[N];
int depth[N];
int height[N];

void dfs(int v, int par)
{

    for (auto &&child : tree[v])
    {
        if (child == par)
            continue;
        depth[child] = depth[v] + 1;
        dfs(child, v);
        height[v] = max(height[v], height[child] + 1);
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
        int e = n - 1;
        for (int i = 0; i < e; i++)
        {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        dfs(1, 0);
        for (int i = 1; i <= n; i++)
        {
            cout << i << " -> " << depth[i] << " " << height[i] << endl;
        }
    }

    return 0;
}