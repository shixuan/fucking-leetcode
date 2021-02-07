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

    void join(int x, int y) {
        int u = find(x);
        int v = find(y);
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

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> res;
        unordered_map<string, int> addrToIdx;
        unordered_map<int, vector<string>> idxToAddrList;
        int len = accounts.size();
        DisjointSet set(len);
        for(int i = 0; i < len; i++) {
            int size = accounts[i].size();
            for(int j = 0; j < size; j++) {
                string addr = accounts[i][j];
                if(addrToIdx.find(addr) == addrToIdx.end()) {
                    addrToIdx[addr] = i;
                }
                else {
                    set.join(i, addrToIdx[addr]);
                }
            }
        }

        for(auto &[name, idx] : addrToIdx) {
            idxToAddrList[set.find(idx)].emplace_back(name);
        }

        for(auto &[idx, list] : idxToAddrList) {
            sort(list.begin(), list.end());
            vector<string> tmp(1, accounts[idx][0]); //加上名字
            tmp.insert(tmp.end(), list.begin(), list.end());
            res.emplace_back(tmp);
        }

        return res;
    }
};