__________________________________________________________________________________________________
def detectCycle(self, head):
    """
    :type head: ListNode
    :rtype: ListNode
    """
    if head is None or head.next is None:
        return
    slow, fast = head.next, head.next.next
    while fast and fast.next and slow != fast:
        slow, fast = slow.next, fast.next.next
    if fast is None or fast.next is None:
        return
    slow2 = head
    while slow2 != slow:
        slow, slow2 = slow.next, slow2.next
    return slow
__________________________________________________________________________________________________

__________________________________________________________________________________________________
