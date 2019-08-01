__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public String smallestGoodBase(String n) {
       long num = 0;
        for (char c : n.toCharArray()) num = num * 10 + c - '0';
        
        long x = 1;
        for (int p = 64; p >= 1; p--) {
            if ((x << p) < num) {
                long k = helper(num, p);
                if (k != -1) return String.valueOf(k);
            }
        }
        return String.valueOf(num - 1);
    }
    
    private long helper(long num, int p) {
        long l = 1, r = (long)(Math.pow(num, 1.0/p) + 1);
        while (l < r) {
            long mid = l + (r - l) / 2;
            long sum = 0, cur = 1;
            for (int i = 0; i <= p; i++) {
                sum += cur;
                cur *= mid;
            }
            if (sum == num) return mid;
            else if (sum > num) r = mid;
            else l = mid + 1;
        }
        return -1;
    }
}
__________________________________________________________________________________________________
sample 35640 kb submission
class Solution {
    public String smallestGoodBase(String n) {
        long num = 0;
        
        for(char c : n.toCharArray())
            num = num * 10 + c - '0';
        
        long x = 1;
        int p = 60;
        
        while((x << p) >= num)
            p--;
        
        while(p > 0){
            long k = helper(num, p);
            
            if(k != -1)
                return String.valueOf(k);
            
            p--;
        }
        
        return String.valueOf(num - 1);
    }
    
    private long helper(long num, int p){
        long l = 1, r = (long)(Math.pow(num, 1.0 / p) + 1);
        
        while(l < r){
            long mid = l + (r - l) / 2;
            long sum = 0, cur = 1;
            
            for(int i = 0; i <= p; i++){
                sum += cur;
                cur *= mid;
            }
            
            if(sum == num)
                return mid;
            else if(sum > num)
                r = mid;
            else
                l = mid + 1;
        }
        
        return -1;
    }
}
__________________________________________________________________________________________________
