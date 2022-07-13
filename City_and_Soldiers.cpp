//Getting TLE for now
#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1e5 + 10;
int parent[N];
long long size[N];

void make_set(int a)
{
    parent[a] = a;
    size[a] = 1;
}
//Hey 
int find_set(int a)
{

    if (parent[a] == a)
        return a;
    else
        return parent[a] = find_set(parent[a]);
}

void union_set(int a, int b)
{

    a = find_set(a);
    b = find_set(b);

    if (a != b)
    {
        parent[a] = b;
        size[a] += size[b];
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
        int l;
        int n, q;
        cin >> n >> q;
        for (int i = 1; i <= n; i++)
        {
            make_set(i);
        }
        {
            int choice;
            cin >> choice;
            switch (choice)
            {
            case 1:
                int a, b;
                cin >> a >> b;
                union_set(a, b);
                break;

            case 2:
                int c;
                cin >> c;
                l = find_set(c);
                if(l!=c)
                parent[l] = c;
                break;

            case 3:
                int d;
                cin >> d;
                cout << find_set(d) << endl;
                break;
            default:
                break;
            }
        }
    }
    
    return 0;
}