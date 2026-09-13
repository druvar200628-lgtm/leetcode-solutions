class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low = 0 , high = 0 , n = nums.size();
        int res = 0 , zerocnt = 0;
        for(high = 0 ; high < n ; high++){
            if(nums[high] == 0)zerocnt++;

            while(zerocnt > k){
                if(nums[low] == 0)
                    zerocnt--;
                low++;
            }
            res = max(res,high-low+1);
            
        }
        return res;
        
    }
};