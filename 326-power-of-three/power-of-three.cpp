class Solution {
public:
    bool isPowerOfThree(int n) {
        int maxPower=1162261467;
        return n>0 && maxPower%n==0;
    }
};