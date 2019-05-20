__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int lastStoneWeight(int[] stones) {
        int iLen = stones.length;
        Arrays.sort(stones);
        //quickSort(0, iLen - 1, stones);
        while(true) {
            if (iLen == 1) {
                return stones[0];
            } 
            if (iLen <= 0) {
                return 0;
            }
            
            int sub = stones[iLen - 1] - stones[iLen - 2];
            if (sub == 0) {
                iLen = iLen - 2;
            } else {
                iLen = iLen - 1;
                insertSub(sub, iLen - 1, stones);
            }
        }
    }
    
    public void insertSub(int sub, int iLen, int nums[]) {
        boolean insert = false;
        for (int i=0; i<iLen; i++) {
            if (nums[i] > sub) {
                insert = true;
                int end = iLen;
                while (end > i) {
                    nums[end] = nums[end - 1];
                    end--;
                }
                nums[i] = sub;
                break;
            }
        }
        if (!insert) {
            nums[iLen] = sub;
        }
    }
    
    public void quickSort(int low, int high, int nums[]){
        if (low >= high) {
            return;
        }
        
        int start = low;
        int end = high;
        int key = nums[start];
        while(start < end) {
            while (start < end && nums[start] < key) {
                start++;
            }
            while (end > start && nums[end] >= key) {
                end--;
            }
            if (start < end) {
                int temp = nums[end];
                nums[end] = nums[start];
                nums[start] = temp;
            } else {
                end = high;
                while (start < end) {
                    while (start < end && nums[start] == key) {
                        start++;
                    }
                    while (start < end && nums[end] > key) {
                        end--;
                    }
                    if (start < end) {
                        int temp = nums[end];
                        nums[end] = nums[start];
                        nums[start] = temp;
                    } 
                }
            }
        }
        quickSort(low, start-1, nums);
        quickSort(start, high, nums);
    }
}
__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int lastStoneWeight(int[] stones) {
        int remaining = stones.length;
        while (remaining > 1) {
            int max_high = Integer.MIN_VALUE;
            int max_high_location = -1;
            int max_low = Integer.MIN_VALUE;
            int max_low_location = -1;
            for (int i = 0; i < stones.length; i++) {
                if (stones[i] >= max_high) {
                    max_low = max_high;
                    max_low_location = max_high_location;
                    max_high = stones[i];
                    max_high_location = i;
                }
                else {
                	if (stones[i] > max_low) {
                		max_low = stones[i];
                		max_low_location = i;
                	}
                }
            }
            if (max_high > max_low) {
                stones[max_low_location] = 0;
                stones[max_high_location] = max_high-max_low;
                remaining -= 1;
            }
            else {
                stones[max_low_location] = 0;
                stones[max_high_location] = 0;
                remaining -= 2;
            }
        }
        for (int i = 0; i < stones.length; i++) {
            if (stones[i] != 0) {
                return stones[i];
            }
        }
        return 0;
    }
}
__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    
    public int lastStoneWeight(int[] stones) {
        PriorityQueue<Integer> pq = new PriorityQueue<>(Comparator.reverseOrder());
        for (int i : stones) pq.add(i);
        
        while (pq.size() >= 2) {
            int a = pq.remove();
            int b = pq.remove();
            
            if (a != b) {
                pq.add(a - b);
            } 
        }
        
        return pq.size() == 0 ? 0 : pq.remove();
    }
}