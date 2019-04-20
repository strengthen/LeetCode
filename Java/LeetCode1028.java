class Solution {
    public TreeNode recoverFromPreorder(String S) {
        return helper(S, 1);
    }
    TreeNode helper(String S, int depth) {
        int index = S.indexOf("-");
        if (index == -1) {
            return new TreeNode(Integer.parseInt(S));
        }
        TreeNode root = new TreeNode(Integer.parseInt(S.substring(0, index)));
        index += depth;
        int start = index, count = 0;
        index = S.indexOf("-", index);
        while (index != -1) {
            count = 0;
            while (index != -1 && index < S.length() && S.charAt(index) == '-') {
                count++;
                index++;
            }
            if (count == depth) break;
            index = S.indexOf("-", index);
        }
        if (index == -1) {
            root.left = helper(S.substring(start), depth + 1);
            return root;
        }
        root.left = helper(S.substring(start, index - depth), depth + 1);
        root.right = helper(S.substring(index), depth + 1);
        return root;
    }
}