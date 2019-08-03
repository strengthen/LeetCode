__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int[] fairCandySwap(int[] A, int[] B) {
        int sa = 0, sb = 0;
        for (int a : A) {
            sa += a;
        }
        boolean[] bb = new boolean[100001];
        for (int b : B) {
            sb += b;
            bb[b] = true;
        }
        
        int d = (sa - sb) >> 1;
        for (int a : A) {
            int p = a - d;
            if (p >= 0 && p <= 100000 && bb[p]) {
                return new int[] {a, p};
            }
        }
        throw new IllegalStateException();
    }
}
__________________________________________________________________________________________________
sample 38508 kb submission
class Solution {
    public int[] fairCandySwap(int[] A, int[] B) {
        int sa = Arrays.stream(A).sum();
		int sb = Arrays.stream(B).sum();
		int dif = (sa-sb)/2;
		int[] c = new int[2];
        HashSet<Integer> set = new HashSet<>();
        for(int a : A){
            set.add(a);
        }
        for(int b : B){
            if(set.contains(b+dif)){
                c[0] = b+dif;
                c[1] = b;}
        }
        return c;
    }
}
__________________________________________________________________________________________________
