class DisjointSet {
private:
    vector<int> set;
    vector<int> rank;

public:
    DisjointSet(int n): set(n), rank(n) {
        for (int i = 0; i < n; i++) {
            set[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        return x == set[x] ? x : set[x] = find(set[x]);
    }

    void join(int u, int v) {
        if(rank[v] > rank[u]) {
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

class Edge {
public:
    int v1, v2, weight;

    Edge(int _v1, int _v2, int _weight) {
        v1 = _v1;
        v2 = _v2;
        weight = _weight;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        auto dist = [&](int v1, int v2) -> int {return abs(points[v1][0] - points[v2][0]) + abs(points[v1][1] - points[v2][1]);};
        vector<Edge> edges;
        int len = points.size();
        for(int i = 0; i < len; i++) {
            for(int j = i + 1; j < len; j++) {
                edges.emplace_back(Edge(i, j, dist(i, j)));
            }
        }

        sort(edges.begin(), edges.end(), [](Edge x, Edge y) -> int {return x.weight < y.weight;});

        int res = 0;
        int accepted = 1;
        DisjointSet set(len);
        for(auto &[v1, v2, weight] : edges) {
            int u = set.find(v1), v = set.find(v2);
            if(u != v) {
                set.join(u, v);
                res += weight;
                accepted++;
                if(accepted == len) break;
            }
        }

        return res;
    }
};