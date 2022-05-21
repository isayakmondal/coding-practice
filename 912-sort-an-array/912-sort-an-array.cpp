class Solution {
public:
    
    void maxHeapify(vector<int> &nums, int n,int i){
        
        
        int parent = i;
        int l = 2*i + 1;
        int r = 2*i + 2;
        
        if(l<n && nums[parent] < nums[l] )
            parent = l;
        if(r<n && nums[parent] < nums[r] )
            parent = r;
        
        if(parent!=i){
            swap(nums[i], nums[parent]);
            maxHeapify(nums, n, parent);
        }
    } 
    
    
    
    void heapSort(vector<int> &nums){
    
        int n = nums.size();
        //Build Heap
        for(int i = n/2 -1; i>=0; i--){
            
            maxHeapify(nums,n,i);
        }
        
        //Removing Elements one by one
        for(int i = n-1; i>0; i--){
            
            swap(nums[i], nums[0]);
            maxHeapify(nums, i, 0);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        
        heapSort(nums);
        
        return nums;
        
    }
};