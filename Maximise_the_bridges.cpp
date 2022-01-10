// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>
// #include <sstream>
// #include <queue>
// #include <deque>
// #include <bitset>
// #include <iterator>
// #include <list>
// #include <stack>
// #include <map>
// #include <set>
// #include <functional>
// #include <numeric>
// #include <utility>
// #include <limits>
// #include <ctime>
// #include <cmath>
// #include <stdio.h>
// #include <cstring>
// #include <cctype>
// #include <cstdlib>
// #include <cassert>
// #include <unordered_map>
// #include <unordered_set>

// using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n,m;
//         cin>>n>>m;

//         if(m==(n*(n-1)/2)){
//             for (int i = 1; i < m; i++)
//             {
//                 cout<<i<<" "<<i+1<<endl;
//             }
//             cout<<n<<" "<<1;
//             cout<<endl;
            
            
//         } else if(m==n-1){
//              for (int i = 1; i <= m; i++)
//             {
//                 cout<<i<<" "<<i+1<<endl;
//             }
            
            
//         } else{
//             for (int i = 1; i < m; i++)
//             {
//                 cout<<i<<" "<<i+1<<endl;
//             }
//             cout<<m-1<<" "<<1;
//             cout<<endl;
            
//         }

//     }

//     return 0;
// }
#include<bits/stdc++.h>

using namespace std;

int main(){

int t;

cin>>t;

while(t--){

    int n,m;
    
    cin>>n>>m;
    
    map<int ,int> x;
    
    for(int i=1;i<n;i++){
    
        x[i]=i+1;
        
        cout<<i<<" "<<i+1<<"\n";
        
        m=m-1;
        
    }
    
    int last=3;
    
    while(m>0){
    
        for(int i=1;i<last;i++){
        
            if (x[i]<last){
            
                x.insert (std::pair<int,int>(i,last));
                
                cout<<i<<" "<<last<<"\n";
                
                m=m-1;
                
                if(m==0){
                
                    break;
                    
                }}}
                
        last=last+1;
        
    }}}