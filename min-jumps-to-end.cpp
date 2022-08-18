#include<bits/stdc++.h>
using namespace std;

int Solution::jump(vector<int> &A) {
   
    
    int maxReach=0, curEnd=0, jumps=0;
    int n=A.size();
    
    if(A[0]==0 && A.size()==1) return 0;
    for(int i=0;i<n;i++){
        
        maxReach=max(maxReach, i+A[i]);
        if(maxReach>=n-1){
            return jumps+1;
        }
        
        if(i==maxReach) return -1;
        
        if(i==curEnd){
            jumps++;
            curEnd=maxReach;
        }
        
    }
    
    return -1;
    

}
