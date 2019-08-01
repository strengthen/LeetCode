__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public String reverseWords(String s) {
        char[] c = s.toCharArray();
        int wordIndex = 0;
        int spaceIndex = 0;
        while ((spaceIndex = s.indexOf(" ", spaceIndex)) != -1) {
            reverse(c, wordIndex, spaceIndex-1);
            spaceIndex++;
            wordIndex = spaceIndex;
        }
        reverse(c, wordIndex, c.length - 1);
        return String.valueOf(c);
    }

    private static void reverse(char[] c, int i, int j) {
        while (i < j) {
            char temp = c[i];
            c[i] = c[j];
            c[j] = temp;
            i++;j--;
        }
    }
}
__________________________________________________________________________________________________
sample 37328 kb submission
class Solution {
    public String reverseWords(String s) {
        return String.join(" ",
                        Arrays.asList(s.split(" "))
                              .stream()
                              .map(sec->new StringBuilder(sec).reverse().toString())
                              .collect(Collectors.toList()));
    }
}
__________________________________________________________________________________________________
