__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int numSubarraysWithSum(int[] A, int S) {
        return solution2(A, S);
    }
    public int solution1(int[] a, int s){
        int i=0, j=0, k=0, len=a.length, count=0, n=0;
        for(i=0; i<len; i++){ if(a[i]==1){ a[j++]=i; } } 
        //Replace the ones with the index numbers
        if(j<len) a[j]=-1;
        // System.out.println(Arrays.toString(a));
        // System.out.println(a.length);
        if(j==0) if(s==0) return len*(len+1)/2; else return 0;
        if(j==len) if(s!=0) return len-s+1; else return 0;  
        //Using a sentinel value to decide end of array
        if(s>j) return 0;   //There aren't enough ones
        else{
            if(s==0){
                //we have to count the zeroes between ones and use n*(n+1)/2
                for(k=0; k<j; k++){
                    //number of zeroes between a[k-1] and a[k] are a[k]-a[k-1]-1
                    n=a[k]-(k-1==-1?0:a[k-1]+1);
                    if(n!=0) count+=n*(n+1)/2;
                    // System.out.println("k is "+k+" and n is "+n);
                }
                n=len-a[k-1]-1;
                if(n!=0) count+=n*(n+1)/2;
                // System.out.println("k is "+k+" and n is "+n);
            }
            // Now use a sliding window of length k
            else {
                for(k=s-1; k<j; k++){
                    // System.out.println("k is "+k);
                    //start of the window is at a[k-s+1]
                    //end of the window is at a[k]
                    //zeroes before the window are a[k-s+1]-a[k-s] accounting for extra one
                    //zeroes after the window are a[k+1]-a[k] accounting for extra one
                    //so total number of ways is (a[k-s+1]-a[k-s])*(a[k+1]-a[k])
                    //need to handle the ending conditions where k-s<0 and k+1=j
                    count+=(a[k-s+1]-(k-s<0?-1:a[k-s]))*((k+1==j?len:a[k+1])-a[k]);
                }
            }
        }
        return count;
    }
    public int solution2(int[] a, int s){
		int j = 0, k = 0, len = a.length, count = 0, n = 0;
		for (int i = 0; i < len; i++) {
			if (a[i] == 1) {
				a[j++] = i;
			}
		}
		if (j < len)
			a[j] = -1;
		if (j == 0)
			if (s == 0)
				return len * (len + 1) / 2;
			else
				return 0;
		if (j == len)
			if (s != 0)
				return len - s + 1;
			else
				return 0;
		if (s > j)
			return 0;
		else {
			if (s == 0) {
				for (k = 0; k < j; k++) {
					n = a[k] - (k == 0 ? 0 : a[k - 1] + 1);
					if (n != 0)
						count += n * (n + 1) / 2;
				}
				n = len - a[k - 1] - 1;
				if (n != 0)
					count += n * (n + 1) / 2;
			} else {
				for (k = s - 1; k < j; k++) {
					count += (a[k - s + 1] - (k - s < 0 ? -1 : a[k - s])) * ((k + 1 == j ? len : a[k + 1]) - a[k]);
				}
			}
		}
		return count;
    }
}
__________________________________________________________________________________________________
sample 39888 kb submission
class Solution {
    public int numSubarraysWithSum(int[] A, int S) {
        int[] count = new int[A.length+1];
        count[0] = 1;
        int cur = 0;
        int res = 0;
        for (int a : A) {
            cur += a;
            if (cur - S >= 0) {
                res += count[cur - S];
            }
            count[cur] ++;
        }
        return res;
    }
}
__________________________________________________________________________________________________
