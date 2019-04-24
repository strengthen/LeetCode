__________________________________________________________________________________________________
32ms
static const int _x_ = [] () { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; } ();

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
    Node* copyNode(Node* node) {
        return (node ? new Node(node->val, node->next, node->random) : nullptr);
    }

public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return nullptr;
        }

        for (Node* i = head; i; i = i->next->next) {
            i->next = copyNode(i);
        }

        for (Node* i = head->next; i; i = i->next->next) {
            if (i->random) {
                i->random = i->random->next;
            }
            if (!i->next) {
                break;
            }
        }

        Node copy_guard(0, nullptr, nullptr);
        Node* ci = &copy_guard;

        for (Node* i = head; i; i = i->next) {
            ci->next = i->next;
            ci = ci->next;
            i->next = i->next->next;
        }

        return copy_guard.next;
    }
};
__________________________________________________________________________________________________
16476 kb
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    if (!head) return NULL;

    RandomListNode dummy(0);
    RandomListNode* tail = &dummy, *cur = head;

    // First round, copy and append nodes
    while (cur) {
      RandomListNode* node = new RandomListNode(cur->label);
      node->next = cur->next;
      node->random = cur->random;
      cur->next = node;
      cur = node->next;
    }

    // Second round, fix random ptr
    cur = head;
    while (cur) {
      cur->next->random = cur->next->random ? cur->next->random->next : NULL;

      cur = cur->next->next;
    }
    
    // Third round, release copied nodes
    cur = head;
    while (cur) {
      tail->next = cur->next;
      tail = tail->next;

      cur->next = cur->next->next;
      cur = cur->next;
    }

    return dummy.next;
  }
};
__________________________________________________________________________________________________
