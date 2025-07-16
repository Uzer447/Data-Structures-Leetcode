class Solution {
public:
    int maximumLength(std::vector<int>& nums) {
        int even_count = 0;
        int odd_count = 0;
        int alt_eo = 0;
        int alt_oe = 0;
        int expected_eo_parity = 0;
        int expected_oe_parity = 1;

        for (int x : nums) {
            int current_parity = x % 2;

            if (current_parity == 0) {
                even_count++;
            } else {
                odd_count++;
            }

            if (current_parity == expected_eo_parity) {
                alt_eo++;
                expected_eo_parity = 1 - expected_eo_parity;
            }

            if (current_parity == expected_oe_parity) {
                alt_oe++;
                expected_oe_parity = 1 - expected_oe_parity;
            }
        }

        return max({even_count, odd_count, alt_eo, alt_oe});
    }
};
