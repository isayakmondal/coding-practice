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
        if (child == par)
            continue;
        sumOfSubtree(child, v);
        subtree_sum[v] += subtree_sum[child];
    }
}
// Without using any extra space.
int __sumOfSubtree(int v, int par)
{

    int sum = 0;
    for (auto &&child : tree[v])
    {
        if (child == par)
            continue;
        sum += __sumOfSubtree(child, v);
    }
    return v + sum;
}

void evenCount(int v, int par)
{

    if (v % 2 == 0)
    {
        even_ct[v]++;
    }

    for (auto &&child : tree[v])
    {
        if (child == par)
            continue;


        evenCount(child, v);
        even_ct[v] += even_ct[child];
    }
}

// Without using extra space
int __evenCount(int v, int par)
{

    int count = 0;
    for (auto &&child : tree[v])
    {
        if (child == par)
            continue;
        count += __evenCount(child, v);
    }
    return v % 2 == 0 ? count + 1 : count;
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
    // evenCount(1, 0);
    // cout<<subtree_sum[2];
    evenCount(4, 3);
    cout << even_ct[4];
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