
// Gets accepted on SPOJ
#include <iostream>
using namespace std;

// and as it's global default here it's set to 0
int counter[125]; // may be require 122 (just take higher)

int main(){

    string s;
    char ans;
    int max = 0;
    cin>>s;

    for(int i = 0; i<s.size(); i++)
        counter[s[i]]++;
    
    for(int i = 0; i<125; i++){
        if(counter[i] > max){
            max = counter[i];
            ans = i;
        }
    }

    cout<<ans<<'\n';
    return 0;
}

//Correct but doesn't get accepted on SPOJ.
/*
#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<char, int> a, pair<char, int> b)
{

    return a.second > b.second;
}

void custom_sort(map<char, int> &mp)
{

    vector<pair<char, int>> v;

    for (auto &ele : mp)
    {
        v.push_back(ele);
    }

    sort(v.begin(), v.end(), cmp);

    cout << v[0].first << endl;
}

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;

    map<char, int> mp;

    vector<pair<char, int>> v;

    for (char ch : s)
    {

        mp[ch]++;
    }

    custom_sort(mp);

    // auto it = --mp.end();

    // auto it = mp.begin();
    // cout<<it->first<<" "<<it->second;

    return 0;
} */