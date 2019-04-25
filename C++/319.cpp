__________________________________________________________________________________________________
class Solution {
public:
    int bulbSwitch(int n) {
        int count=0;
        int m=1;
        while(m*m<=n){
            count++;
            m++;
        }
        return count;
    }
};

/*

0 0 0 0 0 0 0 0 0#R0
1 1 1 1 1 1 1 1 1#R1
1 0 1 0 1 0 1 0 1#R2
1 0 0 0 1 1 1 0 0#R3
1 0 0 1 1 1 1 1 0#R4
1 0 0 1 0 1 1 1 0#R5
1 0 0 1 0 0 1 1 0#R6 
1 0 0 1 0 0 0 1 0#R7 
1 0 0 1 0 0 0 0 0#R8 
1 0 0 1 0 0 0 0 1#R9 


1#R1
1 0#R2
1 0 0#R3
1 0 0 1#R4
1 0 0 1 0#R5
1 0 0 1 0 0#R6
1 0 0 1 0 0 0#R7
1 0 0 1 0 0 0 0#R8
1 0 0 1 0 0 0 0 1#R9

12... 1,2,3,4,6,12 ... **even** number flips, so "off"
9 ... 1,3, 9 ... **odd** number flips, so "on"

*/
__________________________________________________________________________________________________
sample 8044 kb submission
class Solution {
public:
    int bulbSwitch(int n) {
        if (n == 0) {
            return 0;
        }
        int first = 1, last = n + 1;
        while (first < last) {
            const int mid = first + (last - first) / 2;
            const int div = n / mid;
            if (mid <= div && mid + 1 > n / (mid + 1)) {
                return mid;
            }
            else if (mid < div) {
                first = mid + 1;
            }
            else {
                last = mid;
            }
        }
        return 0;
    }
};
__________________________________________________________________________________________________
