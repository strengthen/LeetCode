__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
  public int[] sortArrayByParity(int[] A) {
    int lastOdd = 0;
    for (int i=0; i<A.length; i++) {
      if (A[i]%2==0) {
        if (i != lastOdd) {
          int temp = A[i];
          A[i] = A[lastOdd];
          A[lastOdd] = temp;
        }
        lastOdd++;
      }
    }
    return A;
  }
}
__________________________________________________________________________________________________
sample 36312 kb submission
class Solution {
    public int[] sortArrayByParity(int[] A) {
        List<Integer> even = new ArrayList<Integer>();
        List<Integer> odd = new ArrayList<Integer>();
        for(int i = 0; i<A.length; i++) {
            if (A[i] % 2 == 0 ) {
                even.add(A[i]);
            } else {
                odd.add(A[i]);
            }
        }
        
        even.addAll(odd);
        return even.stream().mapToInt(Integer::intValue).toArray();
    }
}
__________________________________________________________________________________________________
