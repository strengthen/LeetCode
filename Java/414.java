__________________________________________________________________________________________________
sample 0 ms submission
public class Solution {
	public int thirdMax(int[] nums) {

		// first >> secound >> third
		long first = Long.MIN_VALUE;
		long second = Long.MIN_VALUE;
		long third = Long.MIN_VALUE;

		for (int i : nums) {
			if (i > first) {
				third = second;
				second = first;
				first = i;
			} else if (i > second && i < first) {
				third = second;
				second = i;
			} else if (i > third && i < second) {
				third = i;
			}
		}

		return third == Long.MIN_VALUE ? (int) first : (int) third;
	}
}
__________________________________________________________________________________________________
sample 36348 kb submission
class Solution {
    public int thirdMax(int[] nums) {
        PriorityQueue<Long> heap = new PriorityQueue<Long>((n1, n2) -> {
            if (n1 > n2) return 1;
            else if (n1 < n2) return -1;
            else return 0;
        });
        
        Long max = Long.MIN_VALUE;
        HashSet<Long> val = new HashSet<>();
        for (int n : nums) {
            if (val.contains(Long.valueOf(n))) continue;
            heap.add(Long.valueOf(n));
            val.add(Long.valueOf(n));
            
            if (heap.size() > 3) heap.poll();
            max = Math.max(max, n);
        }
        
        return heap.size() == 3 ? (heap.poll().intValue()) : (int)(max.intValue());
    }
}
__________________________________________________________________________________________________
