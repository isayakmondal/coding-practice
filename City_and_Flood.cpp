#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1e5+10;
int parent[N];
int size[N];


void make_set(int v){

    parent[v] = v;
    size[v] = 1;

}

int find_set(int v){

    if(parent[v]==v) return v;
     return (parent[v] = find_set(parent[v]));

}

void union_set(int u, int v){

    int a = find_set(u);
    int b = find_set(v);

    if(a!=b){

        // Union by size
        if(size[b] > size[a] ) swap(a, b);
        parent[b] = a;
        size[a]+=size[b];
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
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            make_set(i);
        }

        while (k--)
        {
            int i, j;
            cin >> i >> j;
            union_set(i, j);

        }
        int ct = 0;
        for (int i = 1; i <=n; i++)
        {
            if(parent[i]==i) ct++;
        }
        
        cout<<ct<<endl;

    }

    return 0;
}