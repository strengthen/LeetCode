__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        
        if (numerator == 0) return "0";
        StringBuilder sb = new StringBuilder();
        sb.append(((numerator > 0) ^ (denominator > 0)) ? "-" : "");
        long num = (long) numerator;
        long denom = (long) denominator;
        num = Math.abs(num);
        denom = Math.abs(denom);
        sb.append(num / denom);
        long rem = num % denom;
        if (rem == 0) {
            return sb.toString();
        }
        
        sb.append(".");
        Map<Long, Integer> map = new HashMap<>();
        
        StringBuilder tmp = new StringBuilder();
        int pos = 0;
        while (rem != 0) {
            if (map.containsKey(rem)) {
                tmp.insert(map.get(rem), "(");
                tmp.append(")");
                return sb.append(tmp).toString();
            }
            map.put(rem, pos);
            
            tmp.append(10*rem/denom);
            rem = 10 * rem % denom;;
            pos++;
        }
        return sb.append(tmp).toString();
    }
}
__________________________________________________________________________________________________
sample 35300 kb submission
class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        StringBuilder answ = new StringBuilder();
        if ((numerator>0&&denominator<0) || (numerator<0&&denominator>0)) answ.append("-");
        long num = Math.abs((long) numerator);
        long den = Math.abs((long) denominator);
        answ.append(num/den);
        num %= den;
        if (num == 0) return answ.toString(); 
        answ.append(".");
        HashMap <Long, Integer> hsm = new HashMap <Long, Integer>();
        hsm.put(num, answ.length());
        while(num!=0){
            num *= 10;
            answ.append(num/den);
            num %= den;
            if (hsm.containsKey(num)){
                int index = hsm.get(num);
                answ.append(")");
                answ.insert(index, "(");
                break;
            }else{
                hsm.put(num, answ.length()); 
            }
        }
        return answ.toString();
    }
}
__________________________________________________________________________________________________
