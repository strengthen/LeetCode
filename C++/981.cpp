__________________________________________________________________________________________________
sample 308 ms submission
static int _ = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    return 0;
} ();
class TimeMap {
    struct info {
        int t;
        string v;
        info(int t, string &v): t(t), v(move(v)) {}
    };
    unordered_map<string, vector<info>> m;
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].emplace_back(timestamp, value);
    }
    
    string get(const string &key, int timestamp) {
        auto it = m.find(key);
        if (it==m.end() || it->second[0].t>timestamp) return "";
        auto &v = it->second;
        if (v.back().t<=timestamp) return v.back().v;
        int l=0, r=v.size()-2;
        while (1) {
            int mid=(l+r)/2;
            if (v[mid].t<=timestamp && timestamp<v[mid+1].t) return v[mid].v;
            if (v[mid].t>timestamp) r=mid-1; else l=mid+1;
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
__________________________________________________________________________________________________
sample 128916 kb submission
class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        return;
    }
    
    void set(string key, string value, int timestamp) {
        if (tmap.find(key) == tmap.end()) {
            tmap[key] = vector<pair<int, string> >(1, make_pair(timestamp, value));
        } else if (value != tmap[key].back().second) {
            tmap[key].push_back(make_pair(timestamp, value));
        }
    }
    
    string get(string key, int timestamp) {
        if (tmap.find(key) == tmap.end()) {
            return "";
        } else if (timestamp < tmap[key][0].first) {
            return "";
        } else if (timestamp >= tmap[key].back().first) {
            return tmap[key].back().second;
        } else {
            int head = 0, tail = tmap[key].size() - 1;
            while (head < tail) {
                int tmp = (head + tail) / 2;
                if (timestamp < tmap[key][tmp].first) {
                    head = tmp;
                } else if (timestamp > tmap[key][tmp].first) {
                    tail = tmp;
                } else
                    return tmap[key][tmp].second;
            }
            return tmap[key][head].second;
        }
    }
private:
   unordered_map<string, vector<pair<int, string>>> tmap; 
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
__________________________________________________________________________________________________
