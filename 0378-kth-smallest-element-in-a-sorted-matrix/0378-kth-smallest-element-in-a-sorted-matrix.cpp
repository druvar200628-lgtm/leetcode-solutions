class Solution {
public:
    int fun(vector<vector<int>>& matrix,int n , int m , int guess){
        int row = n-1;
        int col = 0;
        int cnt = 0;
        while(row >= 0 && col < m){
            if(matrix[row][col] <= guess){
                cnt += row + 1;
                col++;
            }
            else{
                row--;
            }
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int res = -1 , low = matrix[0][0] , high = matrix[n-1][m-1];
        while(low <= high){
            int guess = (low + high)/2;
            int ans = fun(matrix,n,m,guess);
            if(ans < k){
                low = guess + 1;
            }
            else{
                res = guess;
                high = guess - 1;
            }

        }
        return res;
        
    }
};