class Solution {
public:
    string DecimalToBinary(int num) {
        string str;
        while (num) {
            if (num & 1)
                str += '1';
            else
                str += '0';
            num >>= 1;
        }
        reverse(str.begin(),str.end());
        return str;
    }
    int binaryToDecimal(string n) {
        string num = n;
        int dec_value = 0;
        int base = 1;

        int len = num.length();
        for (int i = len - 1; i >= 0; i--) {
            if (num[i] == '1')
                dec_value += base;
            base = base * 2;
        }

        return dec_value;
    }
    int maxGoodNumber(vector<int>& nums) {
        string a = DecimalToBinary(nums[0]);
        string b = DecimalToBinary(nums[1]);
        string c = DecimalToBinary(nums[2]);
        string temp = a + b + c;
        int ans=0;
        ans=max(ans,binaryToDecimal(temp));
        temp=a+c+b;
        ans=max(ans,binaryToDecimal(temp));
        temp=b+a+c;
        ans=max(ans,binaryToDecimal(temp));
        temp=b+c+a;
        ans=max(ans,binaryToDecimal(temp));
        temp=c+a+b;
        ans=max(ans,binaryToDecimal(temp));
        temp=c+b+a;
        ans=max(ans,binaryToDecimal(temp));
        return ans;
    }
};