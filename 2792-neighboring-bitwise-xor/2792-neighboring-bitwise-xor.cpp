class Solution {
public:
    bool doesValidArrayExist(std::vector<int>& derived) {
        int sum = 0;
        for (int num : derived) {
            sum += num;
        }
        return sum % 2 == 0;
    }
};