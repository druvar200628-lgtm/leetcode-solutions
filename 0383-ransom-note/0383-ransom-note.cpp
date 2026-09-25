class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.size();
        int m = magazine.size();
        unordered_map<char,int> have;
        unordered_map<char,int> need;
        for(int i = 0 ; i < n ; i++)
            need[ransomNote[i]]++;
        for(int i = 0 ; i < m ; i++)
            have[magazine[i]]++;
        return fun(have,need);        
    }
    bool fun( unordered_map<char,int> have,unordered_map<char,int> need){
        for(auto i : need){
            char c = i.first;
            int fneed = i.second;
            int fhave = have[c];
            if(fhave < fneed){
                return false;
            }
        }
        return true;
    }
};