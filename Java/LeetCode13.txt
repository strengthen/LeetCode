__________________________________________________________________________________________________
3ms
class Solution {
    public int romanToInt(String s) {
        int n=s.length();
        int sum=0;
        char[] text=s.toCharArray();
        for(int i=n-1;i>=0;i--){
            char c= text[i];
            switch(c){
                case 'I':{
                    if(i<n-1)
                        switch(text[i+1]){
                            case 'V':
                            case 'X':
                                sum--;
                                break;
                            default:
                                sum++;
                        }
                    else
                        sum++;
                }break;
                    
                case 'V':
                    sum+=5;
                    break;
                case 'X':{
                    if(i<n-1)
                        switch(text[i+1]){
                            case 'L':
                            case 'C':
                                sum-=10;
                                break;
                            default:
                                sum+=10;
                        }
                    else
                        sum+=10;
                }break;
                case 'C':{
                    if(i<n-1)
                        switch(text[i+1]){
                            case 'D':
                            case 'M':
                                sum-=100;
                                break;
                            default:
                                sum+=100;
                        }
                    else
                        sum+=100;
                }break;
                 case 'L':
                    sum+=50;
                    break;
                 case 'D':
                    sum+=500;
                    break;
                 case 'M':
                    sum+=1000;
                    break;
            }            
        }        
        return sum;        
    }
}
__________________________________________________________________________________________________
4ms
class Solution {
    private static Map<Character, Integer> map = new HashMap() {{
        put('I', 1);
        put('V', 5);
        put('X', 10);
        put('L', 50);
        put('C', 100);
        put('D', 500);
        put('M', 1000);
    }
    };
    public int romanToInt(String s) {
        int preValue = 0;
        int rs = 0;
        for (int i = s.length()-1 ; i >= 0; i--) {
            char c = s.charAt(i);
            Integer curValue = map.get(c);
            if(preValue > curValue){
                rs -= curValue;
            }else{
                rs += curValue;
            }
            preValue = curValue;
        }
        return rs;
    }
}
__________________________________________________________________________________________________
5ms
class Solution {
    public int romanToInt(String s) {
        ArrayList<Integer> n = new ArrayList<Integer>();
        int res = 0;
        for(int i = 0; i < s.length(); i++){
            switch(s.charAt(i)){
                case 'M':
                    n.add(1000);
                    break;
                case 'D':
                    n.add(500);
                    break;
                case 'C':
                    n.add(100);
                    break;
                case 'L':
                    n.add(50);
                    break;
                case 'X':
                    n.add(10);
                    break;
                case 'V':
                    n.add(5);
                    break;
                case 'I':
                    n.add(1);
                    break;
                default:
                    break;
            }
        }
        for(int i = 0; i + 1 < n.size(); i++){
            if(n.get(i) < n.get(i+1))
                res -= n.get(i);
            else
                res += n.get(i);
        }
        res += n.get(n.size() - 1);
        return res;
    }
}
__________________________________________________________________________________________________
35796 kb
class Solution {
    public int romanToInt(String s) {
        char[] ch = new char[s.length()];
		int[] num = new int[ch.length];
		int res=0;
		ch = s.toCharArray();
		for(int i = 0; i<ch.length; ++i){
			switch (ch[i]) {
			case 'I': num[i] = 1; break;
			case 'V': num[i] = 5; break;
			case 'X': num[i] = 10; break;
			case 'L': num[i] = 50; break;
			case 'C': num[i] = 100; break;
			case 'D': num[i] = 500; break;
			case 'M': num[i] = 1000; break;
			default:
				return -1;
			}
		}
		for(int i=0; i<num.length; ++i){
			if (i+1==num.length || num[i]>=num[i+1]) {
				res+= num[i];
			}else {
				res += num[i+1]-num[i];
				++i;
			}
		}
		return res;
    }
}
__________________________________________________________________________________________________
35852 kb
class Solution {
    public int romanToInt(String s) {        
        int sum = 0;
                
        int curr;
        int next;
        
        for(int i = 0; i < s.length() - 1; i++) {
            curr = getValue(s.charAt(i));
            next = getValue(s.charAt(i+1));
            sum = curr < next ? sum - curr : sum + curr;
        }
                
        sum += getValue(s.charAt(s.length() -1));
        
        return sum;
    }
    
    private static int getValue(char c){
        switch (c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
        
    }
}
__________________________________________________________________________________________________
