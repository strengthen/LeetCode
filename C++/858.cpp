__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int mirrorReflection(int p, int q) {
        int count = 1, org_q = q;
        while (q % p != 0) {
            q += org_q;
            count++;
        }
        
        if ((q / p) % 2 == 0) return 0;
        else {
            if (count % 2 == 0) return 2;
            else return 1;
        }
    }
};
__________________________________________________________________________________________________
sample 8360 kb submission
class Solution {
public:
    int gcd(int a, int b) {
        if(b != 0) {
            return gcd(b, a % b);
        }
        return a;
    }
    int mirrorReflection(int p, int q) {
        return 1 + q / gcd(p, q) % 2 - p / gcd(p, q) % 2;
    }
};
__________________________________________________________________________________________________
