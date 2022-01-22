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


#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,3,4,5,6,7,8};
    cout<<nums.size()<<endl;

    nums.erase(nums.begin()+0);

    cout<<nums.size()<<endl;
    for(auto & ele : nums){
        cout<<ele<<" ";
    }
    
   
    

    return 0;
}