class Solution {
public:
    char kthCharacter(int k) {
        int shift = __builtin_popcount(k - 1) % 26;
        return char('a' + shift);
    }
};