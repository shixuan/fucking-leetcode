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
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<tuple<int, int, int>> edges; //v1, v2, weight

        for(int i = 0; i < m ; i++) {
            for(int j = 0; j < n; j++) {
                if(i < m - 1)
                    edges.emplace_back(i * n + j, (i + 1) * n + j, abs(heights[i][j] - heights[i + 1][j]));
                if(j < n - 1)
                    edges.emplace_back(i * n + j, i * n + j + 1, abs(heights[i][j] - heights[i][j + 1]));
            }
        }

        sort(edges.begin(), edges.end(), [&](auto x, auto y) -> bool{
            return get<2>(x) < get<2>(y);
            });

        DisjointSet set(m * n);
        int ans = 0;
        for(auto &[v1, v2, weight] : edges) {
            set.join(v1, v2);
            if(set.find(0) == set.find(m * n - 1)) {
                ans = weight;
                break;
            }
        }

        return ans;
    }
};