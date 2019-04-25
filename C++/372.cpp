__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int me(int a, int b, int m)
    {
        if(b==0)
            return 1;
        
        long y = me(a, b/2, m);   // avoid overflow
        
        if(b%2==0)   // even
            return (y*y)%m;
        else            // odd
            return ((y*y)%m*a)%m;    // over flow here!!
    }

    int superPow(int a, vector<int>& b) {
        
        int n = b.size();        
        int res = 1;
        int m = 1337;
        long x = 1;

        for (int i = 0; i < b.size(); ++i) {
            res = me(res, 10, m) * me(a, b[i], m) % m;
        }

        return res%m;
    }
};
__________________________________________________________________________________________________
sample 8792 kb submission
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        vector<int> tb(10,1);
        a%=1337;
        for(int i=1;i<10;i++){
            tb[i]=(tb[i-1]*a)%1337;
        }
        int ret = 1;
        for(auto d:b){
            int c = ret;
            for(int i=1;i<10;i++){
                ret*=c;
                ret%=1337;
            }
            ret*=tb[d];
            ret%=1337;
        }
        return ret;
    }
};
__________________________________________________________________________________________________
