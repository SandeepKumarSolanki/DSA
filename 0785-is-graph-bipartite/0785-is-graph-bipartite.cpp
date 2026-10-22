class Solution {
public:
    bool isBipartitePossible(int curr, vector<vector<int>>& graph, vector<int>& color, int currColor) {
        color[curr] = currColor;
        for(auto &v: graph[curr]) {
            if(color[v] != -1 && color[v] == color[curr]) {
                return false;
            } else if(color[v] == -1) {
                color[v] = 1 - color[curr];
                if(isBipartitePossible(v, graph, color, color[v]) == false) {
                    return false;
                }
            }
            
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int>color(N, -1);
        for(int i = 0; i < N; i++) {
            if(color[i] == -1) {
                if(isBipartitePossible(i, graph, color, 1) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};