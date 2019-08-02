__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int countPrimeSetBits(int L, int R) {
        int count = 0;
        P[2] = true;
        P[3] = true;
        P[5] = true;
        P[7] = true;
        P[11] = true;
        P[13] = true;
        P[17] = true;
        P[19] = true;
        for (int i = L; i <= R; i++) {
            if(isPrimeSet(i)) count++;
        }
        return count;
    }
    
    boolean[] P = new boolean[20];
    
    boolean isPrimeSet(int x) {
        int c = Integer.bitCount(x);
        return P[c];    
    }
}
__________________________________________________________________________________________________
sample 31844 kb submission
class Solution {
    public int countPrimeSetBits(int L, int R) {
        int count = 0;
        for (int i=L; i<=R; i++) {
            if (isPrime(numberOfOnes(i))) {
                count++;
            }
        }
        return count;
    }
    
    public boolean isPrime(int num) {
        if (num <= 1) return false;
        int bound = (int) Math.sqrt(num);
       // boolean prime = true;
        for (int i=2; i<=bound; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        
        return true;
    }
    
    public int numberOfOnes (int num) {
        
        int count = 0;
        while (num != 0) {
            num = num & (num-1);
            count++;
        }
        
        return count;
    }
}
__________________________________________________________________________________________________
