/*
    同样能用来解决705
*/
class MyHashMap {
public:
    int base = 769;
    vector<list<pair<int, int>>> tb;

    /** Initialize your data structure here. */
    MyHashMap(): tb(base){

    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int idx = key % base;
        for(auto it = tb[idx].begin(); it != tb[idx].end(); it++) {
            if(it->first == key) {
                it->second = value;
                return;
            }
        }
        tb[idx].push_back(make_pair(key, value));
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int idx = key % base;
        for(auto it = tb[idx].begin(); it != tb[idx].end(); it++) {
            if(it->first == key) {
                return it->second;
            }
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int idx = key % base;
        for(auto it = tb[idx].begin(); it != tb[idx].end(); it++) {
            if(it->first == key) {
                tb[idx].erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */