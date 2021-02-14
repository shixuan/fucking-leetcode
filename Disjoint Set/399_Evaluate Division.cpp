class DisjointSet {
private:
    vector<int> set;
    vector<double> weight;

public:
    DisjointSet(int n): set(n), weight(n) {
        for(int i = 0; i < n; i++) {
            set[i] = i;
            weight[i] = 1;
        }
    }

    int find(int x) {
        if(x != set[x]) {
            int tmp = set[x];
            set[x] = find(set[x]);
            weight[x] *= weight[tmp];
        }
        return set[x];
    }

    void join(int x, int y, double value) {
        int u = find(x);
        int v = find(y);
        if(u == v) return;

        set[u] = v;
        weight[u] = weight[y] * value / weight[x];  // x/y=value, x/u=w[x], y/v=w[y] -> w[u]*w[x] = value*w[y]
    }

    double calWeight(int x, int y) {
        int u = find(x), v = find(y);
        if(u == v)
            return weight[x] / weight[y];
        else
            return -1;
    }
};

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> vars;
        int n = equations.size(), idx = 0;;
        DisjointSet set(2 * n);

        for (int i = 0; i < n; i++) {
            if (vars.find(equations[i][0]) == vars.end()) {
                vars[equations[i][0]] = idx++;
            }
            if (vars.find(equations[i][1]) == vars.end()) {
                vars[equations[i][1]] = idx++;
            }

            set.join(vars[equations[i][0]], vars[equations[i][1]], values[i]);
        }

        vector<double> ans;
        for (const auto& q: queries) {
            double result = -1.0;
            if (vars.find(q[0]) != vars.end() && vars.find(q[1]) != vars.end()) {
                result = set.calWeight(vars[q[0]], vars[q[1]]);
            }
            ans.push_back(result);
        }
        return ans;
    }
};