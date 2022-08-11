//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int search(string pat, string txt)
    {

        vector<int> hsh(27, 0);
        vector<int> phsh(27, 0);
        for (auto s : pat)
        {

            phsh[s - 'a']++;
        }
        int k = pat.size();
        int ct = 0;

        for (int i = 0; i < k; i++)
        {

            hsh[txt[i] - 'a']++;
        }
        if (phsh == hsh)
            ct++;

        for (int j = k; j < txt.size(); j++)
        {

            hsh[txt[j - k] - 'a']--;
            hsh[txt[j] - 'a']++;
            if (phsh == hsh)
                ct++;
        }
        return ct;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends