class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int minl = INT_MAX;
        int sum = 0;

        while(r < n){
            sum += nums[r];
            while(sum >= target){ 
                int len = r - l + 1;
                minl = min(minl, len);
                sum -= nums[l];
                l++;
            }
            r++;
        }

        
        if(minl == INT_MAX) return 0;
        return minl;
    }
};