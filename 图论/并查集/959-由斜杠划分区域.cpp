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
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        DisjointSet set(n * n * 4);

        //单元格内下标顺序：逆时针0，1，2，3
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int idx = (i * n + j) * 4;
                char c = grid[i][j];

                if(c == ' ') {      //空格，join 0和1，2和3，0和2
                    set.join(idx, idx + 1);
                    set.join(idx + 2, idx + 3);
                    set.join(idx, idx + 2);
                }
                else if(c == '/') {     //左斜杠，join 0和1，2和3
                    set.join(idx, idx + 1);
                    set.join(idx + 2, idx + 3);
                }
                else if(c == '\\') {    //右斜杠，join 0和2，1和3
                    set.join(idx, idx + 3);
                    set.join(idx + 1, idx + 2);
                }

                // join当前单元格的3和右边单元格的1
                if(j + 1 < n) {
                    set.join(idx + 3, (i * n + j + 1) * 4 + 1);
                }
                // join当前单元格的2和下边单元格的0
                if(i + 1 < n) {
                    set.join(idx + 2, ((i + 1) * n + j) * 4);
                }
            }
        }

        return set.count();
    }
};