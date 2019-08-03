__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    
    public boolean isRationalEqual(String S, String T) {
        String[] xs = parse(S);
        String[] ys = parse(T);
        
        // for(String x : xs) System.out.printf("%s,", x);
        // System.out.println();
        // for(String y : ys) System.out.printf("%s,", y);
        // System.out.println();
        
        return xs[0].equals(ys[0]) && xs[1].equals(ys[1]) && xs[2].equals(ys[2]);
    }
    
    String addOne(String s) {
        char[] xc = s.toCharArray();
        int i = xc.length-1,  c = 1;
        while(true) {
            int n = c + xc[i] - '0';
            xc[i] = (char)('0' + (n % 10));
            c = n / 10;
            i--;
            if (c == 0 || i < 0) break;
        }
        return new String(xc);   
    }
    boolean reduce(String p, String s) {
        // System.out.printf("reduce %s from s\n", p, s);
        if (p.length() > s.length()) return false;
        if (p.length() == s.length()) return p.equals(s);
        
        if (s.length() % p.length() != 0) return false;
        int n = p.length();
        
        if (!s.substring(0, n).equals(p)) return false;
        
        return reduce(p, s.substring(n));
    }
    
    String[] parse(String s) {
        String part1, part2, part3;
        int n = s.length();
        
        int i = s.indexOf('.');
        if (i == n-1 || i == -1) {
            if (i == n-1) s = s.substring(0, n-1);
            return new String[] {s, "0", ""};        
        }
        
        part1 = s.substring(0, i);
        int j = s.indexOf('(');
        if(j == -1) {
            part2 = s.substring(i+1);
            return new String[] {part1, part2, ""};
        }
        
        part2 = s.substring(i+1, j);
        part3 = s.substring(j+1, n-1);
        // System.out.printf(" s %s part2 %s part3 %s\n",s, part2, part3);
        
        for(int len = 1;  len <= part3.length() / 2 ; len++) {
            if (reduce(part3.substring(0, len), part3.substring(len))) {
                part3 = part3.substring(0,len);
                // System.out.printf("reduce part3 to %s\n",part3);
                break;
            }
        }
        
        while(part2.length() >= part3.length() && part2.substring(part2.length()-part3.length()).equals(part3))
            part2 = part2.substring(0, part2.length()-part3.length());
        // System.out.printf("part2 %s part3 %s\n",part2, part3);
        i = part2.length()-1; j = part3.length()-1;
        while(i >= 0 && j >= 0 && part2.charAt(i) == part3.charAt(j)) {
            i--; j--;
        }
        
        // System.out.printf("i %d j %d\n", i, j);
        
        part3 = part2.substring(i+1) + part3.substring(0, j+1);
        part2 = part2.substring(0, i+1);
        
        if (part3.equals("9")) {
            if (part2.equals("")) {
                part2 = "0";
                int t = Integer.parseInt(part1) + 1;
                part1 = String.valueOf(t);
            } else {
                part2 = addOne(part2);
            }
            part3 = "";
        }
        
        if (part3.equals("0")) part3 = "";
        if (part3.equals("") && part2.equals("")) part2 = "0";
        
        return new String[] {part1, part2, part3};
    }
}
__________________________________________________________________________________________________
sample 35512 kb submission
class Solution {
    // private final static double EPSILON = 0.0000000000000001; // 1 at place 16 (max after point digits in double)
    private final static double EPSILON = 0.000000001; // 1 at place 9
    public boolean isRationalEqual(String S, String T) {
        double s = parseDouble(S);
        double t = parseDouble(T);
        
        // System.out.println(s);
        // System.out.println(t);
        
        return Math.abs(s - t) <= EPSILON;
    }
    
    private double parseDouble(String string){
        String[] dotSeparated = string.split("\\.");        
        double myDouble = Double.parseDouble(dotSeparated[0]);
        
        if(dotSeparated.length > 1){
            boolean isRepeating = false;
            int repeatingStart = -1;
            char[] decimals = dotSeparated[1].toCharArray();
            double coeff = 0.1;
            for(int i = 0, count = 1; i < decimals.length && count < 17; i++){
                if(decimals[i] == '('){
                    repeatingStart = i;
                    continue;
                }else if(decimals[i] == ')'){
                    i = repeatingStart;
                    continue;
                }
                
                myDouble += (decimals[i]-'0') * coeff;
                
                coeff *= 0.1;
                count++;
            }
        }
        return myDouble;
    }
}
__________________________________________________________________________________________________
