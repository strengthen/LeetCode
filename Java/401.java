__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public List<String> readBinaryWatch(int num) {
        
       int[] time = { 1, 2, 4, 8, 16, 32, 1, 2, 4, 8 };

		ArrayList<String> ans = new ArrayList<>();
		binaryWatch(time, 0, 0, 0, ans, num);
        return ans ;
    }
    
 public static void binaryWatch(int[] time, int idx, int hr, int min, ArrayList<String> list, int tl) {

		if (tl == 0) {

			String fm = min + "";

			if (fm.length() == 1)
				fm = "0" + min;

			list.add(hr + ":" + fm);

			return;

		}

		if (idx == time.length) {
			return;
		}

		if (idx >= 6) {

			if (hr + time[idx] <= 11) {
				binaryWatch(time, idx + 1, hr + time[idx], min, list, tl - 1);
			}
		} else {

			if (min + time[idx] <= 59)
				binaryWatch(time, idx + 1, hr, min + time[idx], list, tl - 1);
		}

		binaryWatch(time, idx + 1, hr, min, list, tl); // no

	}
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________
