/*
    Dijkstra Algo is use to find the shortest distance from one 
    source vertex to all other vertex. This uses a priority queue
    or sets instead of a normal queue used in BFS. 

*/
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define INF INT_MAX

const int N = 1e5+10;
vector<pair<int, int>> g[N];

int dijkstra(vector<pair<int, int>> graph[N] ,int src, int n){

    vector<int> distance(N,INF);
    multiset<pair<int, int>> m;
    m.insert({0,src});
    distance[src]=0;

    while (m.size()>0)
    {
        auto vertex = m.begin();
        int v = vertex->second;
        int wt = vertex->first;
        m.erase(vertex);

        for (auto &&child : g[v])
        {
            int cur_v = child.first;
            int cur_wt = child.second;

            if(distance[v] + cur_wt < distance[cur_v]){
                distance[cur_v] = distance[v] + cur_wt;
                m.insert({distance[cur_v], cur_v});
            }
        }

       
        
    }
     int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if(distance[i]==INF) return -1;
            ans = max(ans,distance[i]);
        }
    return ans;
}



int networkDelayTime(vector<vector<int>>& times, int n, int k) {

    vector<pair<int, int>> graph[N];
    for (auto &&vec : times)
    {
        int u = vec[0];
        int v = vec[1];
        int w = vec[2];

        graph[u].push_back({v,w});
    }

    return dijkstra(graph, k,n);



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
        int n, m;
        for (int i = 0; i < m; i++)
        {
            int u,v, wt;
            cin>>u>>v>>wt;
            g[u].push_back({v,wt});
        }
        

    }

    return 0;
}