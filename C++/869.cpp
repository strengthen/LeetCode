__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    bool reorderedPowerOf2(int N) {
        int ntrans = helper(N);
        for(int i=0;i<32;++i){
            if(ntrans == helper(1<<i)) return true;
        }
        return false;
    }
    
    int helper(int N){
        int res = 0;
        while(N){
            res+=pow(10, N%10);
            N /=10;
        }
        return res;
    }
};
__________________________________________________________________________________________________
sample 8812 kb submission
class Solution {
public:
    bool reorderedPowerOf2(int N) {
        string strN = to_string(N);
        sort(strN.begin(), strN.end());
        
        for (int i = 0; i < 31; i++) {
            string pow2i = to_string(1 << i);
            sort(pow2i.begin(), pow2i.end());
            
            if (strN == pow2i) {
                return true;
            }
        }
        return false;
    }
};
__________________________________________________________________________________________________
