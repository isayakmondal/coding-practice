#include <bits/stdc++.h>

using namespace std;

#define ll long long

int const N = 1e5;
vector<int> tree[N];
int depth[N];

void dfs(int v, int par)
{

    for (auto &&child : tree[v])
    {
        if (child == par)
            continue;
        depth[child] = depth[v] + 1;
        dfs(child, v);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    dfs(1, 0);
    int max_depth = -1;
    int max_depth_node = -1;

    for (int i = 1; i <= n; i++)
    {
        if (depth[i] > max_depth)
        {
            max_depth = depth[i];
            max_depth_node = i;
        }
    }
    int temp = max_depth_node;
    for (int i = 0; i <= n; i++)
    {
        depth[i] = 0;
    }
    dfs(max_depth_node, 0);

    for (int i = 0; i <= n; i++)
    {
        if (depth[i] > max_depth)
        {
            max_depth = depth[i];
            max_depth_node = i;
        }
    }

    cout << max_depth << " " << max_depth_node << " " << temp << endl;

    return 0;
}