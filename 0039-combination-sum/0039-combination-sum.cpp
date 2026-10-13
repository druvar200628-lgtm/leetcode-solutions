class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& candidates, int target, int idx, vector<int>& curr, int sum) {
        
        if (sum == target) {
            ans.push_back(curr);
            return; 
        }
        if (sum > target || idx >= candidates.size()) {
            return;
        }

        curr.push_back(candidates[idx]);
        solve(candidates, target, idx, curr, sum + candidates[idx]);
        curr.pop_back(); 

       
        solve(candidates, target, idx + 1, curr, sum);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        solve(candidates, target, 0, curr, 0);
        return ans;
    }
};