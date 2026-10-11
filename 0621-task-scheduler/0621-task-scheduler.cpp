class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int num = tasks.size();
        unordered_map<char,int> freq;
        unordered_map<char,int> free;
        for(int i = 0 ; i < num ; i++){
            freq[tasks[i]]++;
            free[tasks[i]]=-1;
        }
        priority_queue<pair<int,char>> pq;
        for(auto p : freq){
            pq.push({p.second,p.first});
        }
        int seat = 1;
        while(!pq.empty()){
            vector<pair<int,char>> pulled;
            while(!pq.empty()){
                pair<int , char> p = pq.top();
                pq.pop();
                int fr = p.first;
                int task = p.second;
                if(free[task] <= seat){
                    if(p.first > 1)
                        pq.push({p.first-1,p.second});
                        free[p.second] = n + 1 + seat;
                        break;
                    }
                    else{
                        pulled.push_back(p);
                    }
                }
            for(int i = 0 ; i<pulled.size() ; i++)
                pq.push(pulled[i]);
                seat++;
            
        }
        return seat - 1;
        
    }
};