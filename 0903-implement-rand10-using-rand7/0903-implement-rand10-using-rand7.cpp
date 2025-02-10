// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int a = rand7();
        int b = rand7();
        int val = (a - 1) * 7 + b;
        if (val > 40) {
            a = rand7();
            b = rand7();
            val = (a - 1) * 7 + b;
        }
        return val%10+1;
    }
};