__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public String complexNumberMultiply(String a, String b) {
        int r1, r2, i1,  i2, real, im;
        int split = a.indexOf("+");
        r1 = Integer.parseInt(a.substring(0,split));
        i1 = Integer.parseInt(a.substring(split+1,a.length()-1));
        split = b.indexOf("+");
        r2 = Integer.parseInt(b.substring(0,split));
        i2 = Integer.parseInt(b.substring(split+1,b.length()-1));
        
        real = r1*r2 - i1*i2;
        im = r1*i2 + r2*i1;
        
        String ans = Integer.toString(real) + "+" + Integer.toString(im) + "i";
        
        return ans;
    }
}
__________________________________________________________________________________________________
sample 35524 kb submission
class Solution {
    public String complexNumberMultiply(String a, String b) {
        String[] aArray = a.split("\\+");
        int aa1 = Integer.valueOf(aArray[0]);
        int ab1 = Integer.valueOf(aArray[1].substring(0, aArray[1].length()-1));
        
        String[] bArray = b.split("\\+");
        int ba2 = Integer.valueOf(bArray[0]);
        int bb2 = Integer.valueOf(bArray[1].substring(0, bArray[1].length()-1));
        
        int first = aa1 * ba2 - ab1 * bb2;
        int second = aa1 * bb2 + ba2 * ab1;
        
        String s = String.valueOf(first) + "+" + String.valueOf(second) + "i";
        return s;
    }
}
__________________________________________________________________________________________________
