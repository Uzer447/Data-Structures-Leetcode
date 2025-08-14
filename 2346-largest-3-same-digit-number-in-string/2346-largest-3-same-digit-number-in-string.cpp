class Solution {
public:
    string largestGoodInteger(string num) {
        int left = 0;
        int temp = INT_MIN;
        string ans = "";
        int right = 0;
        string res="";
        while (right < num.size()) {
            if (right - left + 1 >= 3) {
                if (num[left] == num[left + 1] &&
                    num[left + 1] == num[left + 2]) {
                    ans = ans + num[left] + num[left + 1] + num[left + 2];
                    cout<<ans<<endl;
                    if(stoi(ans)>temp)
                    {
                        temp = max(temp, stoi(ans));
                        res = ans;
                    }
                    ans="";
                }
                left++;
            }
            right++;
        }
        return res;
    }
};