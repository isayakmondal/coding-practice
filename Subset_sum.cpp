//Interview Bit Question

int dp[105][100005];
int func(int ind, int sum, vector<int> &A){

    if(sum==0) return 1;
    if(ind<0) return 0;
    if(dp[ind][sum]!=-1) return dp[ind][sum];
   bool ans;
    ans = func(ind-1,sum,A);

    if(sum-A[ind]>=0)
     ans = ans || func(ind-1,sum-A[ind],A);

    return dp[ind][sum] = ans;
}

int Solution::solve(vector<int> &A, int B) {
    memset(dp, -1, sizeof(dp));
    return func(A.size()-1,B,A);
}
