class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> factorial(n, 1);
        for(int i = 1; i < n; ++i)
            factorial[i] = factorial[i - 1] * i;
        --k;
        vector<int> numbers;
        for(int i = 1; i <= n; ++i)
            numbers.push_back(i);
        string result;
        for(int i = n; i >= 1; --i) {
            int idx = k / factorial[i - 1];
            result += to_string(numbers[idx]);
            numbers.erase(numbers.begin() + idx);
            k %= factorial[i - 1];
        }
        return result;
    }
};