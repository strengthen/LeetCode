__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public List<Integer> pancakeSort(int[] a) {
        List<Integer> results = new ArrayList<>();
        
        int n = a.length;
        for (int i = n-1; i > 0; i--) {
            int pos = i;
            for (int j = 0; j < i; j++) {
                if (a[j] > a[pos]) {
                    pos = j;
                }
            }
            if (pos == i) {
                continue;
            }
            
            results.add(pos + 1);
            flip(a, pos);
            
            results.add(i + 1);
            flip(a, i);
        }
        
        return results;
    }
    
    private void flip(int[] a, int k) {
        int i = 0;
        int j = k;
        while (i < j) {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            
            i++;
            j--;
        }
    }
}
__________________________________________________________________________________________________
sample 34992 kb submission
class Solution {
    public List<Integer> pancakeSort(int[] A) {
        List<Integer> ans = new ArrayList();
        int N = A.length;

        Integer[] B = new Integer[N];
        for (int i = 0; i < N; ++i)
            B[i] = i+1;
        Arrays.sort(B, (i, j) -> A[j-1] - A[i-1]);

        for (int i: B) {
            for (int f: ans)
                if (i <= f)
                    i = f+1 - i;
            ans.add(i);
            ans.add(N--);
        }

        return ans;
    }
}
__________________________________________________________________________________________________
