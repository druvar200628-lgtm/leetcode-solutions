class Solution {
public:
    int find(vector<int> &a){
        int maxc = -1;
        for(int i = 0 ; i < 256 ; i++){
            maxc = max(maxc,a[i]);
        }
        return maxc;
    }
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> f(256,0);
        int low = 0 , high = 0 , res = INT_MIN;
        for(high = 0 ; high < n ; high++){
            f[s[high]]++;
            int maxcc = find(f);
            int len = high-low+1;
            int dif = len-maxcc;
            while(dif > k){
                f[s[low]]--;
                low++;
                maxcc = find(f);
                len = high-low+1;
                dif = len - maxcc;
            }
            len = high-low+1;
            res = max(len,res);
        }
        return res;
        
    }
};