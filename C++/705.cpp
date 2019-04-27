__________________________________________________________________________________________________
sample 72 ms submission
class MyHashSet 
{
public:
    /** Initialize your data structure here. */
    MyHashSet() 
    {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        data = vector<bool>(1000001, false);
    }
    
    void add(int key) 
    {
        data[key] = true;
    }
    
    void remove(int key) 
    {
        data[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) 
    {
        return data[key];
    }
private:
    vector<bool> data;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */
__________________________________________________________________________________________________
sample 35872 kb submission
class MyHashSet {
public:
    std::vector<int> set;
    /** Initialize your data structure here. */
    MyHashSet() {
        
    }
    
    void add(int key) {
        for(int i = 0,szi(set.size()) ; i < szi ; i++){
            if(set[i] == key) return;
        }
        set.push_back(key);
    }
    
    void remove(int key) {
        std::vector<int>::iterator it = std::find(set.begin(),set.end(),key);
        if(set.end() == it) return;
        set.erase(it);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        if(set.empty()) return false;
        std::vector<int>::iterator it = std::find(set.begin(),set.end(),key);
        return !(set.end() == it);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */
__________________________________________________________________________________________________
