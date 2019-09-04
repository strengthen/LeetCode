__________________________________________________________________________________________________
sample 0 ms submission

class Solution {
	static final long MOD = 1000000007;
	static int prime_count(int n) {
		if(n<2) return 0;
		boolean[] marks= new boolean[n+1];
		int pc = 1;
		for(int v=3; v<=n; v+=2) {
			for(;v<=n && marks[v]; v+=2);
			if(v > n) break;
			pc ++;
			int d = v+v;
			for(int ix=v+d; ix<=n; ix+=d) marks[ix] = true;
		}
		return pc;
	}
	static long P(int n) {
		long r = 1;
		for(;n>0;n--) r = (r * n)%MOD;
		return r;	
	}
	public static int numPrimeArrangements(int n) {
		int pc = prime_count(n);
		return (int)(P(pc) * P(n-pc)%MOD);
	}
	
	public static void main(String[] args) {
		for(int n=1; n<=100;n++) {
			System.out.println(n + "\t" + numPrimeArrangements(n));
		}
	}
}
__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int numPrimeArrangements(int n) {
        //1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20
        boolean[] primes = new boolean[n+1];
        loop:
        for(int i = 2;i<=n;i++){
            for(int j = 2;j<=Math.sqrt(i);j++){
                if(i % j == 0) continue loop;
            }
            primes[i] = true;
        }
        int countPrime = 0;
        for(int i = 2;i<=n;i++){
            if(primes[i]) countPrime++;
        }
        long ans = ((long)fact(countPrime) * fact(n-countPrime)) % 1000_000_007;
        return (int) ans;
    }
    private int fact(int n){
        long ans = 1;
        for(int i = 1;i<=n;i++){
            ans = (ans * i) % 1000_000_007;
        }
        return (int)ans;
    }
}
__________________________________________________________________________________________________
