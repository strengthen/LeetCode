__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int countSegments(String s) {
        boolean space = true;
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ' ') space = true;
            else if (space) {
                count++;
                space = false;
            }
        }
        return count;
    }
}
__________________________________________________________________________________________________
sample 33232 kb submission
class Solution {
    public int countSegments(String s) {
        return (int) Arrays.stream(s.split(" ")).filter(item -> !item.isEmpty()).count();
    }
}
__________________________________________________________________________________________________
