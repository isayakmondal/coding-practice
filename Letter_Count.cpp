#include<bits/stdc++.h>

using namespace std;

bool cmp(pair<char,int> a, pair<char,int> b){

    return a.second>b.second;
}

void custom_sort(map<char,int> &mp){

    vector<pair<char,int>> v;

    for(auto &ele: mp){
        v.push_back(ele);
    }

    sort(v.begin(),v.end(),cmp);

    cout<<v[0].first<<endl;

}

int main(int argc, char const *argv[])
{
    string s;
    cin>>s;

    map<char,int> mp;

    vector<pair<char,int>> v;

    for(char ch : s){

        mp[ch]++;
       
    }

    custom_sort(mp);

    // auto it = --mp.end();
   

    // auto it = mp.begin();
    // cout<<it->first<<" "<<it->second;
    return 0;
}
