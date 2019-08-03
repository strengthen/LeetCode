__________________________________________________________________________________________________
sample 1 ms submission
import java.util.Collections;
import java.util.PriorityQueue;

class Solution {
public int largestSumAfterKNegations(int[] A, int K) {
		Arrays.sort(A);
		int sum = 0;
		int ns = -1;
		int ne = -1;
		int ps = -1;
		for(int i=0;i<A.length;i++) {
			sum += A[i];
			if(A[i] < 0 ) {
				if( ns == -1) {
					ns = i;
					ne = i;
				}
				else {
					ne = i;
				}
			}
		}
		
		if(ne - ns >= K ) {
			for( int i= ns; i<K; i++) {
				sum = sum - A[i] + -1*A[i];
			}
		}
		else {
			if( ne !=-1 ) {
				for( int i= ne; i>=ns; i--) {
					sum = sum - A[i] + -1*A[i];
				}
				if((K -(ne-ns)+1 )%2 != 0) {
					if(A[ne]*-1 > A[ne+1] ) {
						sum = sum - A[ne+1] + -1*A[ne+1];
					}
					else {
						sum = sum + 2*A[ne];
					}
				}
			}
			//All positives
			else {
				if(K%2 != 0) {
					sum = sum - A[0] + -1*A[0];
				}
			}
		}
		
		return sum;
	}
}
__________________________________________________________________________________________________
sample 34900 kb submission
class Solution {
    public int largestSumAfterKNegations(int[] A, int K) {
        int sum = 0;
        PriorityQueue<Integer> minheap = new PriorityQueue<>((o1,o2)->Integer.compare(o1, o2));
        for (int val : A) {
            sum += val;
            minheap.add(val);
        }
        while (K > 0) {
            int cur = minheap.poll();
            sum -= cur;
            sum += -1 * cur;
            minheap.add(-1*cur);
            K--;
        }
        return sum;
    }
}
__________________________________________________________________________________________________
