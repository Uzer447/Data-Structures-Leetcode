class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    string word;
    TrieNode() : word("") {}
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = buildTrie(words);
        vector<string> result;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                dfs(board, i, j, root, result, visited);
        return result;
    }
    
private:
    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(string& word : words) {
            TrieNode* node = root;
            for(char c : word) {
                if(!node->children.count(c))
                    node->children[c] = new TrieNode();
                node = node->children[c];
            }
            node->word = word;
        }
        return root;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& result, vector<vector<bool>>& visited) {
        char c = board[i][j];
        if(!node->children.count(c) || visited[i][j]) return;
        node = node->children[c];
        if(node->word != "") {
            result.push_back(node->word);
            node->word = "";
        }
        visited[i][j] = true;
        int m = board.size(), n = board[0].size();
        if(i > 0) dfs(board, i - 1, j, node, result, visited);
        if(j > 0) dfs(board, i, j - 1, node, result, visited);
        if(i < m - 1) dfs(board, i + 1, j, node, result, visited);
        if(j < n - 1) dfs(board, i, j + 1, node, result, visited);
        visited[i][j] = false;
        if(node->children.empty())
            node->children.erase(c);
    }
};