class Solution {
public:
    vector<string> basicCalculatorIV(string expr, vector<string>& variables,
                                     vector<int>& values) {
        unordered_map<string, int> valueMap;
        int n = variables.size();
        for (int i = 0; i < n; ++i)
            valueMap[variables[i]] = values[i];

        int idx = 0;
        unordered_map<string, int> resultMap =
            evaluateExpression(expr, valueMap, idx);
        vector<pair<string, int>> resultList(resultMap.begin(),
                                             resultMap.end());

        sort(resultList.begin(), resultList.end(), compareByDegree);

        vector<string> finalResult;
        for (auto& entry : resultList) {
            if (entry.second == 0)
                continue;
            finalResult.push_back(to_string(entry.second));
            if (!entry.first.empty())
                finalResult.back() += "*" + entry.first;
        }

        return finalResult;
    }

private:
    unordered_map<string, int>
    evaluateExpression(string& expression, unordered_map<string, int>& valueMap,
                       int& idx) {
        vector<unordered_map<string, int>> operands;
        vector<char> operators = {'+'};
        int len = expression.size();

        while (idx < len && expression[idx] != ')') {
            if (expression[idx] == '(') {
                idx++;
                operands.push_back(
                    evaluateExpression(expression, valueMap, idx));
            } else {
                int start = idx;
                while (idx < len && expression[idx] != ' ' &&
                       expression[idx] != ')')
                    idx++;
                string token = expression.substr(start, idx - start);
                bool isNumber = true;

                for (char c : token) {
                    if (!isdigit(c)) {
                        isNumber = false;
                        break;
                    }
                }

                unordered_map<string, int> temp;
                if (isNumber) {
                    temp[""] = stoi(token);
                } else if (valueMap.count(token)) {
                    temp[""] = valueMap[token];
                } else {
                    temp[token] = 1;
                }
                operands.push_back(temp);
            }

            if (idx < len && expression[idx] == ' ') {
                operators.push_back(expression[++idx]);
                idx += 2;
            }
        }
        idx++;

        return combineOperands(operands, operators);
    }

    unordered_map<string, int>
    combineOperands(vector<unordered_map<string, int>>& operands,
                    vector<char>& operators) {
        unordered_map<string, int> result;
        int numOps = operators.size();

        for (int i = numOps - 1; i >= 0; --i) {
            unordered_map<string, int> temp = operands[i];
            while (i >= 0 && operators[i] == '*') {
                temp = multiplyOperands(temp, operands[--i]);
            }
            int sign = operators[i] == '+' ? 1 : -1;
            for (auto& p : temp)
                result[p.first] += sign * p.second;
        }

        return result;
    }

    unordered_map<string, int>
    multiplyOperands(unordered_map<string, int>& left,
                     unordered_map<string, int>& right) {
        unordered_map<string, int> result;
        for (auto& leftPair : left) {
            for (auto& rightPair : right) {
                string combined =
                    combineStrings(leftPair.first, rightPair.first);
                result[combined] += leftPair.second * rightPair.second;
            }
        }
        return result;
    }

    string combineStrings(const string& a, const string& b) {
        if (a.empty())
            return b;
        if (b.empty())
            return a;

        vector<string> leftTokens = splitString(a, '*');
        vector<string> rightTokens = splitString(b, '*');

        for (auto& s : rightTokens)
            leftTokens.push_back(s);
        sort(leftTokens.begin(), leftTokens.end());

        string combinedStr;
        for (auto& token : leftTokens)
            combinedStr += token + '*';
        combinedStr.pop_back();

        return combinedStr;
    }

    static vector<string> splitString(const string& s, char delimiter) {
        vector<string> parts;
        int start = 0, len = s.size();

        while (start < len) {
            int end = s.find(delimiter, start);
            if (end == string::npos)
                end = len;
            parts.push_back(s.substr(start, end - start));
            start = end + 1;
        }

        return parts;
    }

    static bool compareByDegree(pair<string, int>& a, pair<string, int>& b) {
        string left = a.first, right = b.first;
        vector<string> leftTokens = splitString(left, '*');
        vector<string> rightTokens = splitString(right, '*');

        return leftTokens.size() > rightTokens.size() ||
               (leftTokens.size() == rightTokens.size() &&
                leftTokens < rightTokens);
    }
};