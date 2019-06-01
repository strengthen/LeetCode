__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public boolean isValidSerialization(String preorder) {
        int result = validatePreorderSerialization(preorder, 0);
		//--if the return value is -1 or
        //if the return number is less than length of the input means, the entire array is not iterated hence result should be false
    	if(result == -1 || preorder.length()-1 != result){
            return false;
        }
        else{
            return true;
        }
	}

	private static int validatePreorderSerialization(String preorder, int i) {
		if(preorder.charAt(i) == '#') {
			return i;
		}
		int in = pushuntilnextComma(preorder, i);
		
		if(in == -1 || i > preorder.length()-1) {
			return -1;
		}
		//in the preorder, the node next to root is left subtree root, 
		//hence, we will verify if the left subtree preorder serialized or not by passing next immediate(after comma) element
		int left = validatePreorderSerialization(preorder, in);
		if(left == -1) {
			return -1;
		}
		left = pushuntilnextComma(preorder, left);
		if(left == -1 || left > preorder.length()-1) {
			return -1;
		}
		//the left check will return when the after the complete subtree is over and the returned index will be root(starting point) of the right subtree 
		/* this is to verify if right sub tree is preorder serialized */
		int right = validatePreorderSerialization(preorder, left);
		return right;
	}
	
	/* Incase of there are double digit numbers then push them until we reach next comma */
	private static int pushuntilnextComma(String preorder, int i) {
		while(preorder.charAt(i) != ',') {
			++i;
			if(i > preorder.length()-1) return -1;
		}
		return i+1;
	}
}
__________________________________________________________________________________________________
sample 34032 kb submission
class Solution {
    public boolean isValidSerialization(String preorder) {
        String[] nodes = preorder.split(",");
        Stack<String> st = new Stack<>();
        for (int i = 0; i < nodes.length; i++) {
            String cur = nodes[i];
            if (cur.equals("#")) {
                while (!st.isEmpty() && st.peek().equals("#")) {
                    st.pop();
                    if (st.isEmpty()) {
                        return false;
                    }
                    st.pop();
                }
            }
            st.push(cur);
        }
        return st.size() == 1 && st.peek().equals("#");
    }
}
__________________________________________________________________________________________________
