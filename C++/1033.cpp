__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        sort(a, b, c);
        
        int min = 0, max = c - a - 2;
        
        if(c - b == 2 || b - a == 2) {
         min = 1;   
        } else {
            if(a + 1 != b) {
                ++min;
            }
        
            if(b + 1 != c) {
                ++min;
            }
        }
        
        return vector<int>({ min, max });
    }
    
private:
    void sort(int& a, int& b, int& c) {
        if(a < b) {
            if(a < c) {
                if(c < b) { // acb
                    swap(b, c);
                } // else abc unnecessary, already ordered correctly
            } else { // cab
                swap(a, c);
                swap(b, c);
            }
        } else if(a < c) { // bac
            swap(a, b);
        } else if(b < c) { // bca
            swap(b, c);
            swap(a, c);
        } else { // cba
            swap(a, c);
        }
    }
    
    // m and n are assumed to hold different values
    void swap(int& m, int& n) {
        m ^= n;
        n ^= m;
        m ^= n;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
  vector<int> s = { a, b, c };
  sort(begin(s), end(s));
  if (s[2] - s[0] == 2) return { 0, 0 };
  return { min(s[1] - s[0], s[2] - s[1]) <= 2 ? 1 : 2, s[2] - s[0] - 2 };
}
};
__________________________________________________________________________________________________
