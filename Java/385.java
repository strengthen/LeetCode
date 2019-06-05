__________________________________________________________________________________________________
sample 2 ms submission
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *     // Constructor initializes an empty nested list.
 *     public NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     public NestedInteger(int value);
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // Set this NestedInteger to hold a single integer.
 *     public void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     public void add(NestedInteger ni);
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
class Solution {
    int current = 0;
    String str;
    public NestedInteger deserialize(String s) {
        this.current = 0;
        this.str = s;
        return this.expr();
    }
    
    private NestedInteger expr() {
        NestedInteger ni = new NestedInteger();
        if(str.charAt(current) != '[') {
            ni.setInteger(parseInt());
            return ni;
        }
        if(str.charAt(current+1) == ']') {
            current = current + 2;
            return new NestedInteger();
        }
        return this.nested();
    }
    
    private NestedInteger nested() {
        NestedInteger ni = new NestedInteger();
        if(str.charAt(current++) != '[') {} // error
        ni.add(this.expr());
        while(str.charAt(current) == ',') {
            ++current;
            ni.add(this.expr());
        }
        if(str.charAt(current++) != ']') {} // error
        return ni;
    }
    
    private int parseInt() {
        boolean negative = false;
        if(str.charAt(current) == '-') {
            negative = true;
            ++current;
        }
        int i = 0;
        while(current < str.length() && str.charAt(current) - '0' >= 0 && str.charAt(current) - '0' <= 9) {
            i = i * 10 + str.charAt(current) - '0';
            current = current + 1; 
        }
        return negative ? -1*i : i;
    }    
}
__________________________________________________________________________________________________
sample 38448 kb submission
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *     // Constructor initializes an empty nested list.
 *     public NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     public NestedInteger(int value);
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // Set this NestedInteger to hold a single integer.
 *     public void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     public void add(NestedInteger ni);
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
class Solution {
    public NestedInteger deserialize(String s) {
        if(s.charAt(0) != '[')
            return new NestedInteger(Integer.valueOf(s));
        
        Stack<NestedInteger> st = new Stack<>();
        int minus = 1;
        Integer num = null;
        NestedInteger ni = null;
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == '[') {
                if (ni != null)
                    st.push(ni);
                ni = new NestedInteger();
            }
            else if(s.charAt(i) == ']') {
                if(num != null)
                    ni.add(new NestedInteger(num*minus));
                if (!st.isEmpty()) {
                    st.peek().add(ni);
                    ni = st.pop();
                }
                minus = 1;
                num = null;
            }
            else if(s.charAt(i) == ',') {
                if(num != null)
                    ni.add(new NestedInteger(num*minus));
                minus = 1;
                num = null;
            }
            else if(s.charAt(i) == '-') {
                minus = -1;
            }
            else {
                if (num == null)
                    num = s.charAt(i) - '0';
                else
                    num = num * 10 + (s.charAt(i) - '0');
            }
        }
        return ni;
    }
}
__________________________________________________________________________________________________
