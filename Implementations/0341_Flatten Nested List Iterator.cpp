/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> collections;
    int idx = 0;

    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
    }

    void dfs(vector<NestedInteger> &list) {
        for(auto &obj : list) {
            if(obj.isInteger())
                collections.push_back(obj.getInteger());
            else
                dfs(obj.getList());
        }
    }
    
    int next() {
        return collections[idx++];
    }
    
    bool hasNext() {
        return idx != collections.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */