class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for (int x = low; x <= high; x++) {
            if (x >= 10 && x < 100) {
                int a = x / 10, b = x % 10;
                if (a == b) cnt++;
            } else if (x >= 1000 && x < 10000) {
                int a = x / 1000, b = (x / 100) % 10, c = (x / 10) % 10, d = x % 10;
                if (a + b == c + d) cnt++;
            }
        }
        return cnt;
    }
};