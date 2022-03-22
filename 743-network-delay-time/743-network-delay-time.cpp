class Solution {
public:
    #define ll long long
#define INF INT_MAX

const static int N = 1e5+10;


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

        for (auto &&child : graph[v])
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
        for (int i = 1; i <= n; i++)
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
};