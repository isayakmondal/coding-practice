/*
    Find the depth and height of a node in a given graph

*/
#include <bits/stdc++.h>

using namespace std;

#define ll long long
int const N = 1e5;
vector<int> tree[N];
int depth[N];
int height[N];
// O(2N) extra space, but it has an optimized time complexity, it is mostly used when we
//  have to find for q queries. If we just want to find for a particular node we may not
// arrays
int final_height;
int final_depth;
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

void getDepth(int v, int par, int d, int n)
{
    if (v == n)
    {
        final_depth = d;
        return;
    }

    for (auto &&child : tree[v])
    {
        if (child == par)
            continue;

        getDepth(child, v, d + 1, n);
    }
}
int temp = 0;
int getHeight(int v, int par)
{

    int maxHeight = 0;
    for (auto &&child : tree[v])
    {
        if (child == par)
            continue;

        maxHeight = max(maxHeight, getHeight(child, v)+1);
    }
    return maxHeight ;
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
        // dfs(1, 0);
        // for (int i = 1; i <= n; i++)
        // {
        //     cout << i << " -> " << depth[i] << " " << height[i] << endl;
        // }
        getDepth(1, 0, 0, 5);
        cout << getHeight(2,1)<< endl;
    }

    return 0;
}