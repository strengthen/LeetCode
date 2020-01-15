__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if(n == 1) return 1;
        else 
            return 0.5;
    }
};
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        double p=1;
        if(n==1)
            return p;
        return p/2;
    }
};
__________________________________________________________________________________________________
