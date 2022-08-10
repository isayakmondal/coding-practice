//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                            long long int n, long long int k);

// Driver program to test above functions
int main()
{
    long long int t, i;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

vector<long long> printFirstNegativeInteger(long long int a[],
                                            long long int n, long long int k)
{

    vector<long long> ans;

    queue<long long> q;
    long long tmp;
    for (int i = 0; i < k; i++)
    {

        if (a[i] < 0)
        {
            q.push(a[i]);
        }
    }

    q.empty() ? tmp = 0 : tmp = q.front();
    ans.push_back(tmp);

    for (int j = k; j < n; j++)
    {
        int ele = 0;

        if (a[j] < 0)
        {
            q.push(a[j]);
        }

        if (a[j - k] < 0)
        {
            if (!q.empty())
            {
                q.pop();
            }
        }

        if (!q.empty())
            ele = q.front();

        ans.push_back(ele);
    }
    return ans;
}