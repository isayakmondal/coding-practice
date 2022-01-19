// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    //Function to return a list of indexes denoting the required
    //combinations whose sum is equal to given number.

    vector<vector<int>> v;

    void generator(vector<int> &comb, int sum, int b, vector<int> &A)
    {

        if (sum > b)
            return;

        if (sum == b)
        {

            v.push_back(comb);
            return;
        }

        for (int i = 0; i < A.size(); i++)
        {

            if (comb.empty() || A[i] >= comb[comb.size() - 1])
            {
                comb.push_back(A[i]);
                generator(comb, sum + A[i], b, A);
                comb.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int> &A, int B)
    {

        sort(A.begin(), A.end());
        auto ip = unique(A.begin(), A.end());
        A.resize(distance(A.begin(), ip));

        vector<int> temp;
        generator(temp, 0, B, A);
        return v;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> A;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            A.push_back(x);
        }
        int sum;
        cin >> sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
        if (result.size() == 0)
        {
            cout << "Empty";
        }
        for (int i = 0; i < result.size(); i++)
        {
            cout << '(';
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j];
                if (j < result[i].size() - 1)
                    cout << " ";
            }
            cout << ")";
        }
        cout << "\n";
    }
} // } Driver Code Ends