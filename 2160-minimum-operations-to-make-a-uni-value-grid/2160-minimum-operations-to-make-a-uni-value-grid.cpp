#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        for(auto &r : grid)
            for(auto &e : r)
                arr.push_back(e);
        int n = arr.size(), rem = arr[0] % x;
        for(auto &a : arr)
            if(a % x != rem)
                return -1;
        sort(arr.begin(), arr.end());
        int i = 0, j = n - 1;
        long long ops = 0;
        while(i < j){
            ops += (arr[j] - arr[i]) / x;
            i++;
            j--;
        }
        return ops;
    }
};