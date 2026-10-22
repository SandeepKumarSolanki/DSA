class Solution {
public:
    bool isBipartitePossible(int curr, vector<vector<int>>& graph, vector<int>& color) {
        queue<int> que;
        que.push(curr);
        color[curr] = 1;
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            for(auto v: graph[u]) {
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
    bool isBipartite(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int>color(N+1, -1);
        for(int i = 0; i < N; i++) {
            if(color[i] == -1) {
                if(isBipartitePossible(i, graph, color) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};