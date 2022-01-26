// #include<iostream>
// #include<stdlib.h>

// using namespace std;

// class Test{
    
//     Test(){
//         cout<<"ss";
//     }
// };

// int main(){
//     // Test *t=(Test*)malloc(sizeof(Test));
//     Test *t = new Test;
// }
// struct test{
// int k;
// char c;

// }s;

// int main(){
 
//  int t=9;
// while (t--)
// {
//     cout<<t<<endl;
//     if(t==4) break;
// }

// }

// #include<bits/stdc++.h>

// using namespace std;

// int main(int argc, char const *argv[])
// {
//     vector<int> nums = {5,7,7,8,8,10};
//     int target =8;
//     // int arr[]= {5,7,7,8,8,10};
//     // auto it = find(arr,arr+sizeof(arr),8);
//     // cout<<*(arr+3);
    
//     // auto itr = find(nums.begin(),nums.end(),8);
//     // cout<<itr-nums.begin();
//     auto it = lower_bound(nums.begin(),nums.end(),target);
//     auto it2 = upper_bound(nums.begin(),nums.end(),target);
//     cout<<it-nums.begin()<<endl;
//     cout<<it2-nums.begin()<<endl;
    

//     return 0;
// }


// #include<bits/stdc++.h>

// using namespace std;

// int main(int argc, char const *argv[])
// {
//     vector<int> nums = {1,2,3,4,5,6,7,8};
//     cout<<nums.size()<<endl;

//     nums.erase(nums.begin()+0);

//     cout<<nums.size()<<endl;
//     for(auto & ele : nums){
//         cout<<ele<<" ";
//     }
    
   
    

//     return 0;
// }

//Binary Search


#include<bits/stdc++.h>

using namespace std;

bool binarySearch1(int *arr, int n,int ele){

    int low = 0;
    int high = n-1;
    

    while (high>=low)
    {       
        int mid = (high+low)/2;

        if(ele==arr[mid]) return true;
        else if(ele>arr[mid]){
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    
    return false;
}


int main(int argc, char const *argv[])
{
    
    int arr[]={2,3,5,6,8,9,12,14};
    int n=sizeof(arr)/sizeof(arr[0]);
    // cout<<binary_search(arr,arr+n,6);
    cout<<binarySearch1(arr,n,4);
    
    
   
    

    return 0;
}