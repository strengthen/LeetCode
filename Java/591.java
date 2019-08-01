__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public static final String OPEN_TAG = "<";
    public static final String OPEN_END_TAG = "</";
    public static final String CLOSE_TAG = ">";
    public static final String START_CDATA = "<![CDATA[";
    public static final String END_CDATA = "]]>";
    
    public boolean isValid(String code) {
        Deque<String> stack = new LinkedList<>();
        for(int i = 0; i < code.length();) {
            //System.out.println(i + " " + code.charAt(i));
            if(i > 0 && stack.isEmpty()) return false;
            if(code.startsWith(START_CDATA, i)) {
                int j = i + 9;
                i = code.indexOf(END_CDATA, j);
                if(i < 0) return false;
                i += 3;
            } else if (code.startsWith(OPEN_END_TAG, i)) {
    
                int j = i + 2;
                i = code.indexOf(CLOSE_TAG, j);
                String s = code.substring(j, i++); 
                
                if(stack.isEmpty() || !stack.pop().equals(s)) return false;
                
            } else if(code.startsWith(OPEN_TAG, i)) {
                int j = i + 1;
                i = code.indexOf(CLOSE_TAG, j);
                if(i < 0 || i == j || i - j > 9) return false;
                for(int k = j; k < i; k++) {
                    if(!Character.isUpperCase(code.charAt(k))) return false;
                }
                String s = code.substring(j, i++);
                stack.push(s);
            } else {
                i++;
            }
        }
        return stack.isEmpty();
    }
}
__________________________________________________________________________________________________
sample 36748 kb submission
class Solution {
    public boolean isValid(String code) {
        if (code.charAt(0) != '<' || code.charAt(code.length() - 1) != '>')
			return false;

		Stack<String> stack = new Stack<>();
		boolean[] contains_tag = new boolean[] { false };

		for (int i = 0; i < code.length(); i++) {
			boolean ending = false;
			int closeindex;

			if (stack.isEmpty() && contains_tag[0])
				return false;

			if (code.charAt(i) == '<') {
				if (!stack.isEmpty() && code.charAt(i + 1) == '!') {
					closeindex = code.indexOf("]]>", i + 1);
					if (closeindex < 0 || !isValidCdata(code.substring(i + 2, closeindex)))
						return false;
				} else {
					if (code.charAt(i + 1) == '/') {
						i++;
						ending = true;
					}

					closeindex = code.indexOf('>', i + 1);
					if (closeindex < 0
							|| !isValidTagName(code.substring(i + 1, closeindex), ending, stack, contains_tag))
						return false;
				}

				i = closeindex;
			}
		}

		return stack.isEmpty() && contains_tag[0];
	}

	public boolean isValidTagName(String s, boolean ending, Stack<String> stack, boolean[] contains_tag) {
		if (s.length() < 1 || s.length() > 9)
			return false;

		for (int i = 0; i < s.length(); i++) {
			if (!Character.isUpperCase(s.charAt(i)))
				return false;
		}

		if (ending) {
			if (!stack.isEmpty() && stack.peek().equals(s))
				stack.pop();
			else
				return false;
		} else {
			contains_tag[0] = true;
			stack.push(s);
		}

		return true;
	}

	public boolean isValidCdata(String s) {
		return s.indexOf("[CDATA[") == 0;
    }
}
__________________________________________________________________________________________________
