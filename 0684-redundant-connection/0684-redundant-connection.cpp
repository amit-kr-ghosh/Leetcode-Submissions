class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            return find(parent[x]);
        return x;
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        parent[px] = py;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) parent[i] = i;

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            if (find(u) == find(v)) return e;
            unite(u, v);
        }
        return {};
    }
};