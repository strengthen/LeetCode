__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int time2int(String str) {
        int hour = (str.charAt(0) - '0') * 10 + (str.charAt(1) - '0');
        int min = (str.charAt(3) - '0') * 10 + (str.charAt(4) - '0'); 
        return hour * 60 + min;
    }
    public int findMinDifference(List<String> timePoints) {
        int n = timePoints.size();
        boolean[] t = new boolean[24 * 60];
        for (int i = 0; i < n; i++) {
            int c = time2int(timePoints.get(i));
            if (t[c]) return 0;
            else t[c] = true;
        }

        int min = 24 * 60;
        int ans = 24 * 60;
        int last = -1;
        for (int i = 0; i < 24 * 60; i++)
            if (t[i]) {
                min = Math.min(min, i);
                if (last >= 0)
                    ans = Math.min(ans, i - last);
                last = i;
            }
        ans = Math.min(ans, 24 * 60 - last + min);

        return ans;
    }
}
__________________________________________________________________________________________________
sample 34904 kb submission
class Solution {
            public int findMinDifference(List<String> timePoints) {

        int res = Integer.MAX_VALUE, diff = 0, n = timePoints.size();
        timePoints.sort(String::compareTo);
        for (int i = 0; i < timePoints.size(); i++) {

            String t1 = timePoints.get(i), t2 = timePoints.get((i + 1) % n);
            int h1 = (t1.charAt(0) - '0') * 10 + t1.charAt(1) - '0';
            int m1 = (t1.charAt(3) - '0') * 10 + t1.charAt(4) - '0';

            int h2 = (t2.charAt(0) - '0') * 10 + t2.charAt(1) - '0';
            int m2 = (t2.charAt(3) - '0') * 10 + t2.charAt(4) - '0';
            diff = (h2 - h1) * 60 + (m2 - m1);
            if (i == n - 1) diff += 24 * 60;
            res = Math.min(res, diff);
        }
        return res;
    }
}
__________________________________________________________________________________________________
