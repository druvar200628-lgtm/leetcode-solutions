class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int zero = 0;
        int one = 0;
        unordered_map<int,int> f;
        int res = 0;
        f[0] = -1;
        for(int i = 0 ; i < n ; i++ ){
            if(nums[i] == 0)
                zero++;
            else
                one++;
            int d = zero - one;
            if(d == 0){
                res = max(res,i+1);
                continue;
            }
            if(f.find(d) == f.end())
                f[d] = i;
            else{
                
                int len = i - f[d];
                res = max(len,res);
            } 
        }
    return res;    
    }
};