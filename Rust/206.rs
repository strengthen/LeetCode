__________________________________________________________________________________________________
//runtime: 0ms, memory: 2.4MB

// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
//
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn reverse_list(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut pre = None;
        let mut cur = head;
        while let Some(mut cur_node) = cur.take() {
            let next_temp = cur_node.next.take();
            cur_node.next = pre.take();
            pre = Some(cur_node);
            cur = next_temp;
        }
        pre
    }
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________
