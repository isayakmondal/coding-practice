
#include <bits/stdc++.h>
using namespace std;
string decitoNBase (int n, int num){
    map<int,char> mp;
    for(int i=10;i<=35;i++){
        mp[i]=55+i;
    }
 
    string ans="";
    int q=num,r;
    while(q!=0){
        r=q%n;
        q=q/n;
        if(r<9){
            
            ans+=to_string(r);
        }
        else
        ans.push_back(r+55);
        
    }
    reverse(ans.begin(),ans.end());
    return ans;
    
}

int main() {
    // Write C++ code here
    
    int n=21,num=5678;
    
  cout<<decitoNBase(n,num);

   

    return 0;
}