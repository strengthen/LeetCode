__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
	private static List<Integer> list;
	private static int n;

	public static int videoStitching(int[][] clips, int T) {
		n = clips.length;

		list = new ArrayList<>();
		int count = 0;

		int s = 0, e = T;
		int[] start, end;
		while(s < e) {
			start = getClip(clips, s, false);

			if(start == null) return -1;

			if(start[1] >= e) return ++count;

			end = getClip(clips, e, true);

			if(end == null) return -1;

			s = start[1];
			e = end[0];
			count = count + 2;
		}
		return count;
	}

	private static int[] getClip(int[][] clips, int t, boolean isEnd) {
		int[] clip = new int[2];  // clip[0] - clip[i][0]; clip[1] - clip[i][1]
		boolean flag = false;
		int diff1, diff2;
		for(int i = 0; i < n; i ++) {
			if(!isEnd && clips[i][0] <= t && clips[i][1] > t
				|| isEnd && clips[i][0] < t && clips[i][1] >= t ) {
				if(!flag) {
					flag = true;
					clip = new int[] { clips[i][0], clips[i][1] };
				} else {
					diff1 = isEnd ? t - clips[i][0] : clips[i][1] - t;
					diff2 = isEnd ? t - clip[0] : clip[1] - t;
					if(diff1 > diff2) {
						clip[0] = clips[i][0];
						clip[1] = clips[i][1];
					}
				}
			}
		}
		return flag ? clip : null;
	}
}
__________________________________________________________________________________________________
sample 33092 kb submission
class Solution {
    public int videoStitching(int[][] clips, int T) {
        Arrays.sort(clips, (int[] c1, int[] c2) -> c2[1] - c1[1]);
        int sum = 0;
        int min = Integer.MAX_VALUE;
        for (int target = T; target >= 0; ) {
            for (int[] clip : clips) {
                if (clip[1] >= target) {
                    min = Math.min(clip[0], min);
                }
            }
            if (min == target || min == Integer.MAX_VALUE) {
                return -1;
            }
            target = min;
            sum++;
            if (target == 0) {
                return sum;
            }
        }
        return sum;
    }
}
__________________________________________________________________________________________________
