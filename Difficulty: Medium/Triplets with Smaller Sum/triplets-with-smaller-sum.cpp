class Solution {
  public:
    int countTriplets(int sum, vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int ans = 0;
        
        for(int i = 0;i<n-2;i++){
            int l = i + 1,r = n-1;
            
            while(l < r){
                if(arr[i]+arr[l]+arr[r] >= sum){
                    r--;
                    
                }
                else{
                    ans += (r-l);
                    l++;
                }
            }
        }
        
    return ans;    
    }
};