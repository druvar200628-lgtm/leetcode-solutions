class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> cnt(26, 0);
        for (char c : s1) cnt[c-'a']++;

        int l = 0, need = s1.size();
        for (int r = 0; r < s2.size(); r++) {
            if (cnt[s2[r]-'a']-- > 0) need--;

            if (r - l + 1 == s1.size()) {
                if (need == 0) return true;
                if (cnt[s2[l]-'a']++ >= 0) need++;
                l++;
            }
        }
        return false;
    }
};