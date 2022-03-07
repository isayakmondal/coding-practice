#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1e5;
vector<int> graph[N];
vector<bool> visited(N, 0);

void dfs(int v)
{

    visited[v] = true;
    
    
        for (int j = 0; j < graph[v].size(); j++)
        {
            cout<<graph[v][j]<<endl;
        }
        
    
    
    
    for (auto &child : graph[v])
    {
    cout << " Parent-> " << v << " Child-> "<< child<<endl;
        // cout << child <<endl;
        if (visited[child])
            continue;
        dfs(child);
        // cout<<endl;
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
        int n_v, n_e;
        cin >> n_v >> n_e;
        for (int i = 0; i < n_e; i++)
        {
            int v1, v2;
            cin >> v1 >> v2;
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }
        // cout<<'a'<<endl;
        // cout<<graph[3][0]<<endl;
        dfs(graph[3][0]);
    }

    return 0;
}