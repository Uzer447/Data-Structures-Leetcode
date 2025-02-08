class Solution {
public:
    string countOfAtoms(string formula) {
        int n = formula.size();
        int i = 0;
        stack<map<string, int>> stk;
        stk.push(map<string, int>());
        while (i < n) {
            if (formula[i] == '(') {
                stk.push(map<string, int>());
                i++;
            } else if (formula[i] == ')') {
                i++;
                int start = i;
                while (i < n && isdigit(formula[i])) i++;
                int multiplier = start < i ? stoi(formula.substr(start, i - start)) : 1;
                auto top = stk.top(); stk.pop();
                for (auto& p : top)
                    stk.top()[p.first] += p.second * multiplier;
            } else {
                int start = i;
                if (isupper(formula[i])) {
                    i++;
                    while (i < n && islower(formula[i])) i++;
                    string elem = formula.substr(start, i - start);
                    start = i;
                    while (i < n && isdigit(formula[i])) i++;
                    int count = start < i ? stoi(formula.substr(start, i - start)) : 1;
                    stk.top()[elem] += count;
                }
            }
        }
        auto counts = stk.top();
        string res;
        for (auto& p : counts)
            res += p.first + (p.second > 1 ? to_string(p.second) : "");
        return res;
    }
};