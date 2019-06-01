__________________________________________________________________________________________________
sample 7 ms submission
class Solution {
    public int nthSuperUglyNumber(int n, int[] primes) {
        int[] uglys = new int[n];
        int[] uglyLists = new int[primes.length];
        int[] uglyIndexs = new int[primes.length];
        uglys[0] = 1;
        for(int i=0;i<primes.length;i++){
            uglyLists[i] = primes[i];
        }
        for(int i=1;i<n;i++){
            uglys[i] = uglyLists[0];
            for(int j=1;j<primes.length;j++){
                if(uglyLists[j]<uglys[i]){
                    uglys[i] = uglyLists[j];
                }
            }
            for(int j=0;j<primes.length;j++){
                if(uglyLists[j]==uglys[i]){
                    uglyIndexs[j]++;
                    uglyLists[j] = uglys[uglyIndexs[j]]*primes[j];
                }
            }           
        }
        return uglys[n-1];
    }
}
__________________________________________________________________________________________________
sample 33720 kb submission
class Solution {
    public static int nthSuperUglyNumber(int n, int[] primes) {
	if (n <= 0 || primes == null || primes.length == 0)
		return 0;
	int len = primes.length;
	int[] index = new int[len];
	int[] result = new int[n];
	result[0] = 1;
	for (int i = 1; i < n; i++) {
		int min = Integer.MAX_VALUE;
		for (int j = 0; j < len; j++) {
			if (result[index[j]] * primes[j] < min)
				min = result[index[j]] * primes[j];
		}
		result[i] = min;
		for (int j = 0; j < len; j++) {
			while (result[index[j]] * primes[j] <= min)
				index[j]++;
		}
	}
	return result[n - 1];
 }
}
__________________________________________________________________________________________________
