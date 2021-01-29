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
        setNum--;
        return true;
    }

    int count() {
        return setNum;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int ans = 0;
        DisjointSet alice(n), bob(n);

        for(auto &edge : edges) {
            if(edge[0] == 3) {
                if(!alice.join(edge[1] - 1, edge[2] - 1)) {
                    ans++;
                    continue;
                }
                bob.join(edge[1] - 1, edge[2] - 1);
            }
        }

        for(auto &edge : edges) {
            if(edge[0] == 1) {
                if(!alice.join(edge[1] - 1, edge[2] - 1))
                    ans++;
            }
            else if(edge[0] == 2) {
                if(!bob.join(edge[1] - 1, edge[2] - 1))
                    ans++;
            }
        }

        if(alice.count() != 1 || bob.count() != 1)
            return -1;
        
        return ans;
    }
};