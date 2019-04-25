__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    string toHex(int num) {
        string res;
        for (int i = 0; num && (i < 8); ++i) {
            int t = num & 0xf;
            if (t >= 10) res = (char)(t - 10 + 'a') + res;
            else res = (char) (t + '0') + res;
            num >>= 4;
        }
        
        return res.empty() ? "0" : res;
    }
};
__________________________________________________________________________________________________
sample 8528 kb submission
class Solution {
public:
    string toHex(int num) {
        unsigned int n = num;
        int base = 0x10000000;
        string ans;
        while(base)
        {
            int d = n / base;
            //cout << n << ' ' << base << ' ' << d << endl;
            n %= base;
            base = base >> 4;
            if(ans.size() || d || !base)
            {
                if(d >= 10)
                {
                    ans.push_back('a'+d-10);
                }
                else
                {
                    ans.push_back('0'+d);
                }
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________
