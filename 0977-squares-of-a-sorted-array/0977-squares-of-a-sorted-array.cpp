class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        int siz = nums.size();
        for(int i = 0 ; i < siz ; i++){
            if(nums[i] < 0){
                neg.push_back(nums[i]);
            }
            else{
                pos.push_back(nums[i]);
            }
        }
        if(neg.size() == 0){
                for(int i = 0 ; i<pos.size(); i++){
                    pos[i] = pos[i] * pos[i];
                    
                }
                return pos;
            }
        if(pos.size() == 0){
                for(int i = 0 ; i<neg.size(); i++){
                    neg[i] = neg[i] * neg[i];
                    
                }
                reverse(neg.begin(),neg.end());
                return neg;
            }    
            int i = 0;
            int j = 0 , id = 0;
            int n = neg.size();
            int m = pos.size();
            vector<int> res(n+m);

            for(i = 0;i < n;i++){
            neg[i] = neg[i]*neg[i];
            }
            reverse(neg.begin(),neg.end());
            
            for(j = 0;j<m;j++)
            pos[j] = pos[j]*pos[j];
            i =0,j=0;

            while(i<n && j<m){
                if(neg[i] <= pos[j]){
                    res[id] = neg[i];
                    id++;
                    i++;
                }
                else{
                    res[id] = pos[j];
                    id++;
                    j++;
                }
            }
            while(i < n){
                res[id] = neg[i];
                    id++;
                    i++;
            }
            while(j < m){
                 res[id] = pos[j];
                    id++;
                    j++;
            }
            
        return res;     
        
        
        
    }
};