// Interview Bit
// Link - https://www.interviewbit.com/problems/delete-edge/
#include<bits/stdc++.h>
using namespace std;

 const int M = 1e9+7;
void dfs(int v, int p, vector<int> &wt, vector<int> tree[], vector<long long> &subtree_sum){

    subtree_sum[v] += wt[v-1];
    for(auto& child : tree[v]){
        if(v==p) continue;
        dfs(child,v, wt, tree, subtree_sum);
        subtree_sum[v]+=subtree_sum[child];
    }
}

int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) {
   
    vector<long long> subtree_sum(A.size()+1,0);
    vector<int> G[A.size()+1];
    for(auto edge : B){
        G[edge[0]].push_back(edge[1]);
        G[edge[1]].push_back(edge[0]);
    }
    long long ans = -1;
    dfs(1,0,A,G,subtree_sum);
    for(int i = 2; i <= A.size();i++){
        long long s = subtree_sum[1] - subtree_sum[i];
         ans = max(ans, subtree_sum[i] * 1LL * s) % M;
    }
    return ans;

}
