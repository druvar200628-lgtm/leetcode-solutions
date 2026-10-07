class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long ,vector<int>>> pq;

        for(auto &p : points){
            long long x = p[0];
            long long y = p[1];
            long long d = x*x + y*y;
            pq.push({d,p});
            if(pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;        
    }
};