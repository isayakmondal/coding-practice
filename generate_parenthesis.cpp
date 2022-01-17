#include<bits/stdc++.h>
using namespace std;

//Only the class and function, No main().

class Solution
{
public:
    vector<string> v;

    void generate(string s, int opening, int closing)
    {

        if (opening == 0 && closing == 0)
        {
            v.push_back(s);
            return;
        }

        if (opening > 0)
        {
            s.push_back('(');
            generate(s, opening - 1, closing);

            s.pop_back();
        }

        if (closing > 0 && opening < closing)
        {
            s.push_back(')');
            generate(s, opening, closing - 1);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {

        generate("", n, n);
        return v;
    }
};