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

    void join(int x, int y) {
        int u = find(x);
        int v = find(y);
        if(u == v) return;

        if(rank[u] < rank[v]) {
            set[u] = v;
        }
        else {
            if(rank[u] == rank[v]) {
                rank[u]++;
            }
            set[v] = u;
        }
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<tuple<int, int, int>> edges;

        for(int i = 0; i < n; i++) {
            for(int j = 0;  j < n; j++) {
                if(i < n - 1)
                    edges.emplace_back(i * n + j, (i + 1) * n + j, max(grid[i][j], grid[i + 1][j]));
                if(j < n - 1)
                    edges.emplace_back(i * n + j, i * n + j + 1, max(grid[i][j], grid[i][j + 1]));
            }
        }

        sort(edges.begin(), edges.end(), [&](auto x, auto y) -> bool{
            return get<2>(x) < get<2>(y);
            });
        
        DisjointSet set(n * n);
        int ans = 0;
        for(auto &[v1, v2, weight] : edges) {
            set.join(v1, v2);
            if(set.find(0) == set.find(n * n - 1)) {
                ans = weight;
                break;
            }
        }

        return ans;
    }
};