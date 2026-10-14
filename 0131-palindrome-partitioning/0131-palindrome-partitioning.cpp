class Solution {
public:
    vector<vector<string>> ans;

    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l]!= s[r]) return false;
            l++; r--;
        }
        return true;
    }

    void solve(string& s, int idx, vector<string>& curr) {
        
        if (idx == s.size()) {
            ans.push_back(curr);
            return;
        }

        
        for (int j = idx; j < s.size(); j++) {
            if (isPalindrome(s, idx, j)) {
                
                curr.push_back(s.substr(idx, j - idx + 1));
                solve(s, j + 1, curr);
                curr.pop_back(); 
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> curr;
        solve(s, 0, curr);
        return ans;
    }
};