__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    // 非递归解法
    public static int trailingZeroes(int n) {
        if (n<5)return 0;

        if (n<10)return 1;

        return (n/5+ trailingZeroes(n/5));
    }

}
__________________________________________________________________________________________________
sample 31896 kb submission
class Solution {
    public int trailingZeroes(int n) {
          int sum=5;        int count = 0;
        for (int i = 0; i < n; i++) {
               if(n/sum>0){
                   count +=n/sum;
                   sum *=5;
                   if(sum >1220703125){
                      break;
                  }
               }else{
                   break;
               }
        }
        return count;
    }
}
__________________________________________________________________________________________________
