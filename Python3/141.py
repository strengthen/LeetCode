__________________________________________________________________________________________________
def hasCycle(self, head):
    slow, fast = head, head
    while slow and slow.next and fast and fast.next and fast.next.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            return True
    return False
__________________________________________________________________________________________________

__________________________________________________________________________________________________
