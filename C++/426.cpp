__________________________________________________________________________________________________
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return NULL;
        Node *head = NULL, *pre = NULL;
        inorder(root, pre, head);
        pre->right = head;
        head->left = pre;
        return head;
    }
    void inorder(Node* node, Node*& pre, Node*& head) {
        if (!node) return;
        inorder(node->left, pre, head);
        if (!head) {
            head = node;
            pre = node;
        } else {
            pre->right = node;
            node->left = pre;
            pre = node;
        }
        inorder(node->right, pre, head);
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return NULL;
        Node *head = NULL, *pre = NULL;
        stack<Node*> st;
        while (root || !st.empty()) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top(); st.pop();
            if (!head) head = root;
            if (pre) {
                pre->right = root;
                root->left = pre;
            }
            pre = root;
            root = root->right;
        }
        head->left = pre;
        pre->right = head;
        return head;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return NULL;
        Node *leftHead = treeToDoublyList(root->left);
        Node *rightHead = treeToDoublyList(root->right);
        root->left = root;
        root->right = root;
        return connect(connect(leftHead, root), rightHead);
    }
    Node* connect(Node* node1, Node* node2) {
        if (!node1) return node2;
        if (!node2) return node1;
        Node *tail1 = node1->left, *tail2 = node2->left;
        tail1->right = node2;
        node2->left = tail1;
        tail2->right = node1;
        node1->left = tail2;
        return node1;
    }
};