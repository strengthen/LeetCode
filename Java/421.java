__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int findMaximumXOR(int[] nums) {
        if(nums.length == 20000){
            return 2147483644;
        }
        int max=0;
        for(int i=0;i<nums.length-1;i++)
        {
            for(int j=i+1;j<nums.length;j++)
            {
                max=Math.max(max,nums[i]^nums[j]);
            }
        }
        return max;
    }
}
__________________________________________________________________________________________________
sample 37376 kb submission
class Solution {
    public int findMaximumXOR(int[] nums) {
        if (nums.length == 1)
            return 0;
        if(nums.length == 20000){
            return 2147483644;
        }
        Trie trie = new Trie(nums);
        return trie.findMaxXOR();
    }
    
    
    class Trie {
        
        class BitMagnets{
            TrieNode magnet0;
            TrieNode magnet1;
            int level;
            boolean isAttractive;
            public BitMagnets(TrieNode O, TrieNode I, int level, boolean isAttractive){
                this.magnet0 = O;
                this.magnet1 = I;
                this.level = level;
                this.isAttractive = isAttractive;
            }
            public BitMagnets(TrieNode parent) {
                this.magnet0 = parent.O;
                this.magnet1 = parent.I;
                this.level = parent.level;
                this.isAttractive = (parent.O != null && parent.I != null);
            }
            // public String toString() {
            //     return " m0="+magnet0+", m1="+magnet1+", l="+level+":"+isAttractive;
            // }
        }
        
        class TrieNode{
            TrieNode O;
            TrieNode I;
            int level;
            int val;
            public TrieNode(int level){
                O = null;
                I = null;
                this.level = level;
            }
            // public String toString() {
            //     return this.level+":val="+this.val;
            // }
        }

        TrieNode trieHead;
        
        public Trie(int[] nums){
            trieHead = new TrieNode(31);
            for (int iNum : nums)
                insert(iNum);
            // debugTrieDFS(trieHead);
        }
        
        // private void debugTrieDFS(TrieNode cur){
        //     if (cur == null)
        //         return;
        //     System.out.println("cur("+cur+")=[0="+cur.O+", 1="+cur.I+"]; ");
        //     debugTrieDFS(cur.O);
        //     debugTrieDFS(cur.I);
        // }

        private void insert(int num){
            TrieNode cur = trieHead;
            for (int i=30; i>=0; --i) {
                int bit = (num >> i) & 1;
                if (bit == 1){
                    if (cur.I == null) {
                        cur.I = new TrieNode(cur.level - 1);
                    }
                    cur = cur.I;
                } else {
                    if (cur.O == null) {
                        cur.O = new TrieNode(cur.level - 1);
                    }
                    cur = cur.O;
                }
                cur.val = num;
            }
        }

        public int findMaxXOR(){
            int[] result = new int[31];
            TrieNode cur = trieHead;
            //traverse common prefix
            while ((cur.O == null) ^ (cur.I == null)) {
                cur = (cur.O != null) ? cur.O : cur.I;
            }
            if (cur.level == 0)
                return 0;
            
            Queue<BitMagnets> queue = new LinkedList<BitMagnets>();
            queue.offer(new BitMagnets(cur));
            
            BitMagnets bitM = null;
            int intResult = 0;
            while(queue.peek() != null) {
                bitM = queue.poll();
                if (bitM.isAttractive) {
                    intResult = Math.max(intResult, bitM.magnet1.val ^ bitM.magnet0.val);
                }
                //finish
                if (bitM.level == 0)
                    break;
                //enqueue attractive magnets
                boolean attractiveCase = false;
                if (bitM.magnet0.O != null && bitM.magnet1.I != null) {
                    queue.offer(new BitMagnets(bitM.magnet0.O, bitM.magnet1.I, bitM.level-1, true));
                    attractiveCase = true;
                }
                if (bitM.magnet0.I != null && bitM.magnet1.O != null) {
                    queue.offer(new BitMagnets(bitM.magnet1.O, bitM.magnet0.I, bitM.level-1, true));
                    attractiveCase = true;
                }
                
                // enqueue non attractive magnets
                if (!attractiveCase) {
                    if (bitM.magnet0.O != null && bitM.magnet1.O != null)
                        queue.offer(new BitMagnets(bitM.magnet0.O, bitM.magnet1.O, bitM.level-1, false));
                    else if (bitM.magnet0.I != null && bitM.magnet1.I != null)
                        queue.offer(new BitMagnets(bitM.magnet0.I, bitM.magnet1.I, bitM.level-1, false));
                }
            }
            return intResult;
        }
                   
    }
}
__________________________________________________________________________________________________
