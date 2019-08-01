__________________________________________________________________________________________________
sample 5 ms submission
class Solution {
    public int countBinarySubstrings(String s) {
        int count = 0;
        int count1 = 1;
        int count2 = 0;
        char[] arr = s.toCharArray();
        for(int i = 1; i < arr.length; i++){
            if(arr[i] == arr[i - 1]) {
                count1++;
                if(count2 >= count1) count++;
            }
            else{
                count++;
                count2 = count1;
                count1 = 1;
            }
        }
        return count;
    }
}
__________________________________________________________________________________________________
sample 38216 kb submission
class Solution {
    public int countBinarySubstrings(String s) {
        int[] groups = new int[s.length()];
        int t = 0;
        groups[0] = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i-1) != s.charAt(i)) {
                groups[++t] = 1;
            } else {
                groups[t]++;
            }
        }

        int ans = 0;
        for (int i = 1; i <= t; i++) {
            ans += Math.min(groups[i-1], groups[i]);
        }
        return ans;
    }
}
__________________________________________________________________________________________________
