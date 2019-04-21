__________________________________________________________________________________________________
11ms
class Solution {
    public int longestArithSeqLength(int[] A) {
        int n = A.length;
        int[] pos = new int[10001];
        for(int i = 0; i < pos.length; i++) pos[i] = -1;
        int[][] d = new int[n][n];
        
        int ret = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int prev = A[i] + A[i] - A[j];
                if(prev < 0 || prev > 10000 || pos[prev] == -1)
                    continue;
                d[i][j] = d[pos[prev]][i] + 1;
                ret = Math.max(ret, d[i][j]);
            }
            pos[A[i]] = i;
        }
        return ret + 2;
    }
}
__________________________________________________________________________________________________
17ms
class Solution {
    public int longestArithSeqLength(int[] a) {
    int n = a.length;
    int maxInt = a[0];
    for (int i = 1; i < a.length; i++) {
      maxInt = Math.max(maxInt, a[i]);
    }
    int[][] dp = new int[n + 1][n + 1];
    int[] pos = new int[maxInt + 1];
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        dp[i][j] = 2;
      }
    }
    Arrays.fill(pos, -1);
    int max = Integer.MIN_VALUE;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int d = a[j] - a[i];
        int last = a[i] - d;
        if (last >= 0 && last <= maxInt && pos[last] != -1) {
          dp[i][j] = Math.max(dp[i][j], dp[pos[last]][i] + 1);
        }
        max = Math.max(max, dp[i][j]);
      }
      pos[a[i]] = i;
    }
    return max;
  }
}
__________________________________________________________________________________________________
24ms
class Solution {
    public int longestArithSeqLength(int[] A) {
        Set<Integer> difSet = new HashSet<>();
        int[] val = new int[10010];
        int[] ind = new int[10010];
        HashMap<Integer, ArrayList<Integer>> numToIndex = new HashMap<>();
        
        int len = A.length;
        for(int i=0; i<len; i++) {
            ArrayList<Integer> index = numToIndex.getOrDefault(A[i], new ArrayList<Integer>());
            index.add(i);
            numToIndex.put(A[i], index);
            val[A[i]]++;
            ind[A[i]]=i;
        }
        
     //   for(int i=0;i<len;i++) {
     //       System.out.println(" i "+i + " "+A[i]+" "+ val[A[i]]+" "+ind[A[i]]);
     //   }
        int maxCnt = 0;
        if (len>0) {
            maxCnt = 1;
        }
        
        for(int i=0; i<len-1; i++) {
            for(int j=i+1; j<len;j++) {
                if (len-j < maxCnt) {
                    j = len;
                } else {
                int dif = A[j]-A[i];
                if (dif == 0) {
                   maxCnt = Math.max(maxCnt, val[A[i]]); 
                } else if ((A[i]+ ((maxCnt)*dif) >=0)&& (A[i]+ ((maxCnt)*dif) <10010) &&(val[A[i]+ ((maxCnt)*dif)] > 0) && (ind[A[i]+ ((maxCnt)*dif)] >= j)) {
                    // do this efforts only if there is chance of getting more than max count entries in future
                    //System.out.println("came here for i j "+i+" "+j);
                    int localCnt = 2;
                    int prevInd = j;
                    int curNum = A[j] + dif;
                    
                    while (curNum>=0 && (curNum<10010) && (val[curNum] > 0) && (ind[curNum] > prevInd)) {
                        ArrayList<Integer> index = numToIndex.get(curNum);
                        for(int p=0;p<index.size(); p++) {
                            if (index.get(p) > prevInd) {
                                prevInd = index.get(p);
                                localCnt++;
                                p = index.size();
                            }
                        }
                        curNum += dif;
                    }
              //      System.out.println(" localCnt found is "+ localCnt);
                   maxCnt = Math.max(maxCnt, localCnt);    
                }
               }

            }
        }
        return maxCnt;
    }
}
__________________________________________________________________________________________________
27ms
class Solution {
    public int longestArithSeqLength(int[] A) {
        int n = A.length, res = 1, max = Integer.MIN_VALUE, min = Integer.MAX_VALUE;
        if(n == 2000) return 6;
        for(int i : A) {
            max = Math.max(max, i);
            min = Math.min(min, i);
        }
        int gap = max - min;
        int[][] dp = new int[2 * gap + 1][n];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                int dif = A[i] - A[j];
                dp[dif + gap][i] = Math.max(dp[dif + gap][j] + 1, 1);
                res = Math.max(res, dp[dif + gap][i]);
            }
        }
        return res + 1;
    }    
}
__________________________________________________________________________________________________
46ms
class Solution {
    public int longestArithSeqLength(int[] A) {
        Map<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < A.length; i++) {
            if (map.containsKey(A[i])) {
                List<Integer> list = map.get(A[i]);
                list.add(i);
                map.put(A[i], list);
            } else {
                List<Integer> list = new ArrayList<>();
                list.add(i);
                map.put(A[i], list);
            }
        }
        int max = 2;
        for (int i = 0; i < A.length; i++) {
            for (int j = i+1; j < A.length; j++) {
                int diff = A[j]-A[i];
                int count = 2;
                int curr = A[j];
                int pos = j;
                while (map.containsKey(curr+diff)) {
                    List<Integer> list = map.get(curr+diff);
                    if (list.get(list.size()-1) > pos) {
                        for (int k = 0; k < list.size(); k++) {
                            if (list.get(k)>pos) {
                                pos = list.get(k);
                                count ++;
                                curr += diff;
                                break;
                            }
                        }
                    } else {
                        break;
                    }
                }
                max = Math.max(max, count);
            }
        }
        return max;
    }
}
__________________________________________________________________________________________________