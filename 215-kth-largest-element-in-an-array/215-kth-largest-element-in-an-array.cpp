class Solution {
public:
    
    void heapify(vector<int> &arr,int n, int i){
        
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        
        if(left<n&& arr[left]>arr[largest]) largest=left;
        if(right<n && arr[right]>arr[largest]) largest=right;
        
        if(largest!=i){
            swap(arr[i],arr[largest]);
            heapify(arr,n, largest);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        
        int n=nums.size();
        for(int i=n/2-1;i>=0;i--) heapify(nums,n, i);
        
        int ans=nums[0],ct=0;
        for(int i=n-1;i>=0;i--){
            
            ans=nums[0];
            swap(nums[0],nums[i]);
            heapify(nums,i, 0);
            ct++;
            if(ct==k) break;
        }
        
        return ans;
    }
};