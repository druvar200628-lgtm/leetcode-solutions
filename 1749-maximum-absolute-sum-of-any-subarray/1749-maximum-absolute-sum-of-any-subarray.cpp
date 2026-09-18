class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int  n = nums.size();

        int cmax = nums[0];
        int maxx = nums[0];

        int cmin = nums[0];
        int minn = nums[0];

        for(int i = 1; i < n ; i++){
            cmax = max(nums[i],cmax + nums[i]);
            maxx = max(maxx,cmax);

            cmin = min(nums[i],cmin + nums[i]);
            minn = min(minn,cmin);
        }
        return max(abs(maxx),abs(minn));
        
    }
};