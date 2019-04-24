__________________________________________________________________________________________________
class TwoSum {
public:
    void add(int number) {
        ++m[number];
    }
    bool find(int value) {
        for (auto a : m) {
            int t = value - a.first;
            if ((t != a.first && m.count(t)) || (t == a.first && a.second > 1)) {
                return true;
            }
        }
        return false;
    }
private:
    unordered_map<int, int> m;
};
__________________________________________________________________________________________________
class TwoSum {
public:
    void add(int number) {
        s.insert(number);
    }
    bool find(int value) {
        for (auto a : s) {
            int cnt = a == value - a ? 1 : 0;
            if (s.count(value - a) > cnt) {
                return true;
            }
        }
        return false;
    }
private:
    unordered_multiset<int> s;
};
__________________________________________________________________________________________________
