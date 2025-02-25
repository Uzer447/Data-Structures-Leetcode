class Solution {
public:
    const int MOD = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        long long even_count = 1, odd_count = 0;
        long long answer = 0;
        int prefix_parity = 0;
        for (int num : arr) {
            prefix_parity = (prefix_parity + num) % 2;
            if (prefix_parity == 1) {
                answer = (answer + even_count) % MOD;
                odd_count++;
            } else {
                answer = (answer + odd_count) % MOD;
                even_count++;
            }
        }
        return (int)answer;
    }
};