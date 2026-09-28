class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {firstRange(nums,target),lastRange(nums,target)};
            
    }
    int firstRange(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0 , high = n-1;
        int res = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] < target)
                low = mid + 1;
            else if(nums[mid] > target)
                high = mid - 1;
            else{
                res = mid;
                high = mid - 1;
            }
        }
        return res;
    }
    int lastRange(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0 , high = n-1;
        int res = -1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] < target)
                low = mid + 1;
            else if(nums[mid] > target)
                high = mid - 1;
            else{
                res = mid;
                low = mid + 1;
            }
        }
        return res;
    }
};