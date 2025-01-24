class Solution {
    vector<string> result;
    string num;
    int target;

public:
    vector<string> addOperators(string num, int target) {
        this->num = num;
        this->target = target;
        dfs(0, "", 0, 0);
        return result;
    }
    void dfs(int index, string expr, long long res_so_far,
             long long last_operand) {
        if (index == num.size()) {
            if (res_so_far == target)
                result.push_back(expr);
            return;
        }
        for (int i = index; i < num.size(); ++i) {
            if (i != index && num[index] == '0')
                break;
            string curr_num_str = num.substr(index, i - index + 1);
            long long curr_num = stoll(curr_num_str);
            if (index == 0) {
                dfs(i + 1, expr + curr_num_str, curr_num, curr_num);
            } else {
                dfs(i + 1, expr + '+' + curr_num_str, res_so_far + curr_num,
                    curr_num);
                dfs(i + 1, expr + '-' + curr_num_str, res_so_far - curr_num,
                    -curr_num);
                dfs(i + 1, expr + '*' + curr_num_str,
                    res_so_far - last_operand + last_operand * curr_num,
                    last_operand * curr_num);
            }
        }
    }
};