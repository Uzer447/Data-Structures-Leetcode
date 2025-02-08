class Solution {
public:
    map<string, vector<int>> m;
    vector<bool> v;
    vector<string> w;

    void bucketInsert(string& s, int matches) {
        for (int i = 0; i < w.size(); ++i) {
            if (v[i]) continue;
            string mi, mc;
            for (int y = 0; y < s.size(); ++y) {
                if (s[y] == w[i][y]) {
                    mi += to_string(y);
                    mc += s[y];
                }
            }
            if (mi.size() == matches) {
                mi += mc;
                m[mi].push_back(i);
            } else {
                v[i] = true;
            }
        }
    }

    void cleanBucket() {
        for (auto it = m.begin(); it != m.end(); ) {
            auto key = it->first;
            auto &indices = it->second;
            for (int i = 0; i < indices.size(); ) {
                if (v[indices[i]]) {
                    swap(indices[i], indices.back());
                    indices.pop_back();
                } else {
                    ++i;
                }
            }
            if (indices.empty())
                it = m.erase(it);
            else
                ++it;
        }
    }

    void cleanBucket2(string k) {
        for (auto n : m[k])
            v[n] = true;
        m.erase(k);
    }

    void findSecretWord(vector<string>& words, Master& master) {
        w = words;
        v.resize(words.size(), false);

        while (true) {
            string selectedWord;
            int matches = 0, largest = 0, swi = -1;
            if (m.empty()) {
                for (int i = 0; i < v.size(); ++i) {
                    if (!v[i]) {
                        swi = i;
                        break;
                    }
                }
            } else {
                for (auto& [key, indices] : m) {
                    if (indices.size() > largest) {
                        largest = indices.size();
                        swi = indices[0];
                    }
                }
            }
            
            if (swi == -1) break;
            
            selectedWord = w[swi];
            matches = master.guess(selectedWord);
            if (matches == 6) return;
            v[swi] = true;
            bucketInsert(selectedWord, matches);
            cleanBucket();
        }
    }
};