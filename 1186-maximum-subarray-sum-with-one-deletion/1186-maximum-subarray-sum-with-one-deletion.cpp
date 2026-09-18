class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int oneDel = INT_MIN;
        int noDel = arr[0];
        int res = arr[0];
        for(int i = 1 ; i < n ; i++){
            int prevNoDel = noDel;
            noDel = max(arr[i],noDel + arr[i]);

            if(oneDel == INT_MIN)
                oneDel = prevNoDel;
            else
                oneDel = max(prevNoDel,oneDel + arr[i]);

            res = max({res,oneDel,noDel});
        }
        return res;
    }
};