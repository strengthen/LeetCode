__________________________________________________________________________________________________
sample 100 ms submission
class LFUCache {
private:
    typedef pair<int, int> P;
    typedef list<P> L;
    typedef L::iterator I;
    typedef unordered_map<int, L> C2L;
    typedef unordered_map<int, I> K2I;
    typedef unordered_map<int, int> K2C;
    C2L countToEntryList;
    K2I keyToIter;
    K2C keyToCount;
    int maxSize, minCount = 0;
public:
    /* time: O(1), space: O(1) auxiliary (i.e. does not count cache capacity itself) */
    LFUCache(int capacity) : maxSize(capacity) { }
    
    /* time: O(1), space: O(1) auxiliary (i.e. does not count cache capacity itself) */
    int get(int key) {
        if (!keyToIter.count(key))
            return -1;

        const int oldCount = keyToCount[key], newCount = oldCount + 1;
        auto& oldEntryList = countToEntryList[oldCount];
        auto& newEntryList = countToEntryList[newCount];

        newEntryList.splice(newEntryList.begin(), oldEntryList, keyToIter[key]);
        keyToIter[key] = newEntryList.begin(), keyToCount[key] = newCount;
        
        if (oldEntryList.empty()) {
            countToEntryList.erase(oldCount);
            if (minCount == oldCount)
                minCount = newCount;
        }
        return keyToIter[key]->second;
    }

    /* time: O(1), space: O(1) auxiliary (i.e. does not count cache capacity itself) */
    void put(int key, int value) {
        if (!maxSize)
            return;

        if (get(key) != -1) {
            keyToIter[key]->second = value;
            return;
        }
        
        if (keyToIter.size() == maxSize) {
            auto& entryList = countToEntryList[minCount];
            const int LRFKey = entryList.back().first;
            keyToIter.erase(LRFKey), keyToCount.erase(LRFKey);
            entryList.pop_back();
            if (entryList.empty())
                countToEntryList.erase(minCount);
        }
        
        minCount = 1;
        auto& entryList = countToEntryList[minCount];
        entryList.emplace_front(key, value);
        keyToIter[key] = entryList.begin(), keyToCount[key] = minCount;
    }
};
static int x = []() { ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
__________________________________________________________________________________________________
sample 37752 kb submission
class Info {
private:
    int key;
    int value;
    int freq;
public:
    Info(int key, int value) {
        this->key = key;
        this->value = value;
        this->freq = 1;
    }
    int get_key() {
        return this->key;
    }
    int get_value() {
        return this->value;
    }
    int get_freq() {
        return this->freq;
    }
    void set_value(int value) {
        this->value = value;
    }
    void add_freq() {
        this->freq++;
    }
};


class LFUCache {
private:
    int capacity;
    int curr_vol;
    map<int,int> cache;
    vector<Info> order;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        curr_vol = 0;
    }
    
    int get(int key) {
        map<int,int>::iterator iter = cache.find(key);
        if (iter != cache.end() && capacity > 0) {
            int i = iter->second;
            int v = order[i].get_value();
            order[i].add_freq();
            while (i > 0 && order[i].get_freq() >= order[i-1].get_freq()) {
                iter = cache.find(order[i-1].get_key());
                iter->second = i;
                Info temp = order[i];
                order[i] = order[i-1];
                order[i-1] = temp;
                i--;
            }
            iter = cache.find(order[i].get_key());
            iter->second = i;
            return v;
        }
        else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (capacity == 0) {
            return;
        }
        map<int,int>::iterator iter = cache.find(key);
        if (iter != cache.end()) {
            int i = iter->second;
            order[i].set_value(value);
            order[i].add_freq();
            while (i > 0 && order[i].get_freq() >= order[i-1].get_freq()) {
                iter = cache.find(order[i-1].get_key());
                iter->second = i;
                Info temp = order[i];
                order[i] = order[i-1];
                order[i-1] = temp;
                i--;
            }
            iter = cache.find(order[i].get_key());
            iter->second = i;
        }
        else if (curr_vol < capacity) {
            Info new_node(key, value);
            order.push_back(new_node);
            int i = curr_vol;
            while (i > 0 && order[i].get_freq() >= order[i-1].get_freq()) {
                iter = cache.find(order[i-1].get_key());
                iter->second = i;
                Info temp = order[i];
                order[i] = order[i-1];
                order[i-1] = temp;
                i--;
            }
            cache.insert(pair<int,int>(key, i));
            curr_vol++;    
        }
        else {
            int key_del = order.back().get_key();
            order.pop_back();
            cache.erase(key_del);
            Info new_node(key, value);
            order.push_back(new_node);
            int i = curr_vol - 1;
            while (i > 0 && order[i].get_freq() >= order[i-1].get_freq()) {
                iter = cache.find(order[i-1].get_key());
                iter->second = i;
                Info temp = order[i];
                order[i] = order[i-1];
                order[i-1] = temp;
                i--;
            }
            cache.insert(pair<int,int>(key, i));
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
__________________________________________________________________________________________________
sample 38140 kb submission
class LFUCache {
private:
    struct kv_node;
    struct freq_node {
        int freq, size;
        kv_node *elems;
        freq_node *prev, *next;
        freq_node(int f) : freq(f), size(0) {
            elems = new kv_node(0, 0, this);
            elems->prev = elems;
            elems->next = elems;
        }
    };
    void add_kv_to_freq(freq_node *fn, kv_node *kvn) {
        kvn->container = fn;
        kvn->next = fn->elems->next;
        kvn->next->prev = kvn;
        kvn->prev = fn->elems;
        fn->elems->next = kvn;
        fn->size++;
    }
    void del_kv_from_freq(kv_node *kvn) {
        kvn->next->prev = kvn->prev;
        kvn->prev->next = kvn->next;
        kvn->container->size--;
        if (kvn->container->size == 0) del_freq(kvn->container);
        kvn->container = NULL;
    }
    void add_freq(freq_node *prev) {
        freq_node *curr = new freq_node(prev->freq + 1);
        curr->next = prev->next;
        curr->next->prev = curr;
        curr->prev = prev;
        prev->next = curr;
    }
    void del_freq(freq_node *node) {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        delete node;
    }
    struct kv_node {
        int key, value;
        freq_node *container;
        kv_node *prev, *next;
        kv_node(int k, int v, freq_node *f) : key(k), value(v), container(f) {}
    };
    void inc_kv(kv_node *node) {
        if (node->container->next->freq != node->container->freq + 1)
            add_freq(node->container);
        freq_node *container = node->container->next;
        del_kv_from_freq(node);
        add_kv_to_freq(container, node);
    }
    void ins_kv(kv_node *node) {
        if (freqs->next->freq != 1) add_freq(freqs);
        add_kv_to_freq(freqs->next, node);
    }
    freq_node *freqs;
    int size, cap;
    unordered_map<int, kv_node*> kv_map;
public:
    LFUCache(int capacity) {
        cap = capacity, size = 0;
        kv_map.clear();
        freqs = new freq_node(0);
        freqs->next = freqs;
        freqs->prev = freqs;
    }
    
    int get(int key) {
        if (kv_map.find(key) == kv_map.end()) return -1;
        kv_node *curr = kv_map[key];
        inc_kv(curr);
        return curr->value;
    }
    
    void put(int key, int value) {
        if (cap == 0) return;
        kv_node *curr;
        if (kv_map.find(key) != kv_map.end()) {
            curr = kv_map[key];
            curr->value = value;
            inc_kv(curr);
        } else if (size < cap) {
            curr = new kv_node(key, value, NULL);
            ins_kv(curr);
            size++;
            kv_map[key] = curr;
        } else {
            curr = freqs->next->elems->prev;
            kv_map.erase(curr->key);
            curr->key = key; curr->value = value;
            del_kv_from_freq(curr);
            ins_kv(curr);
            kv_map[key] = curr;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
__________________________________________________________________________________________________
sample 112 ms submission
struct Group;
struct Node {
    int key, val;
    Node *prev, *next;
    Group *parent;
    Node(int k, int v) : key(k), val(v), prev(NULL), next(NULL), parent(NULL) {
    }
};

struct Group {
    int count;
    Group *prev, *next;
    Node head;
    Group(int c) : count(c), prev(NULL), next(NULL), head(0, 0) {
        head.prev = head.next = &head;
    }
};

class LFUCache {
    Group head;
    int cap;
    unordered_map<int, Node*> lookup;

    Group *createAfter(Group *g0, int count) {
        Group *g = new Group(count);
        g->next = g0->next;
        g->prev = g0;
        g->next->prev = g->prev->next = g;
        return g;
    }

    void leaveGroup(Node *p) {
        p->prev->next = p->next;
        p->next->prev = p->prev;

        Group *g = p->parent;
        if (g->head.next == &g->head) {
            g->prev->next = g->next;
            g->next->prev = g->prev;
            delete g;
        }    
    }
    
    void joinGroup(Node *p, Group *g) {
        p->parent = g;
        p->next = g->head.next;
        p->prev = &g->head;
        p->next->prev = p->prev->next = p;
    }

    void update(Node *p) {
        Group *g = p->parent;
        int count = 1 + g->count;
        
        Group *g2 = g->prev;
        if (g2 == &head || count < g2->count)
            g2 = createAfter(g2, count);
            
        leaveGroup(p);        
        joinGroup(p, g2);
    }

public:
    LFUCache(int capacity) : head(0), cap(capacity) {
        head.prev = head.next = &head;
    }

    int get(int key) {
        auto it = lookup.find(key);
        if (it == lookup.end())
            return -1;
        
        Node *p = it->second;
        update(p);
        return p->val;
    }
    
    void put(int key, int value) {
        auto it = lookup.find(key);
        if (it != lookup.end()) {
            Node *p = it->second;
            p->val = value;
            update(p);
        }
        else if (cap > 0) {
            Node *p;
            if (lookup.size() == cap) {
                p = head.prev->head.prev;
                leaveGroup(p);
                lookup.erase(p->key);
                
                p->key = key; // recycle
                p->val = value; 
            }
            else {
                p = new Node(key, value);
            }
            lookup[key] = p;

            Group *g = head.prev;
            if (g == &head || 1 < g->count)
                g = createAfter(g, 1);

            joinGroup(p, g);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */