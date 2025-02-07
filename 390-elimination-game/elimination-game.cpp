class Solution {
 public:
  int lastRemaining(const int n) {
    int ret = 1;
    bool from_left = true;
    for (int step = 1, remains = n; remains > 1; step <<= 1, remains >>= 1) {
      if (from_left || (remains & 1) == 1) {
        ret += step;
      }
      from_left = !from_left;
    }
    return ret;
  }
};