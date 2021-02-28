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
    int numSimilarGroups(vector<string>& strs) {
        int size = strs.size(), len = strs[0].size();
        DisjointSet set(size);

        for(int i = 0; i < size; i++) {
            for(int j = i + 1; j < size; j++) {
                if(set.find(i) == set.find(j)) continue;

                int count = 0;
                for(int k = 0; k < len; k++) {
                    if(strs[i][k] != strs[j][k]) count++;
                    if(count > 2) break;
                }
                if(count == 2 || count == 0)
                    set.join(i, j);
            }
        }

        return set.count();
    }
};