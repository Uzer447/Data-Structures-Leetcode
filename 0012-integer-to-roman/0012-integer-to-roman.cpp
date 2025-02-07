class Solution {
public:
    string intToRoman(int num) {
        string thousand[]={"","M","MM","MMM"};
        string hundred []={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string twoDigit []={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
         string oneDigit []={"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string ans;
        ans+=thousand[num/1000]+hundred[(num%1000)/100]+twoDigit[((num%1000)%100)/10]+oneDigit[((num%1000)%100)%10];
        return ans;
    }
};