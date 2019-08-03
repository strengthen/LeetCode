__________________________________________________________________________________________________
sample 17 ms submission
class Solution {
    public int[] advantageCount(int[] A, int[] B) {
		int length = A.length;
		int[] res = new int[length];
		boolean[] use = new boolean[length];
		Arrays.sort(A);
		
		for (int i = 0; i < length; i++) {
			res[i] = search(A, B[i], use);
		}
		
		return res;
	}
    
    public int search(int[] A, int k, boolean[] use) {
		int length = A.length, left = 0, right = length - 1, middle;
		while (left < right) {
			middle = (left + right) / 2;
			if (A[middle] > k) 
				right = middle;
			else 
				left = middle + 1;
		}
		
		if (A[left] > k) {
			while (left < length && use[left]) 
				left++;
			if (left < length) {
				use[left] = true;
				return A[left];
			}
		}
		
		left = 0;
		while (left < length && use[left])
			left++;
		use[left] = true;
		return A[left];
	}
}
__________________________________________________________________________________________________
sample 39412 kb submission
class Solution {
    public int[] advantageCount(int[] A, int[] B) {
        // prob should make copy of A first then sort
        Arrays.sort(A);
        
        // is added on decreasing order
        PriorityQueue<int[]> pq= new PriorityQueue<>((a,b)->b[0]-a[0]);
        int[] res = new int[A.length];
        for(int i = 0; i < B.length; i++) {
            pq.add(new int[] {B[i], i});
        }
        int lo = 0;
        int hi = A.length - 1;
        
        
        while(!pq.isEmpty()) {
            int[] arr = pq.remove();
            int val = arr[0];
            int index = arr[1];
            if(A[hi] <= val) {
                res[index] = A[lo];
                lo++;
            } else {
                res[index] = A[hi];
                hi--;
            }
        }
        return res;
    }
}
__________________________________________________________________________________________________
