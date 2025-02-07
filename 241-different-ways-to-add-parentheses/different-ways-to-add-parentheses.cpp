class Solution {
public:
    vector<int> Calculate(const string& expr) {

        vector<int> result;

        if (all_of(expr.begin(), expr.end(), ::isdigit)) {
            result.push_back(stoi(expr));
            return result;
        }

        for (int i = 0; i < expr.size(); i++) {
            char c = expr[i];

            if (c == '+' || c == '-' || c == '*') {

                string left = expr.substr(0, i);
                string right = expr.substr(i + 1);

                vector<int> leftResults = Calculate(left);
                vector<int> rightResults = Calculate(right);

                for (int l : leftResults) {
                    for (int r : rightResults) {
                        if (c == '+')
                            result.push_back(l + r);
                        else if (c == '-')
                            result.push_back(l - r);
                        else if (c == '*')
                            result.push_back(l * r);
                    }
                }
            }
        }
        return result;
    }

    vector<int> diffWaysToCompute(string expression) {
        return Calculate(expression);
    }
};