class Solution {
public:
    bool isValid(string code) {
        int n = code.length(), pos = 0;
        vector<string> stack;
        if (code.empty() || code[0] != '<') return false;
        while (pos < n) {
            if (pos + 9 <= n && code.compare(pos, 9, "<![CDATA[") == 0) {
                if (stack.empty()) return false;
                int end_cdata = code.find("]]>", pos + 9);
                if (end_cdata == string::npos) return false;
                pos = end_cdata + 3;
            } else if (pos + 2 <= n && code.compare(pos, 2, "</") == 0) {
                int end_tag_pos = code.find('>', pos + 2);
                if (end_tag_pos == string::npos) return false;
                int len = end_tag_pos - (pos + 2);
                if (len < 1 || len > 9) return false;
                for (int i = pos + 2; i < end_tag_pos; ++i)
                    if (!isupper(code[i])) return false;
                string tagname = code.substr(pos + 2, len);
                if (stack.empty() || stack.back() != tagname) return false;
                stack.pop_back();
                pos = end_tag_pos + 1;
                if (stack.empty() && pos != n) return false;
            } else if (code[pos] == '<') {
                int end_tag_pos = code.find('>', pos + 1);
                if (end_tag_pos == string::npos) return false;
                int len = end_tag_pos - (pos + 1);
                if (len < 1 || len > 9) return false;
                for (int i = pos + 1; i < end_tag_pos; ++i)
                    if (!isupper(code[i])) return false;
                string tagname = code.substr(pos + 1, len);
                stack.push_back(tagname);
                pos = end_tag_pos + 1;
            } else {
                if (stack.empty()) return false;
                ++pos;
            }
        }
        return stack.empty();
    }
};