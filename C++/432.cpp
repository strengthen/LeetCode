__________________________________________________________________________________________________
sample 40 ms submission
class AllOne final {
    using many = unordered_set<string>;
    struct strings final : private variant<monostate, string, many> {
        int size() const noexcept {
            return holds_alternative<many>(*this) ? get<many>(*this).size() : 1;
        }

        void erase(const string& key) noexcept {
            get<many>(*this).erase(key);
        }

        void insert(const string& key) noexcept {
            switch (this->index()) {
            case 0:
                static_cast<variant&>(*this) = key;
                return;
            case 1: {
                this->emplace<many>({move(get<string>(*this)), key});
                return;
            }
            default:
                get<many>(*this).insert(key);
            }
        }

        string get_any() const noexcept {
            return holds_alternative<many>(*this) ? *get<many>(*this).cbegin() : get<string>(*this);
        }
    };

    unordered_map<string, int> key_to_value;
    unordered_map<int, tuple<strings, int, int>> value_to_info;
    int max_value = 0;
    int min_value = 0;

    void remove(const string& key, const int value) noexcept {
        const auto it = value_to_info.find(value);
        auto& [keys, prev, next] = it->second;
        if (keys.size() > 1) {
            keys.erase(key);
            return;
        }
        if (value == min_value) {
            if (value == max_value) {
                min_value = max_value = 0;
                value_to_info.clear();
                return;
            }
            get<1>(value_to_info[min_value = next]) = 0;
        }
        else if (value == max_value)
            get<2>(value_to_info[max_value = prev]) = 0;
        else
            get<1>(value_to_info[next]) = prev,
            get<2>(value_to_info[prev]) = next;
        value_to_info.erase(it);
    }

    void register_value(const int value) noexcept {
        if (!min_value) {
            min_value = max_value = value;
            return;
        }
        auto& [_, prev, next] = value_to_info[value];
        if (value < min_value)
            min_value = get<1>(value_to_info[next = min_value]) = value;
        else if (value > max_value)
            max_value = get<2>(value_to_info[prev = max_value]) = value;
    }

public:
    void inc(const string & key) noexcept {
        const auto it = key_to_value.find(key);
        int after;
        if (it == key_to_value.end()) after = 1, key_to_value.emplace(key, 1);
        else after = ++it->second, remove(key, after - 1);
        get<0>(value_to_info[after]).insert(key);
        register_value(after);
    }

    void dec(const string & key) noexcept {
        const auto it = key_to_value.find(key);
        if (it == key_to_value.end()) return;
        const auto before = it->second;
        remove(key, before);
        if (before == 1) {
            key_to_value.erase(it);
            return;
        }
        const auto after = --it->second;
        get<0>(value_to_info[after]).insert(key);
        register_value(after);
    }

    string getMaxKey() const noexcept {
        return min_value ? get<0>(value_to_info.find(max_value)->second).get_any() : "";
    }

    string getMinKey() const noexcept {
        return min_value ? get<0>(value_to_info.find(min_value)->second).get_any() : "";
    }
};

static const auto _ = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
__________________________________________________________________________________________________
sample 24208 kb submission
class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(m.count(key))
            table.erase({m[key], key});
        m[key]++;
        table.insert({m[key], key});
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(!m.count(key)) return;
        table.erase({m[key], key});
        m[key]--;
        if(!m[key]){
            m.erase(key);
        } else {
            table.insert({m[key], key});
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return table.empty() ? "" : table.rbegin()->second;
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return table.empty() ? "" : table.begin()->second;
    }
private:
    unordered_map<string, int> m;
    set<pair<int, string>> table;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */
__________________________________________________________________________________________________
