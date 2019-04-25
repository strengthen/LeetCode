__________________________________________________________________________________________________
sample 8 ms submission
static const auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        unsigned int mask = 0x00000080;
        unsigned int later_mask = 0x000000c0;
        unsigned int sec_mask = 0x00000040;
        // cout << endl;
        for (auto i = 0; i < data.size(); ) {
            // cout <<data[i] << " " << mask << " " << (data[i] & mask) << "|";
            if ((data[i] & mask) == 0) {
                ++i;
                // cout << "c";
                continue;
            }
            int cnt = 0;
            unsigned int copy = data[i];
            while((copy & mask) != 0) {
                ++cnt;
                copy <<= 1;
            }
            // cout << cnt << " ";
            if (cnt == 1 || cnt > 4) {
                return false;
            }
            for (auto j = i+1; j < i+cnt ; ++j) {
                if (j >= data.size()) {
                    return false;
                }
                auto l = later_mask & data[j];
                if ((l & mask) == mask && (l & sec_mask) == 0) {
                    continue;
                }
                else {
                    return false;
                }
            }
            i += cnt;
        }
        return true;
    }
};
__________________________________________________________________________________________________
sample 9544 kb submission
class Solution {
    
private:
    
public:
    bool validUtf8(vector<int>& data) {
        const int mask7 = (1 << 7);
        const int mask6 = (1 << 6);
        int numBytesToProcess = 0;
        for(int i = 0; i < data.size(); i++) {
            if (numBytesToProcess == 0) {
                int mask = mask7;
                while( (data[i] & mask) != 0) {
                    ++numBytesToProcess;
                    mask >>= 1;
                }
            
                if (numBytesToProcess == 0) {
                    continue;
                }
                       
                if (numBytesToProcess == 1 || numBytesToProcess > 4) {
                    return false;
                }
            } else {
                if ((data[i] & mask7) == 0 || (data[i] & mask6) != 0 ) return false;
            }
            --numBytesToProcess;
        }
        return numBytesToProcess == 0;
    }
};
__________________________________________________________________________________________________
