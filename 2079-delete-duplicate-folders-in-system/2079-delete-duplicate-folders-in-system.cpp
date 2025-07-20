class Solution {
    struct Node {
        string name;
        unordered_map<string, Node*> ch;
        string sig;
        bool dup = false;
        Node(const string& s = "") : name(s) {}
    };
    Node* root = new Node;
    unordered_map<string, int> cnt;

    string dfsSig(Node* u) {
        if (u->ch.empty()) {
            u->sig = "";
            ++cnt[u->sig];
            return u->sig;
        }
        vector<pair<string, string>> v;
        for (auto& [k, nx] : u->ch) v.push_back({k, dfsSig(nx)});
        sort(v.begin(), v.end());
        string s;
        for (auto& [nm, sub] : v) {
            s.push_back('(');
            s += nm;
            s.push_back('|');
            s += sub;
            s.push_back(')');
        }
        u->sig = s;
        ++cnt[s];
        return s;
    }

    void mark(Node* u) {
        if (u != root && !u->ch.empty() && cnt[u->sig] > 1) u->dup = true;
        for (auto& [_, nx] : u->ch) mark(nx);
    }

    void collect(Node* u, vector<string>& cur, vector<vector<string>>& res) {
        if (u->dup) return;
        if (u != root) res.push_back(cur);
        for (auto& [nm, nx] : u->ch) {
            cur.push_back(nm);
            collect(nx, cur, res);
            cur.pop_back();
        }
    }

public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        for (auto& p : paths) {
            Node* cur = root;
            for (auto& s : p) {
                if (!cur->ch.count(s)) cur->ch[s] = new Node(s);
                cur = cur->ch[s];
            }
        }
        dfsSig(root);
        mark(root);
        vector<vector<string>> ans;
        vector<string> cur;
        collect(root, cur, ans);
        return ans;
    }
};