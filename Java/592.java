__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public String fractionAddition(String expression1) {
        if(expression1.length()==0){
            return "0/1";
        }
        String expression;
        if(expression1.charAt(0)!='-'){
            expression = "+" + expression1;
        }else{
            expression = expression1;
        }
        int nume = 0;
        int deno = 0;
        int tnume = 0;
        int tdeno = 0;
        
        for(int i=0; i<expression.length(); i++){
            if(expression.charAt(i)=='-'){
                if(expression.charAt(i+2) == '/'){
                    nume = -1*Character.getNumericValue(expression.charAt(i+1));
                    i++;
                }else{
                    nume = -10;//String.valueOf(expression.substring(i+1,i+3));
                    i=i+2;
                }
            }
            if(expression.charAt(i)=='+'){
                if(expression.charAt(i+2) == '/'){
                    nume = Character.getNumericValue(expression.charAt(i+1));
                    i++;
                }else{
                    nume = 10;
                    i=i+2;
                }
            }
            if(expression.charAt(i)=='/'){
                if(i+2==expression.length() || expression.charAt(i+2) == '+' || expression.charAt(i+2) == '-'){
                    deno = Character.getNumericValue(expression.charAt(i+1));
                    i++;
                }else{
                    deno = 10;
                    i=i+2;
                }
                if(tdeno == 0){
                    tnume = nume;
                    tdeno = deno;
                }else{
                    if(tdeno%deno == 0){
                        tnume += nume*(tdeno/deno);
                    }else{
                        tnume = tnume*deno + nume*tdeno;
                        tdeno = tdeno * deno;
                    }
                }
            }
        }
        int gcd = 0;
        if(tnume == 0){
            return "0/1";
        }else if(tnume < 0){
            gcd = GCD(-1*tnume, tdeno);
        }else{
            gcd = GCD(tnume, tdeno);
        }
        tnume = tnume/gcd;
        tdeno = tdeno/gcd;
        return String.valueOf(tnume) +"/"+String.valueOf(tdeno);
        
    }
    private int GCD(int a, int b){
        if(b == 0){
            return a;
        }
        while(true){
            int tmp = a%b;
            if(tmp == 0){
                return b;
            }else{
                a = b;
                b = tmp;
            }
        }
        
    }
}
__________________________________________________________________________________________________
sample 35716 kb submission
class Solution {
    public String fractionAddition(String expression) {
      ArrayList<Integer> numerators = new ArrayList<Integer>();
      
      int denominator = 0;
      int last = expression.length() - 1;
      while(last >= 0){
        //get the denominator
        int d = expression.charAt(last--) - '0'; 
        if(expression.charAt(last--) == '1'){
          d = 10;
          last--;
        }
        
        //get the numerator
        int n = expression.charAt(last--) - '0';
        if(last >= 0){
          if(expression.charAt(last) == '1'){
            n = 10;
            last--;
          }
          
          if(last >= 0 && expression.charAt(last--) == '-') n *= -1;
        }
        
        //calculate the new overall denominator
        //calculate the new numerator based on the overall denominator
        if(denominator == 0){
          denominator = d;
        } else {
          if(denominator % d != 0){
            n *= denominator;
            denominator *= d;
            for(int i = 0; i < numerators.size(); i++){
              numerators.set(i,numerators.get(i) * d);
            }
          } else {
            n *= (denominator/d);
          }
        }
        
        //add to the arraylist of numerators
        numerators.add(n);
      }
      
      //get the total numerator sum
      int numerator = 0;
      for(int i = 0; i < numerators.size(); i++){
        numerator += numerators.get(i);
      }
      
      //do some simplifying
      for(int i = 10; i > 0; i--){
        if(numerator % i == 0 && denominator % i == 0){
          numerator = numerator / i;
          denominator = denominator /i;
        }
      }
      
      return "" + numerator + "/" + denominator;
    }
}
__________________________________________________________________________________________________
