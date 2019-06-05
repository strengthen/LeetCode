__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
// According to the problem statement
// F(0) = (0A) + (1B) + (2C) + (3D) + (4E)
// F(1) = (4A) + (0B) + (1C) + (2D) + (3E)
// F(2) = (3A) + (4B) + (0C) + (1D) + (2*E)

// This problem at a glance seem like a difficult problem. I am not very strong in mathematics, so this is how I visualize this problem

// We can construct F(1) from F(0) by two step:
// Step 1. taking away one count of each coin from F(0), this is done by subtracting "sum" from "iteration" in the code below
// after step 1 F(0) = (-1A) + (0B) + (1C) + (2D) + (3*E)

// Step 2. Add n times the element which didn't contributed in F(0), which is A. This is done by adding "A[j-1]len" in the code below.
// after step 2 F(0) = (4A) + (0B) + (1C) + (2D) + (3E)

// At this point F(0) can be considered as F(1) and F(2) to F(4) can be constructed by repeating the above steps.

    public int maxRotateFunction(int[] A) {
        if(A.length == 0){
            return 0;
        }
        
        int sum =0, iteration = 0, len = A.length;
        
        for(int i=0; i<len; i++){
            sum += A[i];
            iteration += (A[i] * i);
        }
        
        int max = iteration;
        for(int j=1; j<len; j++){
            // for next iteration lets remove one entry value of each entry and the prev 0 * k
            iteration = iteration - sum + A[j-1]*len;
            max = Math.max(max, iteration);
        }
        
        return max;
    }
}
__________________________________________________________________________________________________
sample 36820 kb submission
class Solution {
  public int maxRotateFunction(int[] A) {
    long sum = Arrays.stream(A).mapToLong(i -> (long) i).sum();
    long b = IntStream.range(0, A.length).map(idx -> idx * A[idx]).sum();
    long ans = b;
    for (int i = 0; i < A.length; i++) {
      b += sum - (long) A.length * A[A.length - i - 1];
      ans = Math.max(ans, b);
    }
    return (int)ans;
  }
}
__________________________________________________________________________________________________
