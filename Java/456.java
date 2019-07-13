__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
        public boolean find132pattern(int[] nums) {
		int n = nums.length, top = n, third = Integer.MIN_VALUE;

		for (int i = n - 1; i >= 0; i--) {
			if (nums[i] < third)
				return true;
			while (top < n && nums[i] > nums[top])
				third = nums[top++];
			nums[--top] = nums[i];
		}

		return false;
	}
}
__________________________________________________________________________________________________
sample 38784 kb submission
class Solution {
        
    private Interval[] intervals = new Interval[10];
    private int interSize = 0;
    
    private static class Interval {
        private int lowerBound;
        private int highBound;
        
        public Interval(int low, int high){
            lowerBound = low;
            highBound = high;
        }
        
        public boolean contains(int i) {
            if (i > lowerBound && i < highBound){
                return true;
            } else {
                return false;
            }
        }
        
        @Override
        public String toString(){
            return lowerBound + ".." +  highBound;
        }
    }
    
    public void addInterval(Interval interv){
        if (interSize == intervals.length){
            intervals = Arrays.copyOf(intervals, intervals.length * 2);
        }
        intervals[interSize++] = interv;
    }
    
    public int upperIndex(int value){
        Interval toSearch = new Interval(value, 0);
        return Arrays.binarySearch(intervals, 0, interSize, toSearch, Comparator.comparingInt((Interval o) -> o.lowerBound).reversed());
    }
    
    public boolean find132pattern(int[] nums) {
        int currentLow = Integer.MAX_VALUE;
        int currentHigh = Integer.MIN_VALUE;
        
        for (int num : nums) {
            if (num > currentLow && num < currentHigh){
                return true;
            }
            int intervInclNum = upperIndex(num);
            intervInclNum = intervInclNum < 0 ? -intervInclNum - 1 : intervInclNum;
            if (intervInclNum >= 0) { 
                for (int i = intervInclNum -1 ; i < interSize ; i++) {
                    if (i >= 0 && intervals[i].contains(num)){
                        return true;
                    }
                }
            }
            
            if (currentHigh == Integer.MAX_VALUE){
                currentLow = Math.min(currentLow, num);
            } else {
                if (num < currentLow){ // we need to keep track of the previous interval
                    addInterval(new Interval(currentLow, currentHigh));
                    currentHigh = Integer.MIN_VALUE;
                    currentLow = num;
                } else {
                    currentHigh = Math.max(currentHigh, num);
                }
            }
        }
        return false;
    }
}
__________________________________________________________________________________________________
