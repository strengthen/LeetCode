__________________________________________________________________________________________________
class Solution {
    public int[] numSmallerByFrequency(String[] queries, String[] words) {
         int[] q = new int[queries.length], w = new int[words.length];
         for (int i = 0; i < q.length; i++) {
             q[i] = jisuan(queries[i]);
         }
         for (int i = 0; i < w.length; i++) {
             w[i] = jisuan(words[i]);
         }
         Arrays.sort(w);
         int[] ans = new int[q.length];
         for (int i = 0; i < q.length; i++) {
             int l = 0, r = w.length - 1;
             while (l <= r) {
                 int mid = (l + r) / 2;
                 if (w[mid] <= q[i]) {
                     l = mid + 1;
                 }
                 else {
                     r = mid - 1;
                 }
             }
             ans[i] = w.length - l;
         }
         return ans;
     }
     
     private int jisuan(String str) {
         int[] arr = new int[26];
         for (char ch : str.toCharArray())
             arr[ch - 'a']++;
         for (int i = 0; i < 26; i++) {
             if (arr[i] != 0)
                 return arr[i];
         }
         return 0;
     }
 }
__________________________________________________________________________________________________

__________________________________________________________________________________________________
