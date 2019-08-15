__________________________________________________________________________________________________
sample 28 ms submission
# Below is the interface for Iterator, which is already defined for you.
#
# class Iterator:
#     def __init__(self, nums):
#         """
#         Initializes an iterator object to the beginning of a list.
#         :type nums: List[int]
#         """
#
#     def hasNext(self):
#         """
#         Returns true if the iteration has more elements.
#         :rtype: bool
#         """
#
#     def next(self):
#         """
#         Returns the next element in the iteration.
#         :rtype: int
#         """

class PeekingIterator:
    def __init__(self, iterator):
        """
        Initialize your data structure here.
        :type iterator: Iterator
        """
        self.peekingIterator = iterator
        self.peeked = False
        self._next = None

    def peek(self):
        """
        Returns the next element in the iteration without advancing the iterator.
        :rtype: int
        """
        if not self.peeked:
            if self.peekingIterator.hasNext():
                self._next = self.peekingIterator.next()
                self.peeked = True
        return self._next
            
    def next(self):
        """
        :rtype: int
        """
        result = None
        if self.peeked:
            self.peeked = False
            result = self._next
            self._next = None
            return result
        else:
            if self.peekingIterator.hasNext():
                return self.peekingIterator.next()
            
    def hasNext(self):
        """
        :rtype: bool
        """
        return self.peekingIterator.hasNext() or self.peeked

# Your PeekingIterator object will be instantiated and called as such:
# iter = PeekingIterator(Iterator(nums))
# while iter.hasNext():
#     val = iter.peek()   # Get the next element but not advance the iterator.
#     iter.next()         # Should return the same value as [val].
__________________________________________________________________________________________________
sample 13176 kb submission
# Below is the interface for Iterator, which is already defined for you.
#
# class Iterator:
#     def __init__(self, nums):
#         """
#         Initializes an iterator object to the beginning of a list.
#         :type nums: List[int]
#         """
#
#     def hasNext(self):
#         """
#         Returns true if the iteration has more elements.
#         :rtype: bool
#         """
#
#     def next(self):
#         """
#         Returns the next element in the iteration.
#         :rtype: int
#         """

class PeekingIterator:
    def __init__(self, iterator):
        """
        Initialize your data structure here.
        :type iterator: Iterator
        """
        self.iterator = iterator
        self.peek_flag = False

    def peek(self):
        """
        Returns the next element in the iteration without advancing the iterator.
        :rtype: int
        """
        if self.peek_flag:
            return self.next_element
        else:
            self.next_element = self.iterator.next()
            self.peek_flag = True
            return self.next_element
        
    def next(self):
        """
        :rtype: int
        """
        if self.peek_flag:
            self.peek_flag = False
            return self.next_element
        else:
            return self.iterator.next()

    def hasNext(self):
        """
        :rtype: bool
        """
        if self.peek_flag:
            return True
        else:
            return self.iterator.hasNext()
        

# Your PeekingIterator object will be instantiated and called as such:
# iter = PeekingIterator(Iterator(nums))
# while iter.hasNext():
#     val = iter.peek()   # Get the next element but not advance the iterator.
#     iter.next()         # Should return the same value as [val].
__________________________________________________________________________________________________
