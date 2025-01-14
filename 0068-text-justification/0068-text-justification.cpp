class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res, curr;
        int numLetters = 0;
        for (int i = 0; i < words.size(); ++i) {
            string w = words[i];
            if (numLetters + curr.size() + w.size() > maxWidth) {
                int spaces = maxWidth - numLetters;
                int gaps = curr.size() - 1;
                string line;
                if (gaps == 0) {
                    line = curr[0] + string(spaces, ' ');
                } else {
                    int spacePerGap = spaces / gaps;
                    int extraSpaces = spaces % gaps;
                    for (int j = 0; j < curr.size(); ++j) {
                        line += curr[j];
                        if (j < gaps) {
                            int spaceToAdd = spacePerGap + (j < extraSpaces ? 1 : 0);
                            line += string(spaceToAdd, ' ');
                        }
                    }
                }
                res.push_back(line);
                curr.clear();
                numLetters = 0;
            }
            curr.push_back(w);
            numLetters += w.size();
        }
        string lastLine;
        for (int i = 0; i < curr.size(); ++i) {
            lastLine += curr[i];
            if (i != curr.size() - 1) lastLine += ' ';
        }
        lastLine += string(maxWidth - lastLine.size(), ' ');
        res.push_back(lastLine);
        return res;
    }
};