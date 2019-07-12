__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int compress(char[] chars) {
        int index = 0;
        int count = 1;
        char cur = chars[0];
        for (int i = 1; i < chars.length; i++) {
            if (chars[i] == cur) count++;
            else {
                index = set(chars, cur, index, count);
                cur = chars[i];
                count = 1;
            }
        }
        index = set(chars, cur, index, count);
        return index;
    }
    
    public int set(char[] chars, char cur, int index, int count) {
        if (count == 1) {
            chars[index] = cur;
            index++;
        } 
        else {
            chars[index++] = cur;
            int inc = 0;
            while (count > 0) {
                chars[index + inc] = (char)('0' + count % 10);
                count /= 10;
                inc++;
            }
            swap(chars, index, index + inc - 1);
            index = index + inc;
        }
        return index;
    }
    
    public void swap(char[] chars, int i, int j) {
        while (i < j) {
            char temp = chars[i];
            chars[i] = chars[j];
            chars[j] = temp;
            i++;
            j--;
        }
    }
}
__________________________________________________________________________________________________
sample 36952 kb submission
class Solution {
    public int compress(char[] chars) {
         if (chars == null || chars.length ==0) return 0;
	        int count = 0;
	        Stack<Character> stack = new Stack<>();
	        for (int i=0; i<chars.length; i++) {
	            if ( stack.isEmpty() || stack.peek() == chars[i]) {
	                count++;
	            }else if (stack.peek() != chars[i] && count > 1) {
	            	count = helper(stack, chars, count);
	            }else{
	                count = 1;
	            }
	            if (i == chars.length-1 && count > 1) {
	            	stack.push(chars[i]);
	            	count = helper(stack, chars, count);
                  break;
            		
	            }
	            stack.push(chars[i]);
	        }
	        int total = stack.size();
	        int i= stack.size() -1;
	        while (i>=0) {
	            chars[i] = stack.pop();
	            i--;
	        }
	        return total;
    }
    
     public  int  helper(Stack stack, char [] chars, int count) {
		  
      	char[] counters= (count+"").toCharArray();
          while (count > 1) {
              stack.pop();
              count--;
          }
        for (int j= 0; j< counters.length; j++)
          stack.push(counters[j]);
        return count;
	  }
}
__________________________________________________________________________________________________
