class DisjointSet {
private:
    vector<int> set;
    vector<int> rank;
    int setCount;

public:
    DisjointSet(int n): set(n), rank(n), setCount(n) {
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
        setCount--;
    }

    int count() {
        return setCount;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet set(n);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] && i != j)
                    set.join(i, j);
            }
        }

        return set.count();
    }
};