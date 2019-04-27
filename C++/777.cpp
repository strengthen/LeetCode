__________________________________________________________________________________________________
sample 4 ms submission
static int fast_io = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
    bool canTransform(string start, string end) {
        int i = 0;
        int j = 0;
        const int n = start.size();
        
        while (i < n || j < n) {
            i = getPos(start, i);
            j = getPos(end, j);
            if (i == n || j == n) {
                return i == j;
            }
            
            if (start[i] != end[j]) {
                return false;
            }
            
            if (start[i] == 'R') {
                if (i > j) {
                    return false;
                }
            } else if (i < j) {
                return false;
            }
            i++;
            j++;
        }
        
        return true;
    }

private:
    int getPos(const string& str, int idx) {
        while (idx < str.size() && str[idx] == 'X') {
            idx++;
        }
        
        return idx;
    }
};
__________________________________________________________________________________________________
sample 9468 kb submission
static int x = [](){
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();
class Solution {
public:
    bool canTransform(string start, string end) {
        if (start.length() != end.length()) return false;
        int l = start.length();
        int i = 0, j = 0;
        while (i < l && j < l) {
            while (i < l && start[i] == 'X') i++;
            while (j < l && end[j] == 'X') j++;
            if (i == l && j == l) return true;
            if (i == l || j == l) return false;
            if (start[i] != end[j]) return false;
            if (start[i] == 'R') {
                // R can be taken to the right
                if (i > j) return false;
            } else {
                // L can be taken to the left
                if (i < j) return false;
            }
            i++; j++;
        }
        return true;
    }
};
__________________________________________________________________________________________________
