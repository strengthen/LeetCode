__________________________________________________________________________________________________
sample 84 ms submission
class MyLinkedList:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack = []
        

    def get(self, index: int) -> int:
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        """
        if index >= len(self.stack) or index < 0:
            return -1
        else:
            return self.stack[index]
        

    def addAtHead(self, val: int) -> None:
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        """
        self.stack.insert(0, val)
        

    def addAtTail(self, val: int) -> None:
        """
        Append a node of value val to the last element of the linked list.
        """
        self.stack.append(val)
        

    def addAtIndex(self, index: int, val: int) -> None:
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        """
        if len(self.stack) < index:
            return -1
        
        self.stack.insert(index, val)
        

    def deleteAtIndex(self, index: int) -> None:
        """
        Delete the index-th node in the linked list, if the index is valid.
        """
        if index >= len(self.stack) or index < 0:
            return -1
        else:
            self.stack.pop(index)
        


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)
__________________________________________________________________________________________________
sample 13368 kb submission
class Node(object):
    def __init__(self):
        self.val = None
        self.next = None


class MyLinkedList:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.count = 0
        self.root = None
        

    def get(self, index: int) -> int:
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        """
        if index >= self.count or index < 0:
            return -1
        
        head = self.root
        for i in range(index):
            head = head.next
        # print(index, self.count, self.root)
        return head.val

    def addAtHead(self, val: int) -> None:
        """
        Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
        """
        node = Node()
        node.val = val
        node.next = self.root
        self.root = node
        self.count += 1

    def addAtTail(self, val: int) -> None:
        """
        Append a node of value val to the last element of the linked list.
        """
        node = Node()
        node.val = val
        
        if self.count == 0:
            self.root = node
        else:
            head = self.root
            for _ in range(self.count-1):
                head = head.next
            
            head.next = node

        self.count += 1
        

    def addAtIndex(self, index: int, val: int) -> None:
        """
        Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
        """
        
        if index > self.count:
            return
        
        node = Node()
        node.val = val        
        
        if self.count == 0:
            node.next = self.root
            self.root = node
            self.count += 1
            return
        
        if self.count == index:
            self.addAtTail(val)
        else:

            if index == 0:
                self.addAtHead(val)
            else:         
                head = self.root
                for _ in range(index-1):
                    head = head.next

                node.next = head.next
                head.next = node
#             node_before = self.getNode(index-1)
#             node_after = self.getNode(index)

#             new_node = Node()
#             node.val = val

#             node_before.next = new_node
#             new_node.next = node_after
                
                self.count += 1
                
            
    def deleteAtIndex(self, index: int) -> None:
        """
        Delete the index-th node in the linked list, if the index is valid.
        """
        
        if index < 0 or index >= self.count:
            return
        
        node_to_delete = self.root
        for _ in range(index):
            node_to_delete = node_to_delete.next
        
        del node_to_delete
        
        if index == 0:
            new_head = self.getNode(1)
            self.root = new_head
        else:
            node_before = self.getNode(index-1)
            node_after = self.getNode(index+1)
            node_before.next = node_after
        self.count -= 1
        
    def getNode(self, index: int) -> ListNode:
        cur = self.root
        for _ in range(index):
            cur = cur.next
        return cur
    
#     def get(self, index: 'int') -> 'int':
#         if index < 0 or index >= self.count:
#             return -1
        
#         return self.getNode(index).val


# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)
__________________________________________________________________________________________________
