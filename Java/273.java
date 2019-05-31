__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    private static final String[] LESS_THAN_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    private static final String[] TENS = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    private static final String[] BIG = {"", "Thousand", "Million", "Billion"};
    private static final String HUNDRED = "Hundred";
    public String numberToWords(int num) {
        if (num == 0) return "Zero";
        StringBuilder sb = new StringBuilder();
        int bigCount = 0;
        while (num != 0) {
            int group = num % 1000;
            if (group > 0) sb.insert(0, BIG[bigCount]);
            if (group > 0 && bigCount > 0) {
                sb.insert(0, " ");
            }
            if (group % 100 < 20) {
                sb.insert(0, LESS_THAN_20[group % 100]);
                if (group % 100 > 0) sb.insert(0, " ");
            } else {
                sb.insert(0, LESS_THAN_20[group % 10]);
                if (group % 10 > 0) sb.insert(0, " ");
                sb.insert(0, TENS[(group % 100) / 10]);
                if ((group % 100) / 10 > 0)sb.insert(0, " ");
            }
            if (group >= 100) {
                sb.insert(0, HUNDRED);
                sb.insert(0, " ");
                sb.insert(0, LESS_THAN_20[group/100]);
                sb.insert(0, " ");
            }
            num /= 1000;
            bigCount++;
        }
        return sb.toString().trim();
    }
}
__________________________________________________________________________________________________
sample 34380 kb submission
class Solution {
    
    private static final String[] LESS_THAN_20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"}; // never include "Zero" in the result
    private static final String[] TENS = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"}; // no need to include "Ten" because numbers less than 20 will be handled by belowTwenty
    
    public String numberToWords(int num) {
        /**
         * The only possibility to include "Zero" in the result is that the number itself is 0.
         */
        if (num == 0) {
            return "Zero";
        }
        
        return helper(num);
    }
    
    private static String helper(int num) {
        String result;
        if (num < 20) {
            result = LESS_THAN_20[num];
        } else if (num < 100) {
            result = TENS[num / 10] + " " + LESS_THAN_20[num % 10];
        } else if (num < 1000) {
            result = helper(num / 100) + " Hundred " + helper(num % 100);
        } else if (num < 1000000) {
            result = helper(num / 1000) + " Thousand " + helper(num % 1000);
        } else if (num < 1000000000) {
            result = helper(num / 1000000) + " Million " + helper(num % 1000000);
        } else {
            result = helper(num / 1000000000) + " Billion " + helper(num % 1000000000);
        }
        /**
         * Trim the result at each recursion because a number trailing 0s will result in empty space at the end.
         */
        return result.trim();
    }
}
__________________________________________________________________________________________________
