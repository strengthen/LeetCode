__________________________________________________________________________________________________
sample 172 ms submission

static int _ = [](){ ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class RangeModule {
public:
    RangeModule() {  }
    
    // Add range [left, right - 1]
    void addRange(int left, int right) {
        --right;
        
        auto it = ranges.upper_bound(left);
        
        if (it == ranges.begin() || prev(it)->second + 1 < left) {
            // Not adjacent with previous range
            it = ranges.insert({left, right}).first;
        } else { 
            // Adjacent with previous range
            --it;
            it->second = max(it->second, right);
        }
        
        // Merge next range into curr range until it overlaps
        while (next(it) != ranges.end() && next(it)->first <= it->second + 1) {
            it->second = std::max(it->second, next(it)->second);
            ranges.erase(next(it));
        }
    }
    
    // Return true if the full range overlaps
    bool queryRange(int left, int right) {
        --right;
        
        auto it = ranges.upper_bound(left);
        
        if (it == ranges.begin()) {
            return false;
        }
        
        return prev(it)->first <= left && prev(it)->second >= right;
    }
    
    // Remove ranges overlapping with [left, right]
    void removeRange(int left, int right) {
        --right;
        
        // Get the interval with first <= left
        auto it = ranges.upper_bound(left);
        
        // Go to previous range it overlaps
        if (it != ranges.begin() && prev(it)->second >= left) {
            it = prev(it);
        }
        
        // Iterate until the range overlaps
        while (it != ranges.end() && it->first <= right) {
            auto nit = next(it);
            
            if (it->first >= left && it->second <= right) {
                // Full overlap
                ranges.erase(it);
            } else if ((it->first < left && it->second > right)) {
                // Subsumed
                ranges.insert({right + 1, it->second});
                 it->second = left - 1;
            } else if (right < it->second) {
                // Overlaps with first half
                ranges.insert({right + 1, it->second});
                ranges.erase(it);
            } else if (right >= it->second) {
                // Overlaps with second half
                it->second = left - 1;
            } else {
                // Never reach here
                assert(0);
            }
            
            it = nit;
        }
    }

private:
    // Print all ranges
    void print(string s = "**") {
        cout << s << " ";
        
        for (auto&p : ranges) {
            cout << "[" << p.first << " " << p.second << "]  ";
        }
        
        cout << endl;
    }
    
    // Store ranges as closed interval key = left, data = right
    map<int, int> ranges;
};
/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */
__________________________________________________________________________________________________
sample 63372 kb submission
class RangeModule {
    vector<pair<int, int>> _seg;

    int upper_bound(int target) {       // right boundary >= target
        if (_seg.empty()) return -1;

        int lo = 0, hi = _seg.size() - 1;
        while (lo + 1 < hi) {
            int m = lo + (hi - lo) / 2;
            _seg[m].second < target ? lo = m : hi = m;
        }
        if (_seg[lo].second >= target) return lo;
        if (_seg[hi].second >= target) return hi;
        return -1;
    }
    int lower_bound(int target) {       // left boundary <= target
        if (_seg.empty()) return -1;

        int lo = 0, hi = _seg.size() - 1;
        while (lo + 1 < hi) {
            int m = lo + (hi - lo) / 2;
            _seg[m].first > target ? hi = m : lo = m;
        }
        if (_seg[hi].first <= target) return hi;
        if (_seg[lo].first <= target) return lo;
        return -1;
    }
public:
    RangeModule() {
    }
    
    void addRange(int left, int right) {
        int s1 = upper_bound(left), s2 = lower_bound(right);
        if (-1 == s1 || -1 == s2) {
            if (-1 == s1) {
                _seg.push_back({left, right});
             } else {
                 _seg.insert(_seg.begin(), {left, right});
             }
        } else {
            pair<int, int> p = {min(left, _seg[s1].first), max(right, _seg[s2].second)};
            _seg.erase(_seg.begin() + s1, _seg.begin() + s2 + 1);   // [start, end)
            _seg.insert(_seg.begin() + s1, p);
        }
    }
    
    bool queryRange(int left, int right) {
        if (_seg.empty()) return false;
        int lo = 0, hi = _seg.size() - 1;
        while (lo + 1 < hi) {
            int m = lo + (hi - lo) / 2;
            _seg[m].first > left ? hi = m : lo = m;
        }
        if (_seg[hi].first <= left && _seg[hi].second >= right) return true;
        if (_seg[lo].first <= left && _seg[lo].second >= right) return true;
        return false;
    }
    
    void removeRange(int left, int right) {
        int s1 = upper_bound(left), s2 = lower_bound(right);
        if (-1 == s1 || -1 == s2) return;

        pair<int, int> ns1, ns2;        // form new segment potentially
        if (left > _seg[s1].first) ns1 = {_seg[s1].first, left};
        if (right < _seg[s2].second) ns2 = {right, _seg[s2].second};

        _seg.erase(_seg.begin() + s1, _seg.begin() + s2 + 1);
        if (ns1.first) _seg.insert(_seg.begin() + s1, ns1);
        if (ns2.first) _seg.insert(_seg.begin() + s1 + (ns1.first ? 1 : 0), ns2);
    }
};
/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */
__________________________________________________________________________________________________
