__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
    private boolean isPossible(int[] weights, int capacity, int D) {
        int count = 0;
        int sum = 0;
        for (int i = 0; i < weights.length; i++) {
            if (weights[i] > capacity) {
                return false;
            }
            if (sum + weights[i] > capacity) {
                count++;
                sum = 0;
            }
            sum += weights[i];
        }
        count++;
        if (count > D) {
            return false;
        }
        return true;
    }
    
    public int shipWithinDays(int[] weights, int D) {
        int sum = 0;
        int low = 1;
        int high = (weights.length * 500) / D;
        int minPossible = high;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(weights, mid, D)) {
                minPossible = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return minPossible;
    }
}
__________________________________________________________________________________________________
sample 40508 kb submission
class Solution {
    public int shipWithinDays(int[] weights, int D) {
        if (weights == null || weights.length == 0) return 0;
    int right = Arrays.stream(weights).sum();
    int left = Arrays.stream(weights).max().getAsInt();
    while (left < right) {
      int mid = left + (right - left) / 2;
      if (canDivid(weights, mid, D)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }
    System.out.println("capacity " + left);
    return left;
  }
  private boolean canDivid(int[] weights, int capacity, int D) {
    int count = 1;
    int sum = 0;
    for (int w : weights) {
      if (sum + w > capacity) {
        sum = 0;
        count++;
      }
      sum += w;
      if (count > D) return false;
    }
    return true;
  } 
}
__________________________________________________________________________________________________
