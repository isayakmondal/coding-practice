//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    unordered_map<char, int> mp = {{'^', 3}, {'*', 2}, {'/', 2}, {'+', 1}, {'-', 1}, {'(', 0}, {')', 0}};

    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s)
    {
        // Your code here

        stack<char> st;
        string postfix;

        for (auto ch : s)
        {

            if (ch == ')')
            {

                while (st.top() != '(')
                {

                    postfix.push_back(st.top());
                    st.pop();
                }
                st.pop();
            }
            else if (ch == '(')
            {

                st.push('(');
            }
            else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
            {

                while (!st.empty() && mp[st.top()] >= mp[ch])
                {
                    postfix.push_back(st.top());
                    st.pop();
                }
                st.push(ch);
            }
            else
            {
                postfix.push_back(ch);
            }
        }

        while (!st.empty())
        {
            postfix.push_back(st.top());
            st.pop();
        }

        return postfix;
    }
};

//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--)
    {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends