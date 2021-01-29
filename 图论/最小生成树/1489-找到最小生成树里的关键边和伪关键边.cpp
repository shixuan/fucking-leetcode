//未优化，内存占用比较高

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
    int v1, v2, weight, idx;

    Edge(int _v1, int _v2, int _weight, int _idx) {
        v1 = _v1;
        v2 = _v2;
        weight = _weight;
        idx = _idx;
    }
};

class Solution {
public:
    int kruskal(vector<Edge> edges, int n) {
        int res = 0;
        int accepted = 0;
        int len = n - 1;
        DisjointSet set(n);
        for(auto &[v1, v2, weight, idx] : edges) {
            int u = set.find(v1), v = set.find(v2);
            if(u != v) {
                set.join(u, v);
                res += weight;
                accepted++;
                if(accepted == len) break;
            }
        }
        if(accepted != len) 
            return -1;
        return res;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<Edge> e;
        int size = edges.size();
        for(int i = 0; i < size; i++) {
            e.emplace_back(Edge(edges[i][0], edges[i][1], edges[i][2], i));
        }
        sort(e.begin(), e.end(), [](Edge x, Edge y) -> int {return x.weight < y.weight;});
        int w = kruskal(e, n);  //原始mst的总权重

        vector<int> critical, noncritical; //两个结果集，关键边和伪边
        for(int i = 0; i < size; i++) {
            vector<Edge> cri_test, noncri_test;
            for(int j = 0; j < size; j++) { //复制边集合，跳过要删除的边
                if(e[j].idx == i) { //排序后顺序混乱，以idx值来判断第几条边
                    noncri_test.emplace_back(e[j]); //为了方便后续判断伪变，把要删除的边放在第一个
                    continue;
                }
                cri_test.emplace_back(e[j]);
            }
            int cri_res = kruskal(cri_test, n); //删边之后的权重
            if(cri_res > w || cri_res == -1)    //若权重变大或者图不连通，边为关键边
                critical.emplace_back(i);
            else {  //否则，把要删除的边挑选上，判断生成的mst的权重是否与原来的一致。若一致，则为伪边，否则，什么边都不是。
                noncri_test.insert(noncri_test.end(), cri_test.begin(), cri_test.end());
                int non_res = kruskal(noncri_test, n);
                if(non_res == w)
                    noncritical.emplace_back(i);
            }
        }

        vector<vector<int>> ans;
        ans.emplace_back(critical);
        ans.emplace_back(noncritical);
        return ans;
    }
};