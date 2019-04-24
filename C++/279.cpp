__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int numSquares(int n) {
        if(isSquare(n))
            return 1;
        while((n&3)==0)
            n>>=2;
        if((n&7)==7)
            return 4;
        int sn=(int)(sqrt(n));
        for(int i=1;i<=sn;i++){
            if(isSquare(n-i*i))
                return 2;
        }
        return 3;
    }
private:
    int isSquare(int n){
        int sn=(int)(sqrt(n));
        return (sn*sn==n);
    }
};
__________________________________________________________________________________________________
sample 7956 kb submission
class Solution {
public:
    int numSquares(int n) {
        if(n == (int) sqrt((double) n) * sqrt((double) n)) return 1;
        while(n % 4 == 0)  n /= 4;
        if(n % 8 == 7) return 4;
        for(int i = 0; i*i < n; ++i) {
            int a = n - i*i;
            if(a == (int) sqrt((double) a) * sqrt((double) a)) return 2;
        }
        return 3;
    }
};
__________________________________________________________________________________________________
