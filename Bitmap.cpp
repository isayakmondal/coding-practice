#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 183;
int graph[N][N];
bool vis[N][N];
int level[N][N];
vector<string> v;

vector<pair<int, int>> movements = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void constructGraph(int n, int m)
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            graph[i][j] = v[i][j] - '0';
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}

bool isValid(int i, int j, int n, int m)
{

    return i >= 0 && j >= 0 && i < n && j < m;
}

void reset()
{

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // graph[i][j]=0;
            vis[i][j] = false;
            level[i][j] = 0;
            v.clear();
        }
    }
}

void bfs(int n, int m)
{

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == 1)
            {
                q.push({i, j});
                vis[i][j] = true;
                level[i][j] = 0;
            }
        }
    }

    while (!q.empty())
    {
        auto t = q.front();
        int x = t.first;
        int y = t.second;
        q.pop();

        for (auto &&movement : movements)
        {
            int child_x = x + movement.first;
            int child_y = y + movement.second;

            if (!isValid(child_x, child_y, n, m))
                continue;
            if (vis[child_x][child_y])
                continue;
            q.push({child_x, child_y});
            level[child_x][child_y] = level[x][y] + 1;
            vis[child_x][child_y] = true;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    cin >> t;
    while (t--)
    {
        reset();
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {

            string val;
            cin >> val;
            v.push_back(val);
        }
        constructGraph(n, m);
        bfs(n,m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(j==m-1) cout<<level[i][j];
                else cout<<level[i][j]<<" ";
                
            }
            cout<<endl;
        }
        // string sss;
        // cin>>sss;
    }

    return 0;
}