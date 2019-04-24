__________________________________________________________________________________________________
sample 4 ms submission
struct Solution final {
    static vector<string> findRepeatedDnaSequences(const string& s) noexcept{
        if (s.size() <= 10) return {};
        vector<string> repeated;
        bitset<0x100000> seen, seen_twice;
        int word = 0;
        for (int i = 0; i < s.size(); ++i) {
            word <<= 2;
            word &= 0xFFFFF;
            switch (s[i]) {
                case 'T': word |= 1; break;
                case 'G': word |= 2; break;
                case 'C': word |= 3;
            }
            if (i >= 9) {
                if (seen.test(word)) {
                    if (!seen_twice.test(word))
                        repeated.push_back(s.substr(i - 9, 10));
                    seen_twice.set(word);
                }
                else seen.set(word);
            }
        }
        return repeated;
    }
};

static const auto speedup = []() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); return 0; }();
__________________________________________________________________________________________________
sample 9328 kb submission
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if(s.size()<=10) return result;
        bitset<1<<20> once, twice;
        int hash = 0;
        for(int i=0; i<10; ++i)
        {
            hash = (hash<<2) | encode(s[i]);
        }
        once.set(hash);
        int mask = (1<<20)-1;
        for(int i=10; i<s.size(); ++i)
        {
            hash = ((hash<<2) & mask) | encode(s[i]);
            if(twice[hash])
            {
                continue;
             }
            else if(once[hash])
            {
                result.emplace_back(s.substr(i-10+1, 10));
                twice.set(hash);
            }
            else
                once.set(hash);
        }
        return result;
    }
    
    int encode(char c)
    {
        switch(c)
        {
            case 'A':
                return 0;
            case 'C':
                return 1;
            case 'G':
                return 2;
            case 'T':
                return 3;
        }
        return 4;
    }
};
__________________________________________________________________________________________________
