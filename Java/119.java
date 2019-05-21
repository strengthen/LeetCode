__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> ans = new ArrayList<>();
        if (rowIndex == 0) {
            ans.add(1);
            return ans;
        }
        if (rowIndex == 1) {
            ans.add(1);
            ans.add(1);
            return ans;
        }

        int[] last = new int[rowIndex + 1];
        int[] cur = new int[rowIndex + 1];
        int[] tmp;

        last[0] = last[1] = last[rowIndex] = cur[0] = cur[rowIndex] = 1;

        for (int i = 3; i <= rowIndex + 1; i++) {
            for (int j = 1; j < i - 1; j++) {
                cur[j] = last[j] + last[j - 1];
            }
            cur[i - 1] = 1;
            tmp = last;
            last = cur;
            cur = tmp;
        }

        for (int n : last) {
            ans.add(n);
        }
        return ans;
    }
}
__________________________________________________________________________________________________
sample 32084 kb submission
class Solution {
    public List<Integer> getRow(int rowIndex) {
		List<Integer> result = new ArrayList<>();
		if (rowIndex < 0) {
			return result;
		}
		result.add(1);
		if (rowIndex == 0) {
			return result;
		}
		result.add(1);
		if (rowIndex == 1) {
			return result;
		}

		int[] res = new int[rowIndex + 1];
		res[0] = 1;
		res[1] = 1;

		int currentIndex = 1;
		while (currentIndex < rowIndex) {
			int currLen = currentIndex + 1;
			int nextLen = currLen + 1;

			res[nextLen - 1] = 1;

			int left = currLen / 2;
			int right = nextLen / 2;

			while (left > 0 && right < nextLen - 1) {
				res[right] = res[left] + res[left - 1];
				right++;
				left--;
			}

			left = 0;
			right = nextLen - 1;
			while (left < right) {
				res[left++] = res[right--];
			}
			currentIndex++;
		}
		result.clear();
		for (int i = 0; i <= rowIndex; i++) {
			result.add(res[i]);
		}
		return result;
	}
}
__________________________________________________________________________________________________
