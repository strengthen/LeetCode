__________________________________________________________________________________________________
class Solution {
    public List<Integer> shortestDistanceColor(int[] colors, int[][] queries) {
        int n = colors.length;
        int last1 = -1, last2 = -1, last3 = -1;
        int[] one = new int[n], two = new int[n], three = new int[n];
        Arrays.fill(one, -1);
        Arrays.fill(two, -1);
        Arrays.fill(three, -1);
        for (int i = 0;i < colors.length;i++) {
            int c = colors[i];
            if (c == 1) last1 = i;
            if (c == 2) last2 = i;
            if (c == 3) last3 = i;
            if (last1 != -1) one[i] = i - last1;
            if (last2 != -1) two[i] = i - last2;
            if (last3 != -1) three[i] = i - last3;
        }
        
        last1 = -1;
        last2 = -1;
        last3 = -1;
        for (int i = n - 1;i >= 0;i--) {
            int c = colors[i];
            if (c == 1) last1 = i;
            if (c == 2) last2 = i;
            if (c == 3) last3 = i;
            if (last1 != -1) one[i] = one[i] == -1 ? last1 - i : Math.min(last1 - i, one[i]);
            if (last2 != -1) two[i] = two[i] == -1 ? last2 - i : Math.min(last2 - i, two[i]); 
            if (last3 != -1) three[i] = three[i] == -1 ? last3 - i : Math.min(last3 - i, three[i]);
        }
        
        List<Integer> dist = new ArrayList<>();
        for (int[] q : queries) {
            int j = q[0];
            int c = q[1];
            if (c == 1) dist.add(one[j]);
            if (c == 2) dist.add(two[j]);
            if (c == 3) dist.add(three[j]);
        }
        
        return dist;
    }
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________
