__________________________________________________________________________________________________
0ms
class Solution {
    public boolean isValid(String s) {
        char stack[] = new char[s.length()];
        int top = -1;
        char current;
        for(int i = 0; i < s.length(); i++)
        {
            current = s.charAt(i);
            if(current =='(' || current =='[' || current == '{'){
                stack[++top] = current;   
            }
            else
            {
                if(top == -1)
                    return false;
                else if(current == ')' && stack[top] != '(')
                    return false;
                else if(current == ']' && stack[top] != '[')
                    return false;
                else if(current == '}' && stack[top] != '{')
                    return false;
                else
                    top--;
            }    
        }
        if(top == -1)
            return true;
        return false;
    }
}
__________________________________________________________________________________________________
1ms
class Solution {
    public boolean isValid(String s) {
   	Stack<Character> stack = new Stack<Character>();
	for (char c : s.toCharArray()) {
		if (c == '(')
			stack.push(')');
		else if (c == '{')
			stack.push('}');
		else if (c == '[')
			stack.push(']');
		else if (stack.isEmpty() || stack.pop() != c)
			return false;
	}
	return stack.isEmpty();
        
    }
}
__________________________________________________________________________________________________
2ms
class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<Character>();
        
        for(int i=0; i<s.length(); i++) {
            if(s.charAt(i) == '(' || s.charAt(i) == '[' || s.charAt(i) == '{') {
                stack.push(s.charAt(i));
            } else {
                if(stack.empty()) {
                    return false;
                }
                Character val = stack.pop();
                // System.out.println(val);
                if(!((val == '(' && s.charAt(i) == ')') || (val == '[' && s.charAt(i) == ']') || (val == '{' && s.charAt(i) == '}'))) {
                    return false;
                }
            }
        }
        if(stack.empty()) {
            return true;
        } else {
            return false;
        }
        
    }
}
__________________________________________________________________________________________________
34152 kb
class Solution {
    public boolean isValid(String s) {
		if (s.isEmpty())
			return true;
		Map<Character, Character> map = new HashMap<>();
		map.put(')', '(');
		map.put(']', '[');
		map.put('}', '{');
		Stack<Character> stack = new Stack<>();
		if (s.length() % 2 != 0)
			return false;
		for (int i = 0; i < s.length(); i++) {
			if (map.containsKey(s.charAt(i))) {
				// close
				if (stack.isEmpty())
					return false;
				Character c = stack.pop();
				if (map.get(s.charAt(i)) != c) {
					return false;
				}
			}
			if(map.containsValue(s.charAt(i))){
				//open
				stack.add(s.charAt(i));
				continue;
			}
		}
		if(!stack.isEmpty())
			return false;
		return true;	
    }
}
__________________________________________________________________________________________________
34236 kb
class Solution {
    public boolean isValid(String s) {
    Map<String, String> CoupleString = new HashMap<String, String>();
    CoupleString.put(")","(");
    CoupleString.put("}","{");
    CoupleString.put("]","[");
    Stack<String> aCharStringStack = new Stack<String>();
    aCharStringStack.empty();
    for(int i =0;i<s.length();i++){
      String aCharStr = s.substring(i,i+1);
      if(!aCharStringStack.isEmpty()){
        String aCharOfStack = aCharStringStack.pop();
        if(!aCharOfStack.equals(CoupleString.get(aCharStr))){
          aCharStringStack.push(aCharOfStack);
          aCharStringStack.push(aCharStr);
        }
      }else {
        aCharStringStack.push(aCharStr);
      }
    }
    return aCharStringStack.empty();
    }
}
__________________________________________________________________________________________________
