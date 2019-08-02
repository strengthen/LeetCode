__________________________________________________________________________________________________
sample 1 ms submission
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public int numComponents(ListNode head, int[] G) {
        boolean [] vis=new boolean[10000];
        for(int i:G){
            vis[i]=true;
        }
        int number=0;
        while(head!=null){
            if(vis[head.val]&&((head.next==null)||!vis[head.next.val])){
              number++;  
            }
            head=head.next;
        }
        return number;
    }
}
__________________________________________________________________________________________________
sample 38888 kb submission
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public int numComponents(ListNode head, int[] G) {
        ListNode tmp = head;
        List<Integer> lst = Arrays.stream(G).boxed().collect(Collectors.toList());
        boolean found = false;
        int res = 0;
        while(tmp != null) {
            if(lst.contains(tmp.val)){
                found = true;
            }
            else {
                if(found){
                    res++;
                    found = false;
                }
            }
            tmp = tmp.next;
        }
        if(found)
            res++;
        
        return res;
    }
}
__________________________________________________________________________________________________
