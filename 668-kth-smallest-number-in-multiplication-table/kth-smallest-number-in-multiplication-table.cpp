class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        auto count = [&](int x) {
            int cnt = 0;
            for (int i = 1; i <= m; ++i)
                cnt += std::min(n, x / i);
            return cnt;
        };
        int low = 1, high = m * n;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (count(mid) < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};