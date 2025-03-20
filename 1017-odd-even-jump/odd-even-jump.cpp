#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<int> next_higher(n, -1), next_lower(n, -1);
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int i, int j){
            if(arr[i] == arr[j]) return i < j;
            return arr[i] < arr[j];
        });
        vector<int> st;
        for (int i : idx) {
            while (!st.empty() && i > st.back()){
                next_higher[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }
        sort(idx.begin(), idx.end(), [&](int i, int j){
            if(arr[i] == arr[j]) return i < j;
            return arr[i] > arr[j];
        });
        st.clear();
        for (int i : idx) {
            while (!st.empty() && i > st.back()){
                next_lower[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }
        vector<bool> dp_odd(n, false), dp_even(n, false);
        dp_odd[n-1] = true; dp_even[n-1] = true;
        for (int i = n - 2; i >= 0; i--){
            if (next_higher[i] != -1) dp_odd[i] = dp_even[next_higher[i]];
            if (next_lower[i] != -1) dp_even[i] = dp_odd[next_lower[i]];
        }
        int ans = 0;
        for (bool b : dp_odd) ans += b;
        return ans;
    }
};