__________________________________________________________________________________________________
2ms
public class Solution {
        public String multiply(String num1, String num2) {
            if (num1.equals("0") || num2.equals("0")) {
                return "0";
            }
            int[] result = new int[num1.length()+num2.length()];
            for (int i =num2.length()-1 ; i >=0; i--) {
                int x=num2.charAt(i)-'0';
                for (int j = num1.length()-1; j>=0; j--) {
                    int y=num1.charAt(j)-'0';
                    result[i+j+1]+=x*y;			
                }
            }
            int flag=0;
            for (int i = result.length-1; i >=0; i--) {
                int temp=0;
                temp=result[i]+flag;
                result[i]= temp %10;
                flag=temp/10;
            }
            StringBuilder sb = new StringBuilder();
            for (int i : result) {
                if (sb.length()==0&& i==0) {
                    continue;
                }else {
                    sb.append(i);
                }
            }
            return sb.toString();
        }
    }
__________________________________________________________________________________________________
4ms
public class Solution {
    public String multiply(String num1, String num2) {
        if(num1 == null && num2 == null) return null;
        if(num1 == null) return num2;
        if(num2 == null) return num1;
        StringBuilder s= new StringBuilder();
        int len1 = num1.length(), len2 = num2.length();
        int[] ret = new int[len1+len2];
        for(int i = len1-1; i >= 0; i--){
            for(int j = len2-1; j >= 0; j--){
                int product = (num1.charAt(i)-'0') * (num2.charAt(j) - '0');
                int pos1 = i+j;
                int pos2 = i+j+1;
                product += ret[pos2];
                ret[pos2] = product % 10;
                ret[pos1] += product/10;
            }
        }
        for(int x: ret){
            if(!(x ==0 && s.length() == 0)){
                s.append(x);
            }
        }
        
        return (s.length() == 0) ? "0" : s.toString();
    }
}
__________________________________________________________________________________________________
5ms
class Solution {
    public String multiply(String num1, String num2) {
        // Implement multiplication by hand
        //where each index 0...i... represents the 10^ith degree
        if (num1.equals("0") || num2.equals("0")) {
            return "0";
        }
        
        int[] product = new int[num1.length() + num2.length()]; 
        for (int i = 0; i < num1.length(); i++) {
            for (int j = 0; j < num2.length(); j++) {
                int n1 = num1.charAt(num1.length() - 1 - i) - '0';
                int n2 = num2.charAt(num2.length() - 1 - j) - '0';
                // System.out.println(n1*n2);
                // System.out.println(i + j);
                product[i + j] += n1*n2;
                
            
            }
        }
        
        String ans = "";
        for (int a = 0; a < product.length - 1; a++) {
            if (product[a] >= 10) {
                product[a + 1] += product[a] / 10;
                product[a] = product[a] % 10;
            }
            ans = product[a] + ans;
        }
        
        ans = product[product.length - 1] + ans;        
        
        int stripIdx = 0; 
        while (stripIdx < ans.length()) {
            if (ans.charAt(stripIdx) != '0') {
                break;
            }
            stripIdx++;
        }
        
        return ans.substring(stripIdx);
        
    }
}
__________________________________________________________________________________________________
35504 kb
class Solution {
    public String multiply(String num1, String num2) {
        int[] nums = new int[num1.length() + num2.length()];
        for(int i = num1.length()-1;i>=0;i--){
            for(int j = num2.length()-1;j>=0;j--){
                int val = (num1.charAt(i)-'0')*(num2.charAt(j)-'0');
                nums[i+j] += (val + nums[i+j+1])/10;
                nums[i+j+1] = (val + nums[i+j+1])%10;
            }
        }
        StringBuilder sb = new StringBuilder();
        int index = 0;
        while(index<nums.length && nums[index] == 0) index++;
        for(;index<nums.length;index++) sb.append(nums[index]);
        return sb.length() == 0 ? "0" : sb.toString();
    }
}
__________________________________________________________________________________________________
35644 kb
class Solution {
    public String multiply(String num1, String num2) {
        int len1 = num1.length();
        int len2 = num2.length() ;
        if((num1.length() == 1 && num1.charAt(0) == '0')|| (num2.length() == 1 && num2.charAt(0) == '0')) return "0"; 
        int[] product = new int[len1 + len2];
        for(int i = len1-1; i >= 0; i--){
            for(int j = len2-1; j >= 0; j--){
                int index = len1 + len2 - i - j -2;
                product[index] += (num1.charAt(i) - '0') * (num2.charAt(j) - '0');
                product[index + 1] += product[index]/10;
                product[index] %= 10;
            }
        }
        
        StringBuilder sb = new StringBuilder();
        for(int i = len1 + len2 -1; i >= 0; i--){
            if(i == len1 + len2 - 1 && product[i] == 0) continue;
            sb.append(product[i]);
        }
        return sb.toString();
    }
}

__________________________________________________________________________________________________