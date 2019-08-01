__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int findMaxForm(final String[] strs, final int m, final int n) {
        final int[][] stringCountsByBitCounts = getStringCountsByBitCounts(strs, m, n);
        return help(stringCountsByBitCounts, m, n, 0, 0, Integer.MAX_VALUE);
    }
    
    private int help(
        final int[][] remainingStringCountsByBitCounts,
        final int remainingZeros,
        final int remainingOnes,
        final int minZerosToConsider,
        final int minOnesToConsider,
        final int maxOnesToConsider
    ) {
        if (minZerosToConsider >= remainingStringCountsByBitCounts.length
            || minZerosToConsider > remainingZeros
        ) {
            return 0;
        }
        if (minOnesToConsider > maxOnesToConsider
            || minOnesToConsider >= remainingStringCountsByBitCounts[minZerosToConsider].length
            || minOnesToConsider > remainingOnes
        ) {
            return
                help(remainingStringCountsByBitCounts, remainingZeros, remainingOnes,
                     minZerosToConsider + 1, 0, maxOnesToConsider);
        }
        if (remainingStringCountsByBitCounts[minZerosToConsider][minOnesToConsider] == 0) {
            return
                help(remainingStringCountsByBitCounts, remainingZeros, remainingOnes,
                     minZerosToConsider, minOnesToConsider + 1, maxOnesToConsider);
        }
        final int option1;
        {
            remainingStringCountsByBitCounts[minZerosToConsider][minOnesToConsider] -= 1;
            option1 = 1 + help(remainingStringCountsByBitCounts,
                               remainingZeros - minZerosToConsider,
                               remainingOnes - minOnesToConsider,
                               minZerosToConsider, minOnesToConsider, maxOnesToConsider);
            remainingStringCountsByBitCounts[minZerosToConsider][minOnesToConsider] += 1;
        }
        final int option2 =
            help(remainingStringCountsByBitCounts, remainingZeros, remainingOnes,
                 minZerosToConsider + 1, 0, minOnesToConsider - 1);
        return Math.max(option1, option2);
    }
    
    private int[][] getStringCountsByBitCounts(final String[] strs, final int m, final int n) {
        final int[][] stringCountsByBitCounts = new int[m+1][n+1];
        
        for (final String s : strs) {
            final int numZeros = countZeros(s);
            final int numOnes = s.length() - numZeros;
            if (numZeros <= m && numOnes <= n) {
                ++stringCountsByBitCounts[numZeros][numOnes];
            }
        }
        
        for (int i = 0; i <= m; ++i) {
            stringCountsByBitCounts[i] = trimTrailingZeros(stringCountsByBitCounts[i]);
        }
        
        return trimTrailingEmptyArrays(stringCountsByBitCounts);
    }
    
    private int countZeros(final String s) {
        int numOnes = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s.charAt(i) == '0') {
                ++numOnes;
            }
        }
        return numOnes;
    }
    
    private int[] trimTrailingZeros(final int[] arr) {
        if (arr.length == 0 || arr[arr.length - 1] != 0) {
            return arr;
        }
        for (int i = arr.length - 2; i >= 0; --i) {
            if (arr[i] != 0) {
                final int[] result = new int[i+1];
                System.arraycopy(arr, 0, result, 0, i+1);
                return result;
            }
        }
        return new int[0];
    }
    
    private int[][] trimTrailingEmptyArrays(final int[][] arr) {
        if (arr.length == 0 || arr[arr.length - 1].length > 0) {
            return arr;
        }
        for (int i = arr.length - 2; i >= 0; --i) {
            if (arr[i].length > 0) {
                final int[][] result = new int[i+1][];
                System.arraycopy(arr, 0, result, 0, i+1);
                return result;
            }
        }
        return new int[0][];
    }
}
__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        if (null == strs || strs.length == 0 || (m == 0 && n == 0)) {
            return 0;
        }

        List<OneAndZero> zeroList = new ArrayList<>();
        List<OneAndZero> oneList = new ArrayList<>();

        for (String s : strs) {
            int countZero = 0, countOne = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == '0') {
                    countZero++;
                } else if (s.charAt(i) == '1') {
                    countOne++;
                }
            }
            zeroList.add(new OneAndZero(s, countZero, countOne));
            oneList.add(new OneAndZero(s, countZero, countOne));
        }

        Collections.sort(zeroList, new Comparator<OneAndZero>() {
            @Override
            public int compare(OneAndZero o1, OneAndZero o2) {
                return Math.min(o1.countZero, o1.countOne) - Math.min(o2.countZero, o2.countOne);
            }
        });

        Collections.sort(oneList, new Comparator<OneAndZero>() {
            @Override
            public int compare(OneAndZero o1, OneAndZero o2) {
                return Math.min(m - o2.countZero, n - o2.countOne) - Math.min(m - o1.countZero, n - o1.countOne);
            }
        });

        int countZero = findMax(zeroList, m, n);
        int countOne = findMax(oneList, m, n);

        return Math.max(countZero, countOne);
    }
    
    public int findMax(List<OneAndZero> list, int m, int n) {
        int count = 0;
        for (int i = 0; i < list.size(); i++) {
            if (m >= list.get(i).countZero && n >= list.get(i).countOne) {
                count++;
                m -= list.get(i).countZero;
                n -= list.get(i).countOne;
            }
        }
        return count;
    }
    
    class OneAndZero {
        String str;
        int countZero;
        int countOne;

        public OneAndZero(String str, int countZero, int countOne) {
            this.str = str;
            this.countZero = countZero;
            this.countOne = countOne;
        }
    }
}
__________________________________________________________________________________________________
sample 36572 kb submission
class Solution {
    public int findMaxForm(String[] strs, int m, int n) {
        int[][] dp = new int[m+1][n+1];
        for(String s:strs){
            int one = 0, zero = 0;
            for(char c:s.toCharArray()){
                if(c=='1'){
                    one++;
                }else{
                    zero++;
                }
            }
            for(int i=m;i>=zero;i--){
                for(int j=n;j>=one;j--){
                    dp[i][j] = Math.max(dp[i][j],dp[i-zero][j-one]+1);
                }
            }
        }

        return dp[m][n];
    }
}