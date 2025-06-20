class Solution {
public:
    int helper(string s, int k) {
        int len = s.size();
        int maxans = 0;
        int up = 0, down = 0;
        int right = 0, left = 0;

        for (int i = 0; i < len; i++) {
            if (s[i] == 'N')
                up += 1;
            else if (s[i] == 'S')
                down += 1;
            else if (s[i] == 'E')
                right += 1;
            else if (s[i] == 'W')
                left += 1;
            int dist = abs(up - down) + abs(right - left);
            int moves = min(up, down) + min(right, left);
            int possibleans = min(k, moves) * 2;
            int maxpossans = min(i+1,dist + possibleans);

            maxans = max(maxans, maxpossans);
        }
        return maxans;
    }
    int maxDistance(string s, int k) { return helper(s, k); }
};
