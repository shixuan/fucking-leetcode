class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        vector<int> visited(graph.size());
        for(int i = 0; i < graph.size(); i++) {
            if(dfs(graph, i, visited)) {
                ans.push_back(i);
                visited[i] = 2;
            }
        }
        return ans;
    }

    bool dfs(vector<vector<int>>& graph, int idx, vector<int> &visited) {
        if(visited[idx] == 1)    return false;
        if(visited[idx] == 2)    return true;
        visited[idx] = 1;

        for(int n : graph[idx]) {
            if(!dfs(graph, n, visited))
               return false;
            else
                visited[n] = 2;
        }

        return true;
    }
};