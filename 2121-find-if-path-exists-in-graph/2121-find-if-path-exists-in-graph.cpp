class Solution {
public:


    
    bool dfs(int node, int dest,vector<vector<int>>& adj, vector<int>& vis) {
        if (node ==dest) 
        return true;
        vis[node] = 1;
        for (int nxt:adj[node]) {
            if (!vis[nxt]) {
            if (dfs(nxt,dest,adj,vis)) 
            return true;
            }
        }
        return false;
    }


    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for (auto &e:edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n,0);

        return dfs(source,destination,adj,vis);
        
    }
};





















