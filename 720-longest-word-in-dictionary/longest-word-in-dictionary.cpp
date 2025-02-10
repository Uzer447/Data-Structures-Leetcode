class Node {
public:
    vector<Node *> child;
    bool isEnd;
public:
    Node()
    {
        this->isEnd = false;
        this->child = vector<Node *> (26, nullptr);
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) 
    {
        sort(words.begin(), words.end());
        Node *root = new Node();
        root->isEnd = true;
        string res = "";
        for (auto &w : words)
        {
            if (add(root, w))
            {
                if (w.size() > res.size() || (w.size() == res.size() && w < res)) res = w;
            }
        }
        return res;
    }
private:
    bool add(Node *node, string &s)
    {
        for (auto &c:s)
        {
            int cur = c-'a';
            if (node->child[cur] == nullptr) 
            {
                if (!node->isEnd) return 0;
                node->child[cur] = new Node();
            }
            node = node->child[cur];
        }
        node->isEnd = true;
        return 1;
    }
};