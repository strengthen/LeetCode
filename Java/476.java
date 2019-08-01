__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int findComplement(int num) {
        num^=((Integer.highestOneBit(num) << 1) - 1);
        return num;
    }
}
__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int findComplement(int num) {
        
        String num1=Integer.toString(num,2);
        StringBuilder sb=new StringBuilder();
        for(int i=0;i<num1.length();i++)
        {
            sb.append(num1.charAt(i)=='0'?1:0);
        }
        
        return Integer.parseInt(sb.toString(),2);
        
    }
}
__________________________________________________________________________________________________
sample 31788 kb submission
class Solution {
    public int findComplement(int num) {
        StringBuilder result = new StringBuilder();
        while (num > 0) {
            if (num % 2 == 1) {
               result.append('0');
            } else {
                result.append('1'); 
            }
            num = num >>> 1;
        }
        return Integer.parseInt(result.reverse().toString(), 2);
    }
}