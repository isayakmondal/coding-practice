#include <bits/stdc++.h>

using namespace std;


unordered_map<char,int> symbols = {{'[',-1},{'{',-2},{'(',-3},{']',1},{'}',2},{')',3}};

string isBalanced(string s) {

    stack<char> st;
    for(char each_char : s){

        if(symbols[each_char]<0){
            st.push(each_char);
        }
        else if(st.empty()) return "NO";
        else {

            if(symbols[each_char]==0) continue;
            char top = st.top();
            st.pop();
            if(symbols[each_char] + symbols[top]!=0) return "NO";
        }
    }

    if(st.empty()) return "YES";
    return "NO";
      
    
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    while(n--){

        string s;
        cin>>s;
        cout<<isBalanced(s)<<endl;
    }



    return 0;
}
