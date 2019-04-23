__________________________________________________________________________________________________
48ms
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseGroup(self, head: 'ListNode') -> 'ListNode':#翻转链表
        if head.next == None:
            return head
        dummy = ListNode(0)
        dummy.next = head
        tmp = dummy
        last = None
        while tmp and tmp.next:                                                                                            
            tmp1 =  tmp.next.next
            tmp.next.next = tmp
            tmp2 = tmp.next
            if last:
                tmp.next = last
            last = tmp2
            tmp = tmp1
        else:
            dummy.next.next = None
            if tmp == None:
                dummy = last
            elif tmp.next == None:
                tmp.next = last
                dummy = tmp
        return dummy


    def reverseKGroup(self, head: 'ListNode', k: 'int') -> 'ListNode':
        dummy = ListNode(0)
        dummy.next = head
        start = head
        last = dummy

        end = dummy
        for i in range(k):
            end = end.next
            if end == None:
                break
        #dummy->0->1->2->3->4->5
        while end:
            tmp1 = start
            start = end.next
            tmp2 = end
            end = tmp1

            tmp2.next = None
            last.next = self.reverseGroup(tmp1)
            end.next = start
            last = end

            for i in range(k):
                end = end.next
                if end == None:
                    break
        return dummy.next
__________________________________________________________________________________________________
52ms
class Solution:
    def reverseKGroup(self, head, k):
        p = head
        p1 = head
        i = 0
        while p and i < k:
            p = p.next
            i += 1
        if i < k:
            return head
        newhead = self.reverseKGroup(p,k)
        for i in range(k):
            p2 = p1.next
            p1.next = newhead
            newhead = p1
            p1 = p2
        return newhead
__________________________________________________________________________________________________
56ms
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        new_head = None
        new_tail = head
        old_tail = None
        prv_node = None
        cur_node = head
        nxt_node = None
        count = 0
        while cur_node is not None:
            if count is 0:
                tmp_node = cur_node
                tmp_count = 0
                while tmp_node is not None and tmp_count < k:
                    tmp_node = tmp_node.next
                    tmp_count += 1
                if tmp_count < k:
                    if old_tail is None:
                        return head
                    else:
                        old_tail.next = cur_node
                    break
                else:
                    new_tail = cur_node
                
            if count < k - 1:
                nxt_node = cur_node.next
                cur_node.next = prv_node
                prv_node = cur_node
                cur_node = nxt_node
                
                count += 1
            elif count == k - 1:
                
                if new_head is None:
                    new_head = cur_node
                    nxt_node = cur_node.next
                    cur_node.next = prv_node
                    prv_node = cur_node
                    cur_node = nxt_node
                else:
                    nxt_node = cur_node.next
                    cur_node.next = prv_node
                    prv_node = cur_node
                    old_tail.next = cur_node
                    cur_node = nxt_node
                    new_tail.next = None
                
                count += 1
            else:
                count = 0
                
                prv_node = new_tail
                old_tail = new_tail
                
        return new_head
__________________________________________________________________________________________________
13068 kb 
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head: 'ListNode', k: 'int') -> 'ListNode':
        # 1. edge case  k = 1, len(sub) < k 
        if k < 2: return head
        node = head 
        for _ in range(k):
            if not node:
                return head
            node = node.next
        
        # reverse
        curr = head
        prev = None
        for _ in range(k):
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp
        
        #recursive
        head.next = self.reverseKGroup(curr, k)
        return prev
__________________________________________________________________________________________________
13080 kb
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head: 'ListNode', k: 'int') -> 'ListNode':
        def reverse_group(pre_first, first):
            # initialize pointers
            n_pre = first
            n = n_pre.next
            n_post = n.next
            
            # iterate over k nodes skipping first one
            i = 1
            while i < k:
                n.next = n_pre
                
                # shift pointers
                n_pre = n
                n = n_post
                if n_post:
                    n_post = n_post.next
                    
                i += 1
            
            first.next = n
            
            if pre_first:
                pre_first.next = n_pre
                
            return n_pre, first
        
        def check_length(first):
            n = first
            i = 0
            while i < k:
                if n is None:
                    return False
                n = n.next
                
                i += 1
            return True
        
        if k <= 1 or head is None:
            return head
        
        if check_length(head):
            new_head, p = reverse_group(None, head)
        else:
            return head
        
        while p.next is not None and check_length(p.next):
            _, p = reverse_group(p, p.next)
        
        return new_head
__________________________________________________________________________________________________
