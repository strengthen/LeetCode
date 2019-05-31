__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    private static int[] ugly = null;
    public int nthUglyNumber(int n) {
        if(ugly == null){
            fillUgly();
        }
        return ugly[n-1];
        
    }
    private static void fillUgly(){
        int two = 0;
        int three = 0;
        int five = 0;
        int next2 = 2, next3 = 3, next5 = 5;
        ugly = new int[1690];
        ugly[0] = 1;
        for(int i = 1; i < 1690; i++){
            int next = Math.min(Math.min(next2,next3), next5);
            ugly[i] = next;
            if(next % 2 == 0){
                next2 = ugly[++two]*2;
            }
            if(next % 3 == 0){
                next3 = ugly[++three]*3;
            }
            if(next % 5 == 0){
                next5 = ugly[++five]*5;
            }
        }
    }
}
__________________________________________________________________________________________________
sample 32188 kb submission
class Solution {
    static List<Integer> res = new ArrayList<>();
    public int nthUglyNumber(int n) {
        if(res.isEmpty()){
        for(long i=1l;i<=Integer.MAX_VALUE;i*=2)
            for(long j=i;j<=Integer.MAX_VALUE;j*=3)
                for(long k = j; k<=Integer.MAX_VALUE;k*=5){
                    res.add((int)k);
                }
        Collections.sort(res);
        }
        return res.get(n-1);
    }
}
__________________________________________________________________________________________________
