__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
      public int largestPerimeter(int[] A) {
       int result = 0;
       int maxA = max(A);
       int maxB = max(A);
       int maxC = max(A);
       while (maxC != 0) {
           if (maxB + maxC > maxA) {
               result = maxA + maxB + maxC;
               break;
           } else {
               maxA = maxB;
               maxB = maxC;
               maxC = max(A);
           }
       }
       return result;
    }

    public int max(int[] A) {
        int max = 0;
        int maxIndex = -1;
        for (int i = 0; i < A.length; i ++) {
            if (max < A[i]) {
                max = A[i];
                maxIndex = i;
            }
        }
        if (maxIndex != - 1) A[maxIndex] = -1;
        return max;
    }
}
__________________________________________________________________________________________________
sample 38276 kb submission
class Solution {
    public int largestPerimeter(int[] A) {
        PriorityQueue<Integer> pq = new PriorityQueue<>((x,y)-> y-x);
		Arrays.stream(A).forEach(pq::add);
        
        int a, b, c;
        if(A.length >= 2) {
            a = pq.poll();
            b = pq.poll();
            c = pq.poll();
            
        } else{
            return 0;
        }

        int i = 3;
        while (i <= A.length) {
            if (b + c > a) {
                return a + b + c;
            } else if(!pq.isEmpty()){
                a = b;
                b = c;
                c = pq.poll();
            } else {
                return 0;
            }

            i++;
        }
        return 0;
    }
}
__________________________________________________________________________________________________
