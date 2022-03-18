#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1e5 + 10;
vector<int> g[N];
bool vis[N];
int level[N];

void bfs(int source)
{

    queue<int> q;
    q.push(source);
    vis[source] = true;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        cout << front << " ";
        for (auto &&child : g[front])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                level[child]  = level[front] + 1;
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
        int n;
        cin >> n;

        for (int i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        bfs(1);
    }

    return 0;
}