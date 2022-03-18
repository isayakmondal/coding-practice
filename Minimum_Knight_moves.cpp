#include <bits/stdc++.h>

using namespace std;

#define ll long long
int graph[8][8];
bool vis[8][8];
int level[8][8];

vector<pair<int, int>> possiblePaths = {
    {1, -2},
    {1, 2},
    {-1, -2},
    {-1, 2},
    {-2, 1},
    {2, 1},
    {-2, -1},
    {2, -1},
};

bool isValid(int x, int y)
{

    return x >= 0 && y >= 0 && x < 8 && y < 8;
}

int getX(string s)
{

    return s[0] - 'a';
}

int getY(string s)
{

    return s[1] - '1';
}

int bfs(string src, string des)
{

    int src_X = getX(src);
    int src_Y = getY(src);

    int des_X = getX(des);
    int des_Y = getY(des);

    queue<pair<int, int>> q;
    q.push({src_X, src_Y});
    vis[src_X][src_Y] = true;

    while (!q.empty())
    {
        auto front = q.front();
        q.pop();
        int x = front.first;
        int y = front.second;

        for (auto &&path : possiblePaths)
        {
            int new_X = x + path.first;
            int new_Y = y + path.second;
            if (vis[new_X][new_Y])
                continue;
            if (isValid(new_X, new_Y))
            {

                q.push({new_X, new_Y});
                vis[new_X][new_Y] = true;
                level[new_X][new_Y] = level[x][y] + 1;
            }
        }
    }

    return level[des_X][des_Y];
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
        string a, b;
        cin >> a >> b;
        cout << bfs(a, b) << endl;
    }

    return 0;
}