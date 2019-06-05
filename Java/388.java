__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    private int maxLen;
    private int currLevel;
    private int currIdx;
    public int lengthLongestPath(String input) {
        maxLen = 0;
        currLevel = 0;
        currIdx = 0;
        input += "\n";
        lengthLongestPathHelper(input, 0, 0);
        return maxLen;
    }
    private void lengthLongestPathHelper(String input, int level, int startLen) {
        if (currLevel != level) return;
        int currLen = 0;
        while (currIdx < input.length()-1) {
            int idx = input.indexOf("\n", currIdx);
            currLen = startLen + idx - currIdx;
            int dotIdx = input.indexOf(".", currIdx);
            if (dotIdx > 0 && dotIdx < idx && currLen > maxLen) maxLen = currLen;
            currIdx = idx;
            currLevel = 0;
            while (currIdx != input.length()-1 && input.charAt(++currIdx) == '\t') ++currLevel;
            if (level < currLevel)
                lengthLongestPathHelper(input, level+1, currLen+1);
            if (level > currLevel) return;
        }
    }
}
__________________________________________________________________________________________________
sample 34292 kb submission
class Solution {
    public int lengthLongestPath(String input) {
        if (input.isEmpty()) {
                return 0;
            }

            char start = '\n';
            char next = '\t';
            int i = 0;
            int currentLevel = 0;
            Deque<Integer> levels = new ArrayDeque<>();
            int max = 0;
            int length = 0;
            while (i < input.length()) {
                if (input.charAt(i) == start) {
                    currentLevel = 0;
                    levels.add(length);
                    length = 0;
                    i++;
                    while (i < input.length() && input.charAt(i) == next) {
                        currentLevel++;
                        i++;
                    }
                    while (levels.size() > currentLevel) {
                        levels.removeLast();
                    }
                } else {
                    if (input.charAt(i) == '.') {
                        length++;
                        i++;
                        while (i < input.length() && input.charAt(i) != start) {
                            length++;
                            i++;
                        }
                        int currentMax = levels.size() + levels.stream().mapToInt(l -> l).sum() + length;
                        if (currentMax > max) {
                            max = currentMax;
                        }
                        length = 0;
                    } else {
                        i++;
                        length++;
                    }
                }
            }

            return max;
    }
}
__________________________________________________________________________________________________
