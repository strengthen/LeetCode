__________________________________________________________________________________________________
1ms
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        int min=Integer.MAX_VALUE;
        int max=Integer.MIN_VALUE;
        for(int i=0;i<lists.length;i++)
        {
            ListNode p = lists[i];
            if(p!=null)
            {
            if(p.val<min )
            {
                min=p.val;
            }
            while(p.next!=null)
            {
                p=p.next;
            }
            if(p.val>max)
            {
                max=p.val;
            }
            }
        }
        int[] arr= new int[max-min+1];
        for(int i=0;i<lists.length;i++)
        {
            ListNode p = lists[i];
            while(p!=null)
            {
                arr[p.val-min]++;
                p=p.next;
            }
        }
        ListNode ans = new ListNode(0);
        ListNode ansh= ans;
        for(int i=0;i<arr.length;i++)
        {
            while(arr[i]!=0)
            {
                ans.next=new ListNode(i+min);
                ans=ans.next;
                arr[i]--;
            }
        }
        return ansh.next;
    }
}
__________________________________________________________________________________________________
2ms
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
 public ListNode mergeKLists(ListNode[] lists) {  
    if(lists.length==0) return null;        
    int interval = 1;
    while(interval < lists.length){
        for (int i = 0; i + interval<lists.length; i=i+interval*2)
            lists[i]=merge2Lists(lists[i],lists[i+interval]);
      
        interval*=2;
    }
    return lists[0];
  }

  public ListNode merge2Lists(ListNode l1, ListNode l2) {
    if ((l1 == null) && (l2 == null)) return null;    
    ListNode l3 = new ListNode(0);
    ListNode currL3=l3;          
    while ((l1 != null) && (l2 != null)) {
      if (l1.val < l2.val) {
        currL3.next = l1;
        l1 = l1.next;
      } else {
        currL3.next = l2;
        l2 = l2.next;
      }      
      currL3 = currL3.next;        
    }
    if ((l1 == null) && (l2 != null))
      currL3.next = l2;
    if ((l1 != null) && (l2 == null))
      currL3.next = l1;
    
    return l3.next;
  }
}
__________________________________________________________________________________________________
3ms
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists == null) return null; 
        int s = 0, e = lists.length -1;
        return part(lists,0,e);
    }
    private ListNode part (ListNode[] ls, int s, int e) {
        if (s == e) return ls[s];
        if (s<e) {
            int mid = (s+e) /2;
            ListNode l1 = part(ls,s,mid);
            ListNode l2 = part(ls,mid+1,e);
            return merge(l1,l2);
        }
        else
            return null; 
    } 
    
    private ListNode merge(ListNode l1, ListNode l2) {
        if (l1 == null) return l2; 
        if (l2 == null) return l1; 
        if (l1.val < l2.val){
            ListNode next = l1.next;
            l1.next = merge(next,l2);
            return l1;
        }
        else {
            ListNode next = l2.next;
            l2.next = merge(next,l1);
            return l2;
        }
    }
}
__________________________________________________________________________________________________
35188 kb
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        final Queue<ListNode> queue = new PriorityQueue<>(new Comparator<ListNode> () {
            @Override
            public int compare (ListNode a, ListNode b) {
                return a.val - b.val;
            }
        });
        for (ListNode list : lists) {
            if (list != null) {
                queue.offer(list);
            }
        }
        ListNode result = new ListNode(0);
        ListNode curr = result;
        while (!queue.isEmpty()) {
            ListNode temp = queue.poll();
            if (temp.next != null) {
                queue.offer(temp.next);
            }
            curr.next = temp;
            curr = curr.next;
        }
        return result.next;
    }
}
__________________________________________________________________________________________________
35192 kb 
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    private Comparator<ListNode> listNodeComparator = new Comparator<ListNode>(){
        public int compare(ListNode left, ListNode right) {
            return left.val - right.val;
        }
    };
    
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }
        
        Queue<ListNode> heap = new PriorityQueue<>(lists.length, listNodeComparator);
        
        for (int i = 0; i < lists.length; i++) {
            if (lists[i] != null) {
                heap.add(lists[i]);
            }
        }
        
        ListNode dummy = new ListNode(0);
        ListNode current = dummy;
        while (!heap.isEmpty()) {
            ListNode minimum = heap.poll();
            current.next = minimum;
            current = minimum;
            if (minimum.next!= null) {
                heap.add(minimum.next);
            }
        }
        
        return dummy.next;
    }
}
__________________________________________________________________________________________________
