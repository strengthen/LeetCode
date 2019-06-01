__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public boolean isAdditiveNumber(String num) {
        if(num==null||num.length()==0) return true;
        int n1=0;
        for(int i=0;i<num.length()-2;i++){//end of n1
            if(n1==0&&i!=0) return false;//invalid n1
            n1=n1*10+(int)(num.charAt(i)-'0');
            int n2=0;
            for(int j=i+1;j<num.length()-1;j++){
                if(n2==0&&j!=i+1) break;//invalid n2
                n2=n2*10+(int)(num.charAt(j)-'0');
                if(find(num,j+1,n1,n2)) return true;
            }
        }
        return false;
    }
    
    private boolean find(String num,int start,int n1,int n2){
        if(start>=num.length()) return true;//find to end
        int n3=0;
        for(int i=start;i<num.length();i++){
            if(n3==0&&i!=start) return false;//first is 0
            n3=n3*10+(int)(num.charAt(i)-'0');
            if(n3-n1==n2) return find(num,i+1,n2,n3);
            if(n3-n1>n2) return false;//no match
        }
        return false;//no match
    }
}
__________________________________________________________________________________________________
sample 32568 kb submission
class Solution {
    public boolean isAdditiveNumber(String s) {
        return isAdditiveNumber(s, 0, 0L, 0L, 0);
    }
    public boolean isAdditiveNumber(String s, int index, long n1, long n2, int c) {   
        if(c > 2 && index == s.length()) return true; 
        long num = 0; 
        int i = index;
        while(index < s.length()){  
            int ch = s.charAt(index++) - '0';
            num = num * 10 + ch;
            while(num != 0 && ch == 0 && index < s.length() && s.charAt(index) == '0'){
                num = num * 10 +s.charAt(index++) - '0';
            } 
            if(n1 + n2  < num && c >= 2) break; 
            if((n1+n2 == num || c < 2) && isAdditiveNumber(s, index, n2, num, c+1))
                return true;
            if(num == 0) break;
        }
        return false;
    }
}
__________________________________________________________________________________________________
