class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> phone = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> res;
        string curr = "";

        backtrack(digits, 0, phone, curr, res);
        return res;
    }

private:
    void backtrack(string &digits, int i, vector<string> &phone, string &curr, vector<string> &res) {
        if (i == digits.size()) {
            res.push_back(curr);
            return;
        }

        string letters = phone[digits[i] - '0'];
        for (char ch : letters) {
            curr.push_back(ch);
            backtrack(digits, i + 1, phone, curr, res);
            curr.pop_back();
        }
    }
};