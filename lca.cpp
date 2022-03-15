#include <bits/stdc++.h>

using namespace std;

#define ll long long

int const N = 1e5;
vector<int> tree[N];
int parents[N];

void dfs(int v, int par)
{

    parents[v] = par;
    for (auto &&child : tree[v])
    {
        if (child == par)
            continue;
        dfs(child, v);
    }
}

vector<int> path(int v)
{

    vector<int> ans;
    while (v != -1)
    {
        ans.push_back(v);
        v = parents[v];
    }
    reverse(ans.begin(), ans.end());
    return ans;
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
        for (int i = 0; i < n-1; i++)
        {
            int x, y;
            cin >> x >> y;
            tree[x].push_back(y);
            tree[y].push_back(x);
        }

        dfs(1, -1);

        int x, y;
        cin >> x >> y;
        vector<int> path_x = path(x);
        vector<int> path_y = path(y);

        int lca = -1;
        int min_len = min(path_x.size(), path_y.size());
        for (int i = 0; i < min_len; i++)
        {
            if (path_x[i] == path_y[i])
            {
                lca = path_x[i];
            }
            else
                break;
        }
        cout << lca << endl;
    }

    return 0;
}