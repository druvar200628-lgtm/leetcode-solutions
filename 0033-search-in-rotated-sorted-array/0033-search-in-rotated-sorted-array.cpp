class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0 , high = n-1;
        while(low <= high){
            int g = (low + high)/2;
            if(nums[g] == target){
                return g;
            }
            if(nums[g] > nums[n-1]){
                if(nums[g] < target)
                    low = g + 1;
                else{
                    if(nums[0] > target)
                        low = g + 1;
                    else
                        high = g - 1;
                }
            }
            else{
                
            if(nums[g] > target)
                    high = g - 1;
            else{
                if(nums[n-1] < target)
                    high = g - 1;
                else
                    low = g + 1;
                }
            }            
        }
        return -1;
    }
        
    };
