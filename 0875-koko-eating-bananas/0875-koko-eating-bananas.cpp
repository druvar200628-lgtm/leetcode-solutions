class Solution {
public:
    long long fun(vector<int>& piles, int speed){
        long long hours = 0;
        for(int i = 0; i < piles.size(); i++){
            hours += piles[i] / speed;
            if(piles[i] % speed!= 0) hours++;
        }
        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int res = high;

        while(low <= high){
            int guess = low + (high - low) / 2;
            long long rh = fun(piles, guess);

            if(rh > h){
                low = guess + 1;
            } else {
                res = guess;
                high = guess - 1;
            }
        }
        return res;
    }
};