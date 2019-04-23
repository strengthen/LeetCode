__________________________________________________________________________________________________
1ms
class Solution {
    public int reverse(int x) {
        Integer x1=new Integer(x);
        char[] ch=Integer.toString(x).toCharArray();
        if(ch.length==0|| ch.length==1) return x;
        StringBuffer str=new StringBuffer();
        char[] ch1=new char[ch.length];
        int num=0;
        int a;
        if (ch[0]=='-'){
            for (int i=1; i<ch.length;i++){
                a=num*10+ch[ch.length-i]-48;
                if((a+48-ch[ch.length-i])/10!=num){
                    return 0;
                }
                num=a;
            }
            return -num;
        }else{
            for(int i=0;i<ch.length;i++){
                a=num*10+ch[ch.length-i-1]-48;
                if((a+48-ch[ch.length-i-1])/10!=num){
                    return 0;
                }
                num=a;
            }
            return num;
        }
    }
}
__________________________________________________________________________________________________
2ms
class Solution {
    public int reverse(int x) {
     try {
            String k = x + "";
            String result="";
            int length = k.length();
            for(int i=length-1;i>=0;i--){
                char index  = k.charAt(i);
                if(index<= 57 && index>=48){
                    result = result + index;
                }else {
                    result = index + result;
                }
            }
            return Integer.parseInt(result);
        } catch (NumberFormatException e) {
            return 0;
        }
    }
}
__________________________________________________________________________________________________
3ms
class Solution {
    public int reverse(int x) {
        String ans="";
        String k=x+"";
        
        String negative= x<0? "-":"";
         for(int i=k.length()-1;i>=0;i--)
         {
             if(k.charAt(i)!='-')
                ans+=k.charAt(i)+"";
         }
        String s=negative+ ans;
        Long l=Long.valueOf(s).longValue();
        
         if(l>Integer.MAX_VALUE||l<Integer.MIN_VALUE){
            return 0;
            }    
        return Integer.valueOf(s).intValue();
    }    
}
__________________________________________________________________________________________________
37536 kb 
class Solution {
    public int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > Integer.MAX_VALUE/10 || (rev == Integer.MAX_VALUE / 10 && pop > 7)) return 0;
            if (rev < Integer.MIN_VALUE/10 || (rev == Integer.MIN_VALUE / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
}
__________________________________________________________________________________________________
 37644 kb
class Solution {
    public int reverse(int x) {
        long res = 0;
        while(x != 0) {
            res = res*10 + x%10;
            if(res > Integer.MAX_VALUE || res < Integer.MIN_VALUE) {
                return 0;
            }
            x /= 10;
        }
        return (int)res;
    }
}
__________________________________________________________________________________________________
