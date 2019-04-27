__________________________________________________________________________________________________
sample 96 ms submission
auto speedup =[]()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class MyHashMap 
{    
    static constexpr int BUCKET_COUNT = 101;        
    
    class node_t 
    {
        // disable copy because of the next pointer
        node_t(const node_t&) = delete;
        node_t& operator=(const node_t&) = delete;
        
    public:
        const int   key;
        int         value;
        node_t*     next;        
        
        // default ctor so we can use vector<node_t>
        node_t() : key(-1), value(-1), next(nullptr) {}
        
        // ctor for inserting keys
        node_t(int key, int value, node_t* next) : key(key), value(value), next(next) {}        
        
        ~node_t() { delete next; }
    };
    
    vector<node_t*> _bucket;
    
    static inline int bidx(int key)
    {
        hash<int> h;
        return h(key) % BUCKET_COUNT;
    }
    
public:
    MyHashMap() : _bucket(BUCKET_COUNT, nullptr) {}    
    ~MyHashMap() {}
    
    void put(int key, int value) 
    {   
        const int idx = bidx(key);
        node_t *cur = _bucket[idx];
        while (cur && cur->key != key) 
            cur = cur->next;
        if (cur) 
            cur->value = value;
        else
            _bucket[idx] = new node_t(key, value, _bucket[idx]);
    }
    
    int get(int key)
    {
        node_t* cur = _bucket[bidx(key)];
        while (cur && cur->key != key)
            cur = cur->next;
        return cur ? cur->value : -1;
    }
    
    void remove(int key) 
    {
        const int idx = bidx(key);
        node_t* cur = _bucket[idx];
        node_t* prev = nullptr;
        while (cur && cur->key != key) {
            prev = cur;
            cur = cur->next;
        }
        if (cur) {
            (prev ? prev->next : _bucket[idx]) = cur->next;
            cur->next = nullptr;
            delete cur;
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
__________________________________________________________________________________________________
sample 41032 kb submission
class MyHashMap {
public:
    /** Initialize your data structure here. */
    vector<pair<int,int>> hash;
    MyHashMap() {
        
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        int flag = 0;
        for(int i=0; i<hash.size(); i++){
            if(hash[i].first==key){
                flag = 1;
                hash[i].second = value;
                break;
            }
        }        
        if(flag==0)
            hash.push_back({key, value});
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        for(int i=0; i<hash.size(); i++){
            if(hash[i].first==key){
                return hash[i].second;
            }
        }        
        return -1;  
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        for(int i=0; i<hash.size(); i++){
            if(hash[i].first==key){
                hash.erase(hash.begin()+i);
                break;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */
__________________________________________________________________________________________________
