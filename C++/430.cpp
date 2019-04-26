__________________________________________________________________________________________________
sample 96 ms submission
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        stack <Node *> st;
        Node *cur = head, *prev = nullptr;
        while (!st.empty() || cur) {
            if (cur == nullptr) {
                cur = st.top(); st.pop();
                prev->next = cur;
                prev->next->prev = prev;
            }
            if (cur->child != nullptr) {
                if (cur->next) st.push(cur->next);
                cur->next = cur->child;
                cur->next->prev = cur;
                cur->child = nullptr;
            }
            prev = cur;
            cur = cur->next;
        }
        
        return head;
    }
};

static int fastio = []() {
    #define endl '\n'
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
}();
__________________________________________________________________________________________________
sample 29808 kb submission
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
	void dfs(Node* ptr, Node* &pre){
		if (!ptr) return;
		if (pre) pre->next=ptr;
		ptr->prev=pre;
		pre=ptr;
		auto* next=ptr->next;
		if (ptr->child){
			auto* nextLevel=ptr->child;
			ptr->child=NULL;
			while (nextLevel->prev)
				nextLevel=nextLevel->prev;
			dfs(nextLevel, pre);
		}
		dfs(next, pre);
	}
public:
    Node* flatten(Node* head) {
        Node* pre=NULL;
		dfs(head, pre);
		return head;
    }
};
__________________________________________________________________________________________________
