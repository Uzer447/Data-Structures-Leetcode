class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        vector<string> below_20{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", 
                                "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", 
                                "Eighteen", "Nineteen"};
        vector<string> tens{"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        vector<string> thousands{"", "Thousand", "Million", "Billion"};
        string result;
        int i = 0;
        while (num > 0) {
            int cur = num % 1000;
            if (cur != 0) {
                string segment = helper(cur, below_20, tens);
                if (!thousands[i].empty()) segment += " " + thousands[i];
                if (result.empty()) result = segment;
                else result = segment + " " + result;
            }
            num /= 1000;
            ++i;
        }
        return result;
    }

    string helper(int num, vector<string>& below_20, vector<string>& tens) {
        if (num == 0) return "";
        else if (num < 20) return below_20[num];
        else if (num < 100) {
            if (num % 10 == 0) return tens[num / 10];
            else return tens[num / 10] + " " + below_20[num % 10];
        } else {
            string res = below_20[num / 100] + " Hundred";
            if (num % 100 != 0) res += " " + helper(num % 100, below_20, tens);
            return res;
        }
    }
};