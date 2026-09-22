class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> temp;
        int n = intervals.size();
        bool insert = false;
        for(int i = 0 ; i < n ; i++){
            if(insert == false && intervals[i][0] >= newInterval[0]){
                temp.push_back(newInterval);
                insert = true;
            }
            temp.push_back(intervals[i]);
            }
            if(insert == false){
                temp.push_back(newInterval);
        }

        sort(temp.begin(),temp.end());
        if(temp.empty()){
            return {};
        }
       
        int start1 = temp[0][0];
        int end1 = temp[0][1];
        vector<vector<int>> res;
        for(int i = 1 ; i < temp.size() ; i++){
            int start2 = temp[i][0];
            int end2 = temp[i][1];
            if(end1 >= start2){
                end1 = max(end1,end2);
                continue;
            }else{
            res.push_back({start1,end1});
            start1 = start2;
            end1 = end2;
            }
        }
        res.push_back({start1,end1});
        return res;

        
    }
};