#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int N = 1e5 + 10;
vector<pair<int, int>> g[N];
vector<int> level(N, INT_MAX);

int bfs(int src, int des)
{

    deque<int> q;
    q.push_back(src);
    level[src] = 0;

    while (!q.empty())
    {
        int cur_v = q.front();
        q.pop_front();

        for (auto &&child : g[cur_v])
        {
            int child_v = child.first;
            int wt = child.second;
            if (level[cur_v] + wt < level[child_v])
            {

                level[child_v] = level[cur_v] + wt;
                if (wt == 0)
                {
                    q.push_front(child_v);
                }
                else
                {
                    q.push_back(child_v);
                }
            }
        }
    }

    return level[des] == INT_MAX ? -1 : level[des];
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
            int x, y;
            cin >> x >> y;
            if(x==y) continue;
            g[x].push_back({y, 0});
            g[y].push_back({x, 1});
        }

        cout << bfs(1, n) << endl;
    }

    return 0;
}