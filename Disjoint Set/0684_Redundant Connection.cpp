class DisjointSet {
private:
    vector<int> set;
    vector<int> rank;
public:
    DisjointSet(int n): set(n), rank(n) {
        for(int i = 0; i < n; i++) {
            set[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        return x == set[x] ? x : set[x] = find(set[x]);
    }

    bool join(int x, int y) {
        int u = find(x);
        int v = find(y);
        if(u == v) return false;

        if(rank[u] < rank[v]) {
            set[u] = v;
        }
        else {
            if(rank[u] == rank[v]) {
                rank[u]++;
            }
            set[v] = u;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> ans;
        DisjointSet set(edges.size() + 1);

        for(auto edge : edges) {
            if(!set.join(edge[0], edge[1]))
                ans = {edge[0], edge[1]};
        }

        return ans;
    }
};