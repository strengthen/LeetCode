__________________________________________________________________________________________________
sample 0 ms submission
class Solution {

    public int[] prevPermOpt1(int[] A) {
        int n = A.length, left = n - 2, right = n - 1, tmp;
        while (left >= 0  && A[left] <= A[left + 1]) left--;
        if (left < 0) return A;
        while (A[left] <= A[right]) right--;
        while (A[right - 1] == A[right]) right--;
        tmp = A[left]; A[left] = A[right]; A[right] = tmp;
        return A;
    }
}
__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int[] prevPermOpt1(int[] A) {
        int n = A.length;
        TreeMap<Integer,Integer> map = new TreeMap<>();
        for(int i=n-1;i>=0;--i){
            if(!map.isEmpty()&&map.lowerKey(A[i])!=null){
                int key = map.lowerKey(A[i]);
                int id = map.get(key);
                int t = A[id];
                A[id] = A[i];
                A[i] = t;
                break;
            }
            else{
                map.put(A[i], i);
            }
        }
        return A;
    }
}
__________________________________________________________________________________________________
