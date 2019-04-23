__________________________________________________________________________________________________
3ms
class Solution {
            // Reversed
    private static final String[] ones = {
            "", "I", "II", "III", "VI", "V", "IV", "IIV", "IIIV", "XI",
    };

    private static final String[] tens = {
            "", "X", "XX", "XXX", "LX", "L", "XL", "XXL", "XXXL", "CX",
    };

    private static final String[] hundreds = {
            "", "C", "CC", "CCC", "DC", "D", "CD", "CCD", "CCCD", "MC",
    };

    private static final String[] thousands = {
            "", "M", "MM", "MMM",
    };

    public static String intToRoman(int num) {
        final StringBuilder builder = new StringBuilder();

        for (int i = 0; i < 4; i += 1) {
            final int digit = num % 10;

            switch (i) {
                case 3: {
                    builder.append(thousands[digit]);
                }
                break;
                case 2: {
                    builder.append(hundreds[digit]);
                }
                break;
                case 1: {
                    builder.append(tens[digit]);
                }
                break;
                case 0: {
                    builder.append(ones[digit]);
                }
                break;
            }

            num /= 10;

            if (num == 0) {
                break;
            }
        }

        return builder.reverse().toString();
    }
    
}
__________________________________________________________________________________________________
4ms
class Solution {
    public String intToRoman(int n) {
        int a,b,c,d;
        String M[] = {"","M","MM","MMM"};
        String C[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        String X[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        String I[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        a=n/1000;
        b=n%1000/100;
        c=n%100/10;
        d=n%10;
        return M[a]+C[b]+X[c]+I[d];
    }
}
__________________________________________________________________________________________________
5ms
class Solution {
    char a[][]={{'I','V','X'},{'X','L','C'},{'C','D','M'},{'M',' ',' '}};
    public String intToRoman(int num) {
        int n=num,c=0;
        
        String str="";
        while(n>0){
            int r=n%10;
            str=getIt(r,c++)+str;
            n=n/10;
        }
        return str;
    }
    public String getIt(int num,int c) {
        switch(num){
                case 1:return ""+a[c][0];
                case 2:return ""+a[c][0]+a[c][0];
                case 3:return ""+a[c][0]+a[c][0]+a[c][0];
                case 4:return ""+a[c][0]+a[c][1];
                case 5:return ""+a[c][1];
                case 6:return ""+a[c][1]+a[c][0];
                case 7:return ""+a[c][1]+a[c][0]+a[c][0];
                case 8:return ""+a[c][1]+a[c][0]+a[c][0]+a[c][0];
                case 9:return ""+a[c][0]+a[c][2]; 
        }
        return ""; 
    }
}
__________________________________________________________________________________________________
38592 kb
class Solution {
    String[] symbols = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int[] values = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    public String intToRoman(int num) {
        int total = 0;
        StringBuilder sb = new StringBuilder();
        for(int i = values.length-1; i >= 0 && total < num; i--) {
            while (total + values[i] <= num) {
                total += values[i];
                sb.append(symbols[i]);
            }
        }
        return sb.toString();
    }
}
__________________________________________________________________________________________________
38648 kb
class Solution {
    public String intToRoman(int num) {
        StringBuilder sb = new StringBuilder();
        if(num < 1 || num > 3999) return sb.toString();
        
        int[] numbers = new int[]{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        String[] roman = new String[]{"M", "CM", "D", "CD", "C", "XC", "L", "XL","X", "IX", "V", "IV", "I"};
        
        for(int i = 0; i < numbers.length; i++){
            if(num == 0) break;
            int count = num / numbers[i];
            if(count == 0) continue;
            num -= count * numbers[i];
            for(int j = 0; j < count; j++){
                sb.append(roman[i]);
            }
        }
        
        return sb.toString();
    }
}
__________________________________________________________________________________________________
