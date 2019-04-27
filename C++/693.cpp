__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int cur = n % 2;
        n /= 2;
        while (n > 0) {
            if (cur == n % 2) return false;
            cur = n %2;
            n /= 2;
        }
        
        return true;
    }
};
__________________________________________________________________________________________________
sample 8156 kb submission
class Solution {
public:
    bool hasAlternatingBits(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        uint mask = 0x1;
        int i = 31;
        mask = 1 << i;
        while(i && !(n & mask)) {
            i--;
            mask = 1 << i;
        }
        
        if(!i) return n;
        bool prev = true;
        i--;
        
        for (; i >= 0; i--) {
            mask = 0x1 << i;
            bool curr = (n & mask);
            if (curr == prev) return false;
            prev = curr;
        }
        return true;
    }
};
__________________________________________________________________________________________________
