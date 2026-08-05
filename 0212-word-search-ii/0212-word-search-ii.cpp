class TrieNode {
public:
    TrieNode* child[26];
    string word;

    TrieNode() {
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
        word = "";
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();
    vector<string> ans;

    void insert(string word) {
        TrieNode* node = root;

        for (char c : word) {
            int idx = c - 'a';

            if (node->child[idx] == NULL)
                node->child[idx] = new TrieNode();

            node = node->child[idx];
        }

        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node) {
        char c = board[i][j];

        if (c == '#' || node->child[c - 'a'] == NULL)
            return;

        node = node->child[c - 'a'];

        if (node->word != "") {
            ans.push_back(node->word);
            node->word = "";     // avoid duplicates
        }

        board[i][j] = '#';

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni >= 0 && nj >= 0 &&
                ni < board.size() &&
                nj < board[0].size())
                dfs(board, ni, nj, node);
        }

        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        for (string word : words)
            insert(word);

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root);
            }
        }

        return ans;
    }
};