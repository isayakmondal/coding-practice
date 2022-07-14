#include<bits/stdc++.h>
using namespace std;

int findCount(int n, int arr[], int num, int diff) {
    
    int ct = 0;
    for (int i = 0; i < n; i++)
    {
        int res = abs(arr[i]-num);
        if(res<=diff) ct++;
    }
    
    return ct==0?-1:ct;

}
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int num; cin >> num;
    int diff; cin >> diff;
    cout << findCount(n, arr, num, diff);
}