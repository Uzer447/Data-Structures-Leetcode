class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        result.reserve(n);
        int num = 1;
        while(size(result) < n){
            result.push_back(num);
            if(num*10 <= n){
                num = num*10;
            }
            else{
                while (num % 10 == 9 || num == n)
                    num/=10;
                num++;
            }
            
        }
        return result;
        }

};