#include<bits/stdc++.h>
const int size = 1e7+10;
int arr[size];

using namespace std;

int main(){
    
    int n,m;
    cin>>n>>m;
    long long max=-1;
    while(m--){
        int a,b;
        long long k;
        cin>>a>>b>>k;

        arr[a]+=k;
        arr[b+1]-=k;
        }

         for(int i=1;i<=n;i++){
            arr[i]=arr[i-1]+arr[i];
            if(arr[i]>max){
                max=arr[i];
            }
         }

    cout<<max<<endl;
        
}
