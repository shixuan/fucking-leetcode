class MyHashSet {
public:
    int tb[40000] = { 0 };  //0 <= key <= 10^6

    /** Initialize your data structure here. */
    MyHashSet() {

    }
    
    void add(int key) {
        int bucketIdx = key / 32;
        int bitIdx = key % 32;
        tb[bucketIdx] |= (1 << bitIdx);
    }
    
    void remove(int key) {
        int bucketIdx = key / 32;
        int bitIdx = key % 32;
        tb[bucketIdx] &= ~(1 << bitIdx);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int bucketIdx = key / 32;
        int bitIdx = key % 32;
        return (tb[bucketIdx] >> bitIdx) & 1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */