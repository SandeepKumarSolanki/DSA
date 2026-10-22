class Solution {
public:
    bool isBipartite(int curr, unordered_map<int, vector<int>>& adj, vector<int>& color) {
        queue<int> que;
        que.push(curr);
        color[curr] = 1;
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            for(auto &v: adj[u]) {
                if(color[v] == color[u]) {
                    return false;
                } else if(color[v] == -1) {
                    que.push(v);
                    color[v] = 1 - color[u];
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> adj;
        vector<int>color(n+1, -1);
        for(auto &dislike: dislikes) {
            adj[dislike[1]].push_back(dislike[0]);
            adj[dislike[0]].push_back(dislike[1]);
        }
        for(int i = 1; i <= n; i++) {
            if(color[i] == -1) {
                if(isBipartite(i, adj, color) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};