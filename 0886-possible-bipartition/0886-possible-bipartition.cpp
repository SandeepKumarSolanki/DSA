class Solution {
public:
    bool isPossibleBipartite(int curr, unordered_map<int, vector<int>>& adj, vector<int>& color, int currColor) {
        color[curr] = currColor;
        for(auto &v: adj[curr]) {
            if(color[v] != -1 && color[v] == color[curr]) {
                return false;
            } else if(color[v] == -1) {
                color[v] = 1 - color[curr];
                if(isPossibleBipartite(v, adj, color, color[v]) == false) {
                    return false;
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>color(n+1, -1);
        unordered_map<int, vector<int>> adj;
        for(auto dislike: dislikes) {
            adj[dislike[1]].push_back(dislike[0]);
            adj[dislike[0]].push_back(dislike[1]);
        }

        for(int i = 0; i < n; i++) {
            if(color[i] == -1) {
                if(isPossibleBipartite(i, adj, color, 1) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};