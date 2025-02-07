class Solution {
public:
    bool solve(string& num, int i, long long first, long long second) {
        if (i == size(num))
            return true;
        long long target = first + second;
        int len = (target == 0) ? 1 : int(log10(target)) + 1;
        if (size(num) - i < len)
            return false;
        if (stoll(num.substr(i, len)) == target)
            return solve(num, i + len, second, target);
        return false;
    }

    bool isAdditiveNumber(string num) {
        long long first = 0, second;
        int n = size(num);

        for (int i = 0; i < (n - 1) / 2; i++) {
            first = 10 * first + num[i] - '0';
            second = 0;
            int last_indx = i + 1;
            for (int j = 0; j < (n - 1) / 2; j++, last_indx++) {
                second = 10 * second + num[last_indx] - '0';
                if (solve(num, last_indx + 1, first, second)) {
                    return true;
                }
                if (second == 0)
                    break; 
            }
            if (first == 0)
                break; 
        }
        return false;
    }
};