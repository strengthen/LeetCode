__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    public String originalDigits(String s) {
        int[] table = new int[26];
        for (char c : s.toCharArray()) {
            table[c - 'a']++;
        }
        int[] temp = new int[10];
        char[] identifiers = new char[] {'z', 'w', 'u', 'f', 'o', 'x', 's', 'g', 't', 'i'};
        int[] indexes = new int[] {0, 2, 4, 5, 1, 6, 7, 8, 3, 9};
        String[] strs = new String[] {"zero", "two", "four", "five", "one", "six", "seven", "eight", "three", "nine"};
        for (int i = 0; i < 10; i++) {
            char iden = identifiers[i];
            int index = indexes[i];
            String str = strs[i];
            int fre = table[iden - 'a'];
            if (fre > 0) {
                temp[index] = fre;
                for (char c : str.toCharArray()) {
                    table[c - 'a'] -= fre;
                }
            }
        }
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < temp[i]; j++) {
                result.append(i);
            }
        }
        return result.toString();
    }
}
__________________________________________________________________________________________________
sample 38212 kb submission
class Solution {
    public String originalDigits(String s) {
        String[] nums = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        int[] count = new int[10];
        for(char c : s.toCharArray()) {
            if(c == 'z')
                count[0]++;
            if(c == 'w')
                count[2]++;
            if(c == 'u')
                count[4]++;
            if(c == 'x')
                count[6]++;
            if(c == 'g')
                count[8]++;
            if(c == 'o')
                count[1]++;
            if(c == 'h')
                count[3]++;
            if(c == 'f')
                count[5]++;
            if(c == 's')
                count[7]++;
            if(c == 'i')
                count[9]++;
        }
        
        count[1] = count[1]- count[0] - count[2] - count[4];
        count[3] -= count[8];
        count[5] -= count[4];
        count[7] -= count[6];
        count[9] = count[9] - count[8] - count[5] - count[6];
        
        StringBuilder res = new StringBuilder();
        for(int i = 0; i < 10; i++)
            for(int j = 0; j < count[i]; j++)
                res.append(i);
        
        return res.toString();
    }
}
__________________________________________________________________________________________________
