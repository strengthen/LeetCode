__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size() <= 1) return chars.size();
        int n = chars.size(), i = 0, j = 1, st = 0;
        char c = chars[0];
        while (j < n) {
            while (j < n && chars[j] == c) ++j;
            chars[i++] = c;
            if (j - st > 1) {
                string tmp = to_string(j - st);
                for (int k = 0; k < tmp.size(); ++k) chars[i++] = tmp[k];
            }
            if (j < n) {
                st = j;
                c = chars[j];
            }
        }
        return i;
    }
};
__________________________________________________________________________________________________
sample 9400 kb submission
class Solution {
public:
	int compress(vector<char>& chars) {
		int start = 0;
		for (int end = 0, count = 0; end < chars.size(); end++) {
			count++;
			if (end == chars.size() - 1 || chars[end] != chars[end + 1]) {
				//We have found a difference or we are at the end of array
				chars[start] = chars[end]; // Update the character at start pointer
				start++;
				if (count != 1) {
					// Copy over the character count to the array
					auto arr = to_string(count);
					for (int i = 0; i<arr.length(); i++, start++)
						chars[start] = arr[i];
				}
				// Reset the counter
				count = 0;
			}
		}
		return start;
	}
};
__________________________________________________________________________________________________
