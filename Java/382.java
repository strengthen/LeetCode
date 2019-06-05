__________________________________________________________________________________________________
sample 51 ms submission
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {

    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    int size = 0;
    Random rand ;
    ListNode head2;
    public Solution(ListNode head) {
        int count = 0;
        ListNode curr = head;
        while(curr !=null) {
            count++;
            curr = curr.next; 
        }
        size = count;
        rand = new Random(); 
        head2 = head;
    }
//    int size;
    
    /** Returns a random node's value. */
    public int getRandom() {
        ListNode curr = head2;
         int r = rand.nextInt(size);
        for (int i=0; i<r; i++) {
            if (curr!= null){
                curr = curr.next;
            }
        }
        return curr.val;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
__________________________________________________________________________________________________
sample 38244 kb submission
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
/*
水塘抽样算法
Problem:
Choose k entries from n numbers. Make sure each number is selected with the probability of k/n
Basic idea:
Choose 1, 2, 3, ..., k first and put them into the reservoir.
//下面的k＋1表示第k＋1个数字
For k+1, pick it with a probability of k/(k+1), and randomly replace a number in the reservoir.
For k+i, pick it with a probability of k/(k+i), and randomly replace a number in the reservoir.
Repeat until k+i reaches n
*/

class Solution {   
    private ListNode head;
    private Random rand;
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    public Solution(ListNode head) {
        this.head = head;
        this.rand = new Random();
    }
    
    /** Returns a random node's value. */
    public int getRandom() {
        int k = 1;
        ListNode node = this.head;
        int i = 0;
        ArrayList<Integer> reservoir = new ArrayList<Integer>();
        //先把前k个放进水塘
        while (i < k && node != null) {
            reservoir.add(node.val);
            node = node.next;
            i++;
        }
      //  i++; // i == k  =>  i == k+1 这样i就代表了现在已经处理过的总共数字个位
        i = 1;
        while (node != null) {
            //更换水塘里的数字的概率要是 k／(现在处理过的数字总数)，所以因为i是从0开始，所以概率为从0
           // 到i的数当中选0 到k－1的数字，rand.nextInt(i) < k的概率是k／(现在处理过的数字总数)
            if (rand.nextInt(k+i) == i) {
                reservoir.set(rand.nextInt(k), node.val);
            }
            i++;
            node = node.next;
        }
        return reservoir.get(0);// or return reservoir when k > 1;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
__________________________________________________________________________________________________
