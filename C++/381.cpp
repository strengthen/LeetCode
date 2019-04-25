__________________________________________________________________________________________________
sample 48 ms submission
class RandomizedCollection {
    default_random_engine seed;
    vector<int> v;  // Vector for O(1) random.
    unordered_map<int, unordered_set<int>> mp;  // Set for O(1) remove.
public:
    /** Initialize your data structure here. */
    RandomizedCollection() : seed(random_device()()) {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        mp[val].emplace(v.size());  // O(1)
        v.emplace_back(val);        // O(1)
        return mp[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto it = mp.find(val);  
        if (it == mp.end()) return false;
        
        int i = *it->second.begin(); 
        if (val == v.back()) {
            i = v.size() - 1;
        } else {
            // Moves back val to target index.
            v[i] = v.back();
            
            // Updates mp to reflect move.
            mp[v.back()].erase(v.size() - 1);
            mp[v.back()].emplace(i);
        }
        
        // Removes target index and/or target entry.
        if (it->second.size() == 1) {
            mp.erase(it);
        } else {
            it->second.erase(i);
        }
        v.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int index = uniform_int_distribution<int>{0, v.size() - 1}(seed);
        return v[index];
    }
};
static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
__________________________________________________________________________________________________
sample 22420 kb submission
class RandomizedCollection {
public:
    unordered_multiset<int> m_v;
    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand(time(nullptr));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto it = m_v.find(val);
        m_v.insert(val);
        return it != m_v.end();
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = m_v.find(val);
        if (it != m_v.end())
        {
            m_v.erase(it);
            return true;
        }
        return false; 
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if (m_v.empty())
            return -1;
        
        auto it = m_v.begin();
        advance(it, rand() % m_v.size());
        return *it;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
__________________________________________________________________________________________________
