class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int cmax = nums[0];
        int maxx = nums[0];
        
        int cmin = nums[0];
        int minn = nums[0];

        int total = nums[0];

        for(int i = 1 ; i < n ; i++){
            total += nums[i];

            cmax = max(nums[i],cmax+nums[i]);
            maxx = max(cmax,maxx);

            cmin = min(nums[i],cmin+nums[i]);
            minn = min(cmin,minn);
        }
        if(maxx < 0)return maxx;
        int c = total - minn;

        return max(c,maxx);
    }
};