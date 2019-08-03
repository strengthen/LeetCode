__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public boolean validMountainArray(int[] A) {
        int i = 0;
        while (i + 1 < A.length && A[i + 1] > A[i]) {
            ++i;
        }

        int j = A.length - 1;
        while (j > 0 && A[j - 1] > A[j]) {
            --j;
        }

        return i < A.length - 1 && j > 0 && i == j;
    }
}
__________________________________________________________________________________________________
sample 39648 kb submission
class Solution {
    public boolean validMountainArray(int[] A) {
        if(A.length < 3)
        {
            return false;
        }
        //array is at least size 3, can be a mountain
        else{
            System.out.println("Length of A is: " + A.length);
            int curr = 1; //mountain cannot be first element
            if(A[curr] <= A[curr - 1])
            {
                return false;
            }
            //going up
            while(curr < A.length - 1 && A[curr] > A[curr - 1]  )
            {
                System.out.println("curr: " + A[curr] + " and curr - 1 " + A[curr -1]);
                curr++;
            }
            System.out.println("Going Down");
            //going down
            while( (curr < A.length ) && (A[curr] < A[curr - 1]) )
            {
                System.out.println("curr: " + A[curr] + " and curr - 1 " + A[curr -1]);
                System.out.println("Value of curr: " + curr);
                curr++;
            }
            if(curr == A.length)
            {
                return true;
            }
            else{
                return false;
            }
            
        }
        
    }
}
__________________________________________________________________________________________________
