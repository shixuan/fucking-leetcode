class DisjointSet {
private:
    int set[20000];

public:
    DisjointSet() {
        for (int i = 0; i < 20000; i++) {
            set[i] = -1;
        }
    }

    int find(int x) {
        if (set[x] == -1)
            set[x] = x;
        return x == set[x] ? x : set[x] = find(set[x]);
    }

    void join(int x, int y) {
        int u = find(x);
        int v = find(y);
        if (u != v)
            set[u] = v;
    }

    int getNumOfSets() {
        int num = 0;
        for (int i = 0; i < 20000; i++) {
            if (set[i] == i)
                num++;
        }

        return num;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DisjointSet set;

        for (int i = 0; i < n; i++)
            set.join(stones[i][0], stones[i][1] + 10000);

        return n - set.getNumOfSets();
    }
};