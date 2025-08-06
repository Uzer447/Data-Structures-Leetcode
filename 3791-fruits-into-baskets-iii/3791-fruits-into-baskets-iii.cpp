class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size(), size = 1;
        while(size < n) size <<= 1;
        vector<int> tree(2 * size, 0);
        for (int i = 0; i < n; i++) tree[size + i] = baskets[i];
        for (int i = size - 1; i > 0; i--) tree[i] = max(tree[2 * i], tree[2 * i + 1]);
        int unplaced = 0;
        for (int f : fruits) {
            if (tree[1] < f) { unplaced++; continue; }
            int idx = 1;
            while (idx < size) {
                if (tree[2 * idx] >= f) idx = 2 * idx;
                else idx = 2 * idx + 1;
            }
            int pos = idx - size;
            int p = idx;
            tree[p] = 0;
            for (p /= 2; p >= 1; p /= 2) tree[p] = max(tree[2 * p], tree[2 * p + 1]);
        }
        return unplaced;
    }
};
