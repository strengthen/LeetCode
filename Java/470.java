__________________________________________________________________________________________________
sample 3 ms submission
/**
 * The rand7() API is already defined in the parent class SolBase.
 * public int rand7();
 * @return a random integer in the range 1 to 7
 */
class Solution extends SolBase {
    private int shift;
    public Solution()
    {
        shift = rand7();
    }
    public int rand10() {
        int res = (rand7()+shift-1)%10+1;
        shift = (shift+1)%10;
        return res;
    }
}
__________________________________________________________________________________________________
sample 4 ms submission
/**
 * The rand7() API is already defined in the parent class SolBase.
 * public int rand7();
 * @return a random integer in the range 1 to 7
 */
class Solution extends SolBase {
    public int rand10() {
        int val = 40;
        while (val >= 40) {
            val = (rand7() - 1) * 7 + rand7() - 1;
        }
        return val % 10 + 1;
    }
}
__________________________________________________________________________________________________
sample 38752 kb submission
/**
 * The rand7() API is already defined in the parent class SolBase.
 * public int rand7();
 * @return a random integer in the range 1 to 7
 */
class Solution extends SolBase {
    public int rand10() {
        int r1 = rand7(), r2 = rand7();
        while (r1 == 7) {
            r1 = rand7();
        }
        r1 %= 2;
        
        while (r2 > 5) {
            r2 = rand7();
        }
        
        return r1 * 5 + r2;
    }
}