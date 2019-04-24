__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret=0;
        for(int i=0;i<32;i++){
            ret<<=1;
            if(n&1)
                ret++;
            n>>=1;
        }
        return ret;
    }
};
__________________________________________________________________________________________________
sample 7728 kb submission
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        uint32_t pos = 1;
        uint32_t temp;
        for(int i=0; i<32; ++i){            
            if( (n & pos) > 0 ) temp = 1;
            else temp = 0;
            result = result << 1;
            result = result + temp;
            pos = pos << 1;
            //cout << result << endl;
        }
        return result;
    }
};
__________________________________________________________________________________________________
