class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1, high = *max_element(candies.begin(), candies.end()), ans = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            long long total = 0;
            for (int c : candies) {
                total += c / mid;
                if(total >= k) break;
            }
            if(total >= k){
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};