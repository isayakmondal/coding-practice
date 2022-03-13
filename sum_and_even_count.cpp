/*
    Given Q queires, Q<=10^5
    In each query given V,
    Print subtree sum of  V and Number of even no in
    subtree of V
*/
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1e5 + 10;
vector<int> tree[N];
int subtree_sum[N];
int even_ct[N];

void sumOfSubtree(int v, int par)
{

    subtree_sum[v] = v;
    for (auto &&child : tree[v])
    {
        if (child == par) continue;
        sumOfSubtree(child, v);
        subtree_sum[v] += subtree_sum[child];
    }
}

void evenCount(int v, int par)
{

    even_ct[v] = v;
    for (auto &&child : tree[v])
    {
        if (child == par) continue;
        evenCount(child, v);
        if(even_ct[child]%2==0)
        even_ct[v]+=even_ct[child];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[v].push_back(u);
        tree[u].push_back(v);
    }

    // sumOfSubtree(1, 0);
    evenCount(1,0);
    cout<<even_ct[1];
    // ll t = 1;
    // cin >> t;
    // while (t--)
    // {
    //     int n;
    //     cin >> n;
    //     cout << subtree_sum[n];
    // }

    return 0;
}