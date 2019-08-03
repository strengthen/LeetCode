__________________________________________________________________________________________________
sample 1 ms submission
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode recoverFromPreorder(String S) {
		if (S == null || S.isEmpty())
			return null;
		int[] index = new int[1];
		index[0] = 0;
		return recoverMyTree(S, index, 0);
	}

	public TreeNode recoverMyTree(String S, int[] index, int depth) {
		if (index[0] >= S.length())
			return null;
		int count = 0;
		for (int i = index[0]; i < S.length() && S.charAt(i) == '-'; i++)
			count++;
		TreeNode node = null;
		if (count == depth) {
			index[0] += count;
			node = new TreeNode(getNumber(S, index));
			node.left = recoverMyTree(S, index, depth + 1);
			node.right = recoverMyTree(S, index, depth + 1);
		}
		return node;
	}

	public int getNumber(String S, int[] index) {
		int number = 0;
		int mult = 10;
		while (index[0] < S.length() && S.charAt(index[0]) != '-') {
			number = (number * mult) + Character.getNumericValue(S.charAt(index[0]));
			index[0]++;
		}
		return number;
	}
}
__________________________________________________________________________________________________
sample 36096 kb submission
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    
    public TreeNode recoverFromPreorder( String S ) {
        if( S.isEmpty())
            return null;
        int index = S.indexOf( '-' );
        if( index == -1 )
            return new TreeNode( Integer.parseInt( S ));
        PriorityQueue<Priority> q = parseString( S.substring( index ));
        TreeNode root = new TreeNode( Integer.parseInt( S.substring( 0, index )));
        return recoverBranch( root, q, (short) 1 );
    }

    private PriorityQueue<Priority> parseString( String s ) {
        PriorityQueue<Priority> q = new PriorityQueue<>( ( o1, o2 ) ->
                o1.branch < o2.branch ? -1 : o1.branch == o2.branch ? o1.depth - o2.depth : 1 );
        int depth = 0;
        int next;
        int branch = 0;
        String val;
        for( int i = 0; i < s.length(); i++ ){
            if( s.charAt( i ) == '-' ) depth++;
            else{
                next = s.indexOf( '-', i );
                if( next == -1 )
                    val = s.substring( i );
                else
                    val = s.substring( i, next );
                q.add( new Priority( Integer.parseInt( val ), (short) depth, branch++ ));
                i = next == -1 ? s.length() : next-1;
                depth = 0;
            }
        }
        return q;
    }

    private TreeNode recoverBranch( TreeNode root, PriorityQueue<Priority> q, short depth ){
        if( q.peek() != null && q.peek().depth == depth ){ // если есть элемент и идем вглубь
            Priority p = q.poll();
            root.left = new TreeNode( p.val );
            if( q.peek() != null && q.peek().depth == depth+1 ){ // если дети
                root.left = recoverBranch( root.left, q, (short) (depth+1) );
            }
            if( q.peek() != null && q.peek().depth == depth ){ // если есть правый
                p = q.poll();
                root.right = new TreeNode( p.val );
                if( q.peek() != null && q.peek().depth == depth+1 ){ // если дети
                    root.right = recoverBranch( root.right, q, (short) (depth+1) );
                }
            }
        }
        return root;
    }

    private class Priority{
        int val;
        short depth;
        int branch;
        Priority(int val, short depth, int branch ){
            this.val = val;
            this.depth = depth;
            this.branch = branch;
        }
    }    
}
__________________________________________________________________________________________________
