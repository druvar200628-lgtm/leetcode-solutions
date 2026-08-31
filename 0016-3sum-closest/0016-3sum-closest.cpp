class Solution {
public:
    int threeSumClosest(vector<int>& nums, int tar) { 
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int max_dif = INT_MAX;
        int res_sum = nums[0] + nums[1] + nums[2];

        for(int i = 0 ; i < n-2 ; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int l = i+1;
            int r = n-1;

            while( l < r){
                int Sum = nums[i] + nums[l] + nums[r];
                int dif = abs(Sum - tar);
                if( dif < max_dif){
                    max_dif = dif;
                    res_sum = Sum;
                }

                if(Sum == tar) return Sum;
                else if(Sum < tar) l++;
                else r--;
            }
        }
        return res_sum; 
    }
};