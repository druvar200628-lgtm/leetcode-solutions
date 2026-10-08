class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        for(char c : s){
            mp[c]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto &it : mp)
            pq.push({it.second,it.first});

            string res = "";
            int seat = 0;
            while(!pq.empty()){
                auto p = pq.top();
                pq.pop();
                if(seat == 0 ||  res[seat - 1] != p.second){
                    res.push_back(p.second);
                    seat++;
                    p.first--;
                    if(p.first > 0){
                        pq.push(p);
                    }
                }
                else{
                    if(pq.empty())
                        return "";
                    auto q = pq.top();
                    pq.pop();
                    res.push_back(q.second);
                    seat++;
                    q.first--;
                    if(q.first > 0)
                        pq.push(q);
                    pq.push(p);
                }
            }
            return res;
    }
};