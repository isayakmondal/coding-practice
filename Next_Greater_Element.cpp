#include <bits/stdc++.h>

using namespace std;


// O(n^2) sol using vectors

vector<int> NGE(vector<int> v){

    int n = v.size();
    vector<int> nge(n, -1);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] > v[i])
            {
                nge[i] = v[j];
                break;
            }
            else
            {
                nge[i] = -1;
            }
        }
    }

    return nge;


}

// O(n) sol using stack

vector<int> NGE_stack(vector<int> v){

    int n = v.size();
    vector<int> nge(n, -1);
    stack<int> st;
    int ct=0;

    for (int i = 0; i < n; i++)
    {
        while(!st.empty() && v[i]>v[st.top()]){

            int temp = st.top();
            nge[temp]=i;
            st.pop();
            ct++;
        }
        st.push(i);
    }
    // cout<<ct<<endl;
    return nge;


}



int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {

        cin >> v[i];
    }

    // vector<int> nge = NGE(v);
    vector<int> nge = NGE_stack(v);

    
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " " << (nge[i]==-1?-1:v[nge[i]]) << endl;
    }

    return 0;
}
