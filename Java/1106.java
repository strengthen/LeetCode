__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    int len;
	int pos;
	char[] carr = null;

	public boolean parseBoolExpr(String expression) {
		carr = expression.toCharArray();
		len = carr.length;
		pos = 0;

		boolean res = exp();
		if (pos != len)
			return false;
		return res;
	}

	boolean exp() {
		if (carr[pos] == 'f') {pos++;
			return false;
		}
		if (carr[pos] == 't'){pos++;
			return true;
		}
		if (carr[pos] == '!') {
			pos++;
			if (carr[pos] != '(')
				return false;
			pos++;
			boolean res = exp();
			if (carr[pos] != ')')
				return false;
			pos++;
			return !res;
		}
		if (carr[pos] == '&') {
			pos++;
			if (carr[pos] != '(')
				return false;
			pos++;
			boolean temp = true;
			
			while (true) {
				boolean t = exp();
				temp &= t;
				if (carr[pos] == ')') break;
				pos++;
			}
			if (carr[pos] == ',') return false;
			
			pos++;
			return temp;
		}
		if (carr[pos] == '|') {
			pos++;
			if (carr[pos] != '(')
				return false;
			pos++;
			boolean temp = false;
			while (true) {
				boolean t = exp();
				temp |= t;
				
				if (carr[pos] == ')') break;
				
				
				pos++;
			}
			if (carr[pos] == ',') return false;
			pos++;
			return temp;
		}
		return false;
	}
    
}
__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public boolean parseBoolExpr(String expression) {
        if (expression.length()==1)return expression.equals("t");
        else if (expression.charAt(0)=='!')return !parseBoolExpr(expression.substring(2,expression.length()-1));
        else{
            char c=expression.charAt(0);
            int cnt=0,start=2;
            for (int i=1;i<expression.length();i++){
                char t=expression.charAt(i);
                if (t=='(')cnt++;
                if (t==')')cnt--;
                if (cnt==1&&t==','){
                    if (c=='&'&&parseBoolExpr(expression.substring(start,i))==false)return false;
                    if (c=='|'&&parseBoolExpr(expression.substring(start,i))==true)return true;
                    start=i+1;
                }
            }
            return parseBoolExpr(expression.substring(start,expression.length()-1));
            
        }
    }
}
__________________________________________________________________________________________________
