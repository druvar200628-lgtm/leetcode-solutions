class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i = 0 ; i < mat.size(); i++){
            int cnt = 0;

            for(int x : mat[i])
                cnt += x;
            pq.push({cnt,i});
            if(pq.size() > k)
                pq.pop();
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};