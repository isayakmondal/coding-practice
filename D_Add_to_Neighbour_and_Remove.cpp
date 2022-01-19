#include<bits/stdc++.h>

using namespace std;

vector<int> global;

    void addRemove(vector<int> &v,int i, int ct){

            if(all_of(v.begin(),v.end(),[&](int i){return i == v[0];})){
                global.push_back(ct);
                return;
            }

            int temp = v[i];
            temp+=v[i-1];
            v.pop_back();
            v.push_back(temp);
            addRemove(v,i,ct+1);
            
            //Incomplete and probably incorrect

    }



int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            cin>>v[i];
        }

        addRemove(v,v.size()-1,0);

        auto it = min_element(global.begin(),global.end());
        cout<<*it<<endl;
    }
    return 0;
}
