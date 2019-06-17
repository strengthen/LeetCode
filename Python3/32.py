__________________________________________________________________________________________________
sample 36 ms submission
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        length = len(s)
        stack = [0]*length # note that list can add and multi !
        top = -1
        last = -1
        Max = 0
        
        for i in range(0,length):
            # push into stack if there is new '('
            if s[i]=='(':
                top = top + 1
                stack[top] = i
            elif top >= 0:
                # pop stack if there is element in stack
                top = top -1
                
                # either stak is empty, then we need last starting point
                # or we need to fecth begin point
                if top>=0:
                    begin =stack[top] #+ 1
                else:
                    begin = last
                l = i - begin #+1  # the current length
                
                if(Max < l): # update the max if necessary
                    Max = l
            else: # this char is ')' and top < 0
                # the stack is empty and we see ")", we need to update the last good starting point seen
                last = i #+1
        
        return Max

    # the solution has +1, but if we use last =-1 to solve the "()"" case 
    # (which last is not touched but used, we can remove all +1)
# https://leetcode.com/problems/longest-valid-parentheses/discuss/305042/Java-Solution-using-an-array-as-stack        
        
        """
        public int longestValidParentheses(String s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = s.length();
        int [] stack = new int[len];
        int top = -1;
        int last = 0;
        int max = 0;
        for (int i = 0; i < len; i++) {
		    // Push into stack for new '('
            if (s.charAt(i) == '(') {
                stack[++top] = i;
            } else if (top >= 0) {
			    // Pop stack if there is element
                top--;
				// Either the stack is empty, then we need the last starting point seen.
				// Or we just directly fetch the matched beginning point
                int begin = top >= 0 ? stack[top] + 1 : last;
                int l = i - begin + 1;
                if (max < l){
                    max = l;
                }
            } else {
			    // Stack is empty, but we see ')', meaning we should update the last good starting point seen
                last = i + 1;
            }
        }
        return max;
    }
}
        """
__________________________________________________________________________________________________
sample 12944 kb submission
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        r=0
        l=0
        pointer=0
        max_so_far = 0
        curr_max = 0
        
        for i in range(len(s)):
            if s[i]=='(':
                l += 1
            else:
                r += 1
            if r>l:
                l=0
                r=0
                curr_max = 0
                pointer = i+1
            elif l==r:
                curr_max += (i-pointer)+1
                l=0
                r=0
                pointer = i+1
                max_so_far = max(max_so_far, curr_max)
        r=0
        l=0
        pointer=len(s)-1
        curr_max = 0
        for i in range(len(s)):
            if s[len(s)-1-i]=='(':
                l += 1
            else:
                r += 1
            if l>r:
                l=0
                r=0
                curr_max = 0
                pointer = (len(s)-1-i)-1
            elif l==r:
                curr_max += (pointer -(len(s)-1-i))+1
                l=0
                r=0
                pointer = (len(s)-1-i)-1
                max_so_far = max(max_so_far, curr_max)
        return max_so_far 
 
__________________________________________________________________________________________________
