class DisjointSet {
private:
    vector<int> set;
    vector<int> rank;
    int setNum;

public:
    DisjointSet(int n): set(n), rank(n), setNum(n) {
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
        setNum--;
    }

    int count() {
        return setNum;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int len = connections.size();

        if(len < n - 1) return -1;  //连通所有节点最少需要n-1条边

        DisjointSet set(n);
        for(auto &connection : connections) {
            set.join(connection[0], connection[1]);
        }

        return set.count() - 1;
    }
};