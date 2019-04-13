__________________________________________________________________________________________________
0ms
class Solution {
    public int videoStitching(int[][] clips, int T) {
        int s = 0, ct = 0;
        while (s < T) {
            int ns = s;
            for (int i = 0; i < clips.length; i++) {
                if (clips[i][0]<=s&&clips[i][1]>s){ns = Math.max(ns, clips[i][1]);}
            }
            if (ns ==s){
                return -1;
            }
            s =ns;
            ct++;
        }
        return ct;
    }
}
__________________________________________________________________________________________________
1ms
class Solution {
     public int videoStitching(int[][] clips, int T) {
          Arrays.sort(clips, new Comparator<int[]>() {
              public int compare(int[] a, int[] b) {
                  return a[0]-b[0];
              }
          });    
          int count = 0;
          int curend = 0;
          //int laststart = -1;
          
          for(int i = 0; i < clips.length; ) {
              if(clips[i][0] > curend) {
                  return -1;
              }
              int maxend = curend;
              while(i < clips.length && clips[i][0] <= curend) { 
                  // while one clip's start is before or equal to current end
                  maxend = Math.max(maxend, clips[i][1]); 
                  // find out the one with the max possible end
                  i++;
              }
              count++;
              curend = maxend;
              if(curend >= T) {
                  return count;    
              }
          }
          return -1;        
      }
}
__________________________________________________________________________________________________
2ms
class Solution {
    public int videoStitching(int[][] clips, int T) {
        int[] dp = new int[T+1];
        Arrays.fill(dp, T+1);
        dp[0] = 0;
        for(int i = 0; i <= T; i++){
            for(int[] clip : clips){
                if(i <= clip[1] && i >= clip[0]){
                    dp[i] = Math.min(dp[i], dp[clip[0]]+1);
                }
            }
        }
        return dp[T] == T+1 ? -1 : dp[T];
    }
}
__________________________________________________________________________________________________
3ms
class Solution {
    public int videoStitching(int[][] clips, int T) {
        if (clips == null || clips.length == 0)return -1;
        
        Arrays.sort(clips, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                if(a[0] != b[0]){
                    return a[0] - b[0];
                }else{
                    return b[1] - a[1];
                }
            }
        });
        List<int[]> candi = new ArrayList<>();
        if(clips[0][0] != 0)return -1;
        Set<Integer> used = new TreeSet<Integer>();
        for(int[] crs : clips){
            if(!used.contains(crs[0])){
                candi.add(crs);
            }
        }
        //CUR START 0, CUR END:
        int rtcp = 1;
        int ce = clips[0][1];
        if(ce >= T)return 1;
        int ne = ce;
        int idx = 1;
        int nc = 0;
        int ty = 0;
        while(ty < candi.size()){
            for(int i = 1; i < candi.size();i++){
                if(candi.get(i)[0] <= ce && candi.get(i)[1] > ne){
                    ne = candi.get(i)[1];
                }
            }
            //System.out.println("ne: " + ne + " ce: " + ce);
            ce=ne;
            rtcp++;
            ty++;
            if(ce >=T)return rtcp;
        }
        return -1;
        }
}
__________________________________________________________________________________________________
13ms
class Solution {
    int T;
    int[][] clips;
    public int videoStitching(int[][] clips, int T) {
        this.T = T;
        this.clips = clips;
        Map<String, List<Integer>> covered = new HashMap<>();
        // dp[i] is saving the min segs to cover 0 to i
        int[] dp = new int[T + 1];
        // lastSegIndex is saving the last segment's index for dp[i]'s choice
        List<List<Integer>> lastSegIndex = new ArrayList<>();
        for (int i = 0; i <= T; i++) {
            dp[i] = 0;
            lastSegIndex.add(new ArrayList<>());
        }
        for (int i = 0; i < clips.length; i++) {
            int start = clips[i][0];
            int end = clips[i][1];
            // k is length
            for (int k = 1; k <= end - start + 1; k++) {
                if (start + k - 1 <= end) {
                    String id = start + "/" + (start + k - 1);
                    if (!covered.containsKey(id)) {
                        covered.put(id, new ArrayList<>());
                    }
                    covered.get(id).add(i);
                }
            }
        }
        for (int i = 1; i <= T; i++) {
            int min = 101;
            int minIndex = -1;
            for (int j = 0; j < i; j++) {
                if (dp[j] >= 0 && covered.containsKey(j + "/" + i)) {
                    int curr = dp[j] + 1;
                    List<Integer> lastSeg = lastSegIndex.get(j);
                    // If the last one can connect, no extra segment is needed
                    if (!findCommon(lastSeg, covered.get(j + "/" + i)).isEmpty()) {
                        curr = dp[j];
                    }
                    if (curr <= min) {
                        min = curr;
                        minIndex = j;
                    }
                }
            }
            if (minIndex == -1) {
                return -1;
            }
            lastSegIndex.get(i).addAll(findCommon(lastSegIndex.get(minIndex), covered.get(minIndex + "/" + i)));
            if (lastSegIndex.get(i).isEmpty()) {
                lastSegIndex.get(i).addAll(covered.get(minIndex + "/" + i));
            }
            dp[i] = min;
        }
        return dp[T];
    }
    private List<Integer> findCommon(List<Integer> a, List<Integer> b) {
        List<Integer> result = new ArrayList<>();
        for (Integer x : b) {
            if (a.contains(x)) {
                result.add(x);
            }
        }
        return result;
    }
}
__________________________________________________________________________________________________
30ms
class Solution {
    public int videoStitching(int[][] clips, int T) {
        if(T == 0){
            return 0;
        }
        Arrays.sort(clips , (i1 , i2) -> (i1[0] - i2[0]));
        int end = 0;
        int start = 0;
        int res = 0;
        for(int i = 0 ; i < clips.length ; i ++){
            if(clips[i][0] <= start){
                if(clips[i][1] > end){
                    end = clips[i][1];
                    if(end >= T){
                        return res + 1;
                    }
                }
            }
            else{
                if(clips[i][0] > end){
                    break;
                }
                start = end;
                res ++;
                i --;
            }
        }
        return -1;
    }
}
__________________________________________________________________________________________________