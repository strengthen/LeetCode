__________________________________________________________________________________________________
sample 2 ms submission

class Solution {
    //Map<Integer, List<Count>> counts = new HashMap<>();
    
    Count[] count2 = new Count[16];
    int countSize = 0;
    
    private static class Count {
        int count;
        TreeNode tree;
        int hash;
        Count next;
        
        public Count(TreeNode tree, int count, int hash){
            this.tree = tree;
            this.count = count;
            this.hash = hash;
        }
    }    
    
    public List<TreeNode> findDuplicateSubtrees(TreeNode root) { 
        List<TreeNode> result = new ArrayList<>();
        addDuplicates(root, result);
        return result;
    }
    
    /**
     * Recursiverly compute a hash code and test the noe for duplicate
     */
    private int addDuplicates(TreeNode root, List<TreeNode> result){
        if (root == null){
            return -1;
        }
        
        int hash = Integer.hashCode(root.val);
        hash = hash * 31 + addDuplicates(root.left, result);
        hash = hash * 31 + addDuplicates(root.right, result);
        addCandidate(hash, root, result);
        return hash;
    }
    
    /**
     * Maintain a count of deeply equale sub trees and add the given tree to the result 
     * list if and only if this count is 2.
     */
    private void addCandidate(int hash, TreeNode tree, List<TreeNode> result){
        if (countSize > .75F * count2.length){
            Count[] newCount = new Count[count2.length * 2];
            for (Count b : count2){
                if (b != null){
                    addCount(b, newCount);
                }
            }
            count2 = newCount;
        }
        
        int optHash = hash ^ (hash >>> 16);
        int bucketIdx = optHash & (count2.length - 1);
        Count bucket = count2[bucketIdx];
        if (bucket == null){
            bucket = new Count(tree, 1, optHash);   
            countSize++;
            count2[bucketIdx] = bucket;
        } else {
            while (bucket != null) {
                if (deepEqual(tree, bucket.tree)){
                    if (++bucket.count == 2){
                        result.add(tree);
                    }
                    return;
                }
                bucket = bucket.next;
            }
            bucket = new Count(tree, 1, optHash);
            bucket.next =  count2[bucketIdx];
            count2[bucketIdx] = bucket;
        }
    }
    
    private void addCount(Count buck, Count[] buckets){  
        while (buck != null){
            Count next = buck.next;
            buck.next = null;
            
            int bucketIdx = buck.hash & (buckets.length - 1);
            if (buckets[bucketIdx] == null){
                buckets[bucketIdx] = buck;
            } else {
                buck.next = buckets[bucketIdx];
                buckets[bucketIdx] = buck;
            }
            buck = next;
        }
    }
    
    
    private boolean deepEqual(TreeNode tree1, TreeNode tree2){
        if (tree1 == null && tree2 == null){
            return true;
        } else if (tree1 == null || tree2 == null || tree1.val != tree2.val){
            return false;
        }
        boolean equal = deepEqual(tree1.left, tree2.left)
                        && deepEqual(tree1.right, tree2.right);
        return equal;
    }
}
__________________________________________________________________________________________________
sample 38464 kb submission
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
    //Map<Integer, List<Count>> counts = new HashMap<>();
    Count[][] count2 = new Count[16][];
    int countSize = 0;
    
    private static class Count {
        int count;
        TreeNode tree;
        int hash;
        
        public Count(TreeNode tree, int count, int hash){
            this.tree = tree;
            this.count = count;
            this.hash = hash;
        }
    }    
    
    public List<TreeNode> findDuplicateSubtrees(TreeNode root) { 
        List<TreeNode> result = new ArrayList<>();
        addDuplicates(root, result);
        return result;
    }
    
    /**
     * Recursiverly compute a hash code and test the noe for duplicate
     */
    private int addDuplicates(TreeNode root, List<TreeNode> result){
        if (root == null){
            return -1;
        }
        
        int hash = Integer.hashCode(root.val);
        hash = hash * 31 + addDuplicates(root.left, result);
        hash = hash * 31 + addDuplicates(root.right, result);
        addCandidate(hash, root, result);
        return hash;
    }
    
    /**
     * Maintain a count of deeply equale sub trees and add the given tree to the result 
     * list if and only if this count is 2.
     */
    private void addCandidate(int hash, TreeNode tree, List<TreeNode> result){
        int bucketIdx = (hash ^ (hash >>> 16)) & (count2.length - 1);
        Count[] bucket = count2[bucketIdx];
        if (bucket == null){
            bucket = new Count[3];
            
            if (countSize > .75 * count2.length){
                Count[][] newCount = new Count[count2.length * 2][];
                for (Count[] b : count2){
                    if (b != null){
                        addCount(b, newCount);
                    }
                }
                count2 = newCount;
                bucketIdx = (hash ^ (hash >>> 16)) & (newCount.length - 1);
            }
            
            countSize++;
            count2[bucketIdx] = bucket;
        }
        boolean found = false;
        for (Count count : bucket){
            if (count == null) break;
            
            if (deepEqual(tree, count.tree)){
                if (++count.count == 2){
                    result.add(tree);
                }
                found = true;
                break;
            }
        }
        if (!found){         
            Count newCount = new Count(tree, 1, hash);
            for (int i = 0; i < bucket.length; i++){
                if (bucket[i] == null){
                    bucket[i] = newCount;       
                    newCount = null;
                    break;
                }
            }
            if (newCount != null){
                int oldLength = bucket.length;
                bucket = Arrays.copyOf(bucket,  oldLength * 2);
                bucket[oldLength] = newCount;
                count2[bucketIdx] = bucket;
            }
        }
    }
    
    private void addCount(Count[] buck, Count[][] buckets){
        if (buck[1] == null){
            int bucketIdx = (buck[0].hash ^ (buck[0].hash >>> 16)) & (buckets.length - 1);
            if (buckets[bucketIdx] == null){
                buckets[bucketIdx] = buck;
                return;
            }
        }
        
        for (Count cnt : buck){
            if (cnt == null) break;
            int bucketIdx = (cnt.hash ^ (cnt.hash >>> 16)) & (buckets.length - 1);
            Count[] insBucket = buckets[bucketIdx];
            if (insBucket == null){
                insBucket = new Count[3];
                buckets[bucketIdx] = insBucket;
            }
            
            for (int i = 0; i < insBucket.length; i++){
                if (insBucket[i] == null){
                    insBucket[i] = cnt;       
                    cnt = null;
                    break;
                }
            }
            if (cnt != null){
                int oldLength = insBucket.length;
                insBucket = Arrays.copyOf(insBucket,  oldLength * 2);
                insBucket[oldLength] = cnt;
                buckets[bucketIdx] = insBucket;
            }
        }
    }
    
    
    private boolean deepEqual(TreeNode tree1, TreeNode tree2){
        if (tree1 == null && tree2 == null){
            return true;
        } else if (tree1 == null || tree2 == null || tree1.val != tree2.val){
            return false;
        }
        boolean equal = deepEqual(tree1.left, tree2.left)
                        && deepEqual(tree1.right, tree2.right);
        return equal;
    }
}
__________________________________________________________________________________________________
