class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        struct cmp {
        bool operator()(pair<int,string>& a, pair<int,string>& b) {
           if(a.first == b.first)
               return a.second < b.second; 
           return a.first > b.first;
        }
        };
        priority_queue<pair<int,string>, vector<pair<int,string>>, cmp> pq;

   unordered_map<string,int> f;
   for(int i = 0 ; i < n ; i++){
    f[words[i]]++;
   }
   for(auto i : f){
    string ele = i.first;
    int fre = i.second;
    pair<int, string> cur = {fre,ele};
    if(pq.size() < k){
        pq.push(cur);
        continue;
    }
    if(cur.first < pq.top().first)
    continue;
    if(cur.first == pq.top().first && cur.second > pq.top().second )
    continue;
    pq.pop();
    pq.push(cur);
    }

    vector<string> res;
    while(!pq.empty()){
        res.push_back(pq.top().second);
        pq.pop();

    }
    reverse(res.begin(),res.end());
    return res;
    }
};