You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

给定两个非空链表来表示两个非负整数。位数按照逆序方式存储，它们的每个节点只存储单个数字。将两数相加返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
64ms
 1 /**
 2  * Definition for singly-linked list.
 3  * public class ListNode {
 4  *     public var val: Int
 5  *     public var next: ListNode?
 6  *     public init(_ val: Int) {
 7  *         self.val = val
 8  *         self.next = nil
 9  *     }
10  * }
11  */
12 class Solution {
13     func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
14         var c1: ListNode? = l1
15         var c2: ListNode? = l2
16         if c1==nil
17         {return c2!}
18         if c2==nil
19         {return c1!}
20         var sentinel = ListNode(0)
21         var d: ListNode?  = sentinel;
22         var sum:Int = 0
23         while (c1 != nil || c2 != nil) {
24             sum /= 10
25             if c1 != nil {
26                 sum += c1!.val
27                 c1 = c1!.next
28             }
29             if c2 != nil {
30                 sum += c2!.val
31                 c2 = c2!.next
32             }
33             d!.next = ListNode(sum % 10)
34             d = d!.next;
35         }        
36         
37         if sum / 10 == 1
38           {
39               d!.next = ListNode(1)
40           }    
41         return sentinel.next        
42     }
43 }
 

64ms

 1 /**
 2  * Definition for singly-linked list.
 3  * public class ListNode {
 4  *     public var val: Int
 5  *     public var next: ListNode?
 6  *     public init(_ val: Int) {
 7  *         self.val = val
 8  *         self.next = nil
 9  *     }
10  * }
11  */
12 class Solution {
13     func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
14         var newList = ListNode(0);
15         var p = newList;
16         var p1 = l1;
17         var p2 = l2;
18         var div = 0;
19         while true {
20             let val1 = p1 == nil ? 0 : p1!.val;
21             let val2 = p2 == nil ? 0 : p2!.val;
22             let value = (val1 + val2 + div) % 10;
23             div = ((val1 + val2 + div) - value) / 10;
24             p.val = value;
25             if p1?.next == nil &&  p2?.next == nil && div == 0 {
26                 break
27             } else {
28                 p.next = ListNode(0);
29                 p = p.next!;
30                 if p1 != nil {
31                     p1 = p1?.next;
32                 } 
33                 if p2 != nil {
34                     p2 = p2?.next;
35                 }
36             }
37         }
38         return newList;
39     }
40 }
68ms

 1 /**
 2  * Definition for singly-linked list.
 3  * public class ListNode {
 4  *     public var val: Int
 5  *     public var next: ListNode?
 6  *     public init(_ val: Int) {
 7  *         self.val = val
 8  *         self.next = nil
 9  *     }
10  * }
11  */
12 class Solution {
13     func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
14         guard l1 != nil, l2 != nil else { return nil }
15         guard l1 != nil else { return l2 }
16         guard l2 != nil else { return l1 }
17         guard var l1 = l1 as ListNode?, var l2 = l2 as ListNode? else { return nil }
18         var remainder: Int = 0
19         var newNode: ListNode?
20         var currentNode: ListNode?
21         
22         let sum = l1.val + l2.val + remainder
23             let i: Int
24             if sum > 9 {
25                 remainder = 1
26                 i = sum - 10
27             } else {
28                 remainder = 0
29                 i = sum
30             }
31             if newNode == nil {
32                 newNode = ListNode(i)
33                 currentNode = newNode
34             } else {
35                 currentNode!.next = ListNode(i)
36                 currentNode = currentNode!.next
37             }
38         
39         while l1.next != nil || l2.next != nil {
40             if l1.next != nil {
41                 l1 = l1.next!
42             } else {
43                 l1.val = 0
44             }
45             if l2.next != nil {
46                 l2 = l2.next!
47             } else {
48                 l2.val = 0
49             }
50             let sum = l1.val + l2.val + remainder
51             let i: Int
52             if sum > 9 {
53                 remainder = 1
54                 i = sum - 10
55             } else {
56                 remainder = 0
57                 i = sum
58             }
59             if newNode == nil {
60                 newNode = ListNode(i)
61                 currentNode = newNode
62             } else {
63                 currentNode!.next = ListNode(i)
64                 currentNode = currentNode!.next
65             }
66         }
67         
68         if remainder == 1 {
69             if newNode == nil {
70                 newNode = ListNode(remainder)
71             } else {
72                 currentNode!.next = ListNode(remainder)
73             }
74         }
75         
76         return newNode
77     }
78     
79     func convertToString(_ l1: ListNode) -> String {
80         var node = l1
81         var str = "\(node.val)"
82         while node.next != nil {
83             node = node.next!
84             str = "\(node.val)" + str
85         }
86         return str
87     }
88 }
72ms

 1 /**
 2  * Definition for singly-linked list.
 3  * public class ListNode {
 4  *     public var val: Int
 5  *     public var next: ListNode?
 6  *     public init(_ val: Int) {
 7  *         self.val = val
 8  *         self.next = nil
 9  *     }
10  * }
11  */
12 class Solution {
13     func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
14         var addition = 0
15         
16         var tn1 = l1
17         var tn2 = l2
18         var lastRN = ListNode(0)
19         var ret: ListNode? = nil
20         while tn1 != nil || tn2 != nil || addition > 0 {
21             var rn = ListNode(0)
22             
23             if tn1 != nil || tn2 != nil {
24                 rn.val = ((tn1?.val ?? 0) + (tn2?.val ?? 0) + addition) % 10
25                 addition = ((tn1?.val ?? 0) + (tn2?.val ?? 0) + addition) / 10
26             } else {
27                 rn.val = addition
28                 addition = 0
29             }
30             
31             if tn1 === l1 || tn2 === l2 {
32                 // first time
33                 ret = rn
34                 rn.next = nil
35             } else {
36                 lastRN.next = rn
37             }
38             lastRN = rn
39             tn1 = tn1?.next
40             tn2 = tn2?.next
41         }
42         return ret
43     }
44 }
76ms

 1 /**
 2  * Definition for singly-linked list.
 3  * public class ListNode {
 4  *     public var val: Int
 5  *     public var next: ListNode?
 6  *     public init(_ val: Int) {
 7  *         self.val = val
 8  *         self.next = nil
 9  *     }
10  * }
11  */
12 class Solution {
13     func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
14         var l1 = l1
15         var l2 = l2
16         var carry = 0
17         var sum = 0
18         var result = ListNode(0)
19         let head = result
20         
21         while l1 != nil || l2 != nil || carry != 0{
22             
23             let current = ListNode(0)
24             
25             sum = (l1?.val ?? 0) + (l2?.val ?? 0) + carry
26             current.val = sum % 10
27             carry = sum >= 10 ? 1 : 0
28             
29             result.next = current
30             result = current
31             
32             l1 = l1?.next
33             l2 = l2?.next
34             
35         }
36         return head.next
37     }
38 }
80ms

 1 /**
 2  * Definition for singly-linked list.
 3  * public class ListNode {
 4  *     public var val: Int
 5  *     public var next: ListNode?
 6  *     public init(_ val: Int) {
 7  *         self.val = val
 8  *         self.next = nil
 9  *     }
10  * }
11  */
12 class Solution {
13     func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
14         var carryover = 0
15         var next:ListNode?
16         var result:ListNode?
17         var l1v = l1
18         var l2v = l2
19         while l1v != nil && l2v != nil
20         {     
21             if next == nil
22             {
23                 next = ListNode(0)
24                 result = next
25             }
26             else
27             {
28                 next?.next = ListNode(0)
29                 next = next?.next!
30             }
31             
32             var sum = l1v!.val + l2v!.val + carryover
33             carryover = 0
34             if sum >= 10
35             {
36                 carryover = sum / 10
37                 sum = sum % 10
38             }
39             
40             next?.val = sum
41             
42             l1v = l1v?.next
43             l2v = l2v?.next
44         }
45         
46         if l1v != nil
47         {
48             while l1v != nil
49             {
50                 next?.next = ListNode(0)
51                 next = next?.next!
52                 
53                 var sum = l1v!.val + carryover
54                 carryover = 0
55                 if sum >= 10
56                 {
57                     carryover = sum / 10
58                     sum = sum % 10
59                 }
60                 
61                 next?.val = sum
62                 
63                 l1v = l1v?.next
64             }
65         }
66         
67         if l2v != nil
68         {
69             while l2v != nil
70             {
71                 next?.next = ListNode(0)
72                 next = next?.next!
73                 
74                 var sum = l2v!.val + carryover
75                 carryover = 0
76                 if sum >= 10
77                 {
78                     carryover = sum / 10
79                     sum = sum % 10
80                 }
81                 
82                 next?.val = sum
83                 
84                 l2v = l2v?.next
85             }
86         }
87         
88         if carryover > 0
89         {
90             next?.next = ListNode(carryover)
91         }
92 
93         return result
94     }
95 }
84ms

 1 /**
 2  * Definition for singly-linked list.
 3  * public class ListNode {
 4  *     public var val: Int
 5  *     public var next: ListNode?
 6  *     public init(_ val: Int) {
 7  *         self.val = val
 8  *         self.next = nil
 9  *     }
10  * }
11  */
12 class Solution {
13     func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
14         var returnList: ListNode?
15         var currentNode: ListNode?
16         var tempList: ListNode?
17         
18         var currentL1 = l1
19         var currentL2 = l2
20         
21         var carryForward: Int?
22         
23         while currentL1 != nil || currentL2 != nil || carryForward != nil {
24             var combinedValue = carryForward != nil ? carryForward! : 0
25             
26             carryForward = nil
27             
28             if let cur1 = currentL1 {
29                 combinedValue += cur1.val
30             }
31             
32             if let cur2 = currentL2 {
33                 combinedValue += cur2.val
34             }
35             
36             if combinedValue/10 > 0 {
37                 carryForward = 1
38             }
39             
40             tempList = ListNode(combinedValue%10)
41             currentNode?.next = tempList
42             
43             if returnList == nil {
44                 returnList = tempList
45             }
46             
47             currentNode = tempList
48             
49             currentL1 = currentL1?.next
50             currentL2 = currentL2?.next
51         }
52         
53         return returnList
54     }
55     
56     func reverseLinkedList(_ ll: ListNode?) -> ListNode? {
57         var previousNode: ListNode?
58         var currentNode: ListNode?
59         var tempNode: ListNode?
60         
61         previousNode = nil
62         currentNode = ll
63         
64         while currentNode != nil {
65             tempNode = currentNode?.next
66             currentNode?.next = previousNode
67             previousNode = currentNode
68             currentNode = tempNode
69         }
70         
71         return previousNode
72     }
73 }
88ms

 1 /**
 2  * Definition for singly-linked list.
 3  * public class ListNode {
 4  *     public var val: Int
 5  *     public var next: ListNode?
 6  *     public init(_ val: Int) {
 7  *         self.val = val
 8  *         self.next = nil
 9  *     }
10  * }
11  */
12 class Solution {
13     func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
14       guard var l1 = l1, var l2 = l2 else {return nil}
15       
16       var firstNode = ListNode((l1.val + l2.val) % 10)
17       var currentNode = firstNode
18       var listNode1 = l1.next
19       var listNode2 = l2.next
20       var addOne = (l1.val + l2.val) > 9
21       while listNode1 != nil || listNode2 != nil {
22         var sum = (listNode1?.val ?? 0) + (listNode2?.val ?? 0)
23         sum += addOne ? 1 : 0 
24         let nextNode = ListNode(sum % 10)
25         currentNode.next = nextNode
26         currentNode = nextNode
27         addOne = sum > 9
28         listNode1 = listNode1?.next
29         listNode2 = listNode2?.next
30       }
31       
32       if addOne { currentNode.next = ListNode(1) }
33       
34       return firstNode
35     }
36 }
 