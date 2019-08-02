__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int maxDistToClosest(int[] seats) {
        int best = 0;
        int i=0;
        while(i<seats.length){
            if(seats[i]==0){
                int j = i+1;
                while(j<seats.length && seats[j]==0)
                    j++;
                if(j==seats.length || i==0)
                    best = Math.max(best,j-i);
                else
                    best = Math.max(best,(j-i+1)/2);
                i=j;
            }
            i++;
        }
        return best;
    }
}
__________________________________________________________________________________________________
sample 37236 kb submission
class Solution {
    public int maxDistToClosest(int[] seats) {
      int prev = -1;
      int[] max = null;

      Function<int[], Integer> dist = (r -> {
        int d = r[1] - r[0] - 1;
        if (r[0] == -1 || r[1] == seats.length) d *= 2;
        return d;
      });

      for (int i = 0; i < seats.length; i++) {
        int s = seats[i];
        int[] tmp = null;

        if (s == 1) {
          tmp = new int[] {prev, i};
          prev = i;
        } else if (i == seats.length - 1) {
          tmp = new int[] {prev, seats.length};
        }

        if (tmp == null) continue;
        if (max == null || dist.apply(tmp) > dist.apply(max)) max = tmp;
      }

      // System.out.println(Arrays.toString(max));
      if (max[0] == -1 || max[1] == seats.length) return max[1] - max[0] - 1;
      return (max[1] - max[0]) / 2;
    }
}
__________________________________________________________________________________________________
