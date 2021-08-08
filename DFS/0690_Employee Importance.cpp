/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int, Employee*> map;

    int getImportance(vector<Employee*> employees, int id) {
        for(auto &e : employees)
            map[e->id] = e;
        return dfs(id);
    }

    int dfs(int id) {
        int total = map[id]->importance;
        for(int i : map[id]->subordinates)
            total += dfs(i);
        return total;
    }
};