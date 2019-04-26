__________________________________________________________________________________________________
sample 300 ms submission
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* intersect(Node* T1, Node* T2) {
        if(T1->isLeaf && T1->val || T2->isLeaf && T2->val == 0) return T1; 
        if(T2->isLeaf && T2->val || T1->isLeaf && T1->val == 0) return T2;
         
        Node *tl = intersect(T1->topLeft, T2->topLeft);
        Node *tr = intersect(T1->topRight, T2->topRight);
        Node *bl = intersect(T1->bottomLeft, T2->bottomLeft);
        Node *br = intersect(T1->bottomRight, T2->bottomRight);
        
        if(tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf && 
           tl->val == tr->val && tl->val == bl->val && tl->val == br->val) 
        {
            bool val = tl->val;
            delete tl, tr, bl, br;
            return new Node(val, 1, 0, NULL, NULL, NULL); 
        }
        else return new Node(0, 0, tl, tr, bl, br); 
    }
};

static int x = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return NULL;
}();
__________________________________________________________________________________________________
sample 49064 kb submission
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
		if((!quadTree1)&&(!quadTree2))return NULL;
		if(!quadTree2){
			quadTree2 = quadTree1;
			quadTree1=NULL;
		}
        Node* newRoot;
		if(!quadTree1){
			newRoot = quadTree2;
		}
		else{
			if(quadTree1->isLeaf&&quadTree1->val){
				newRoot = quadTree1;
			}
			else if(quadTree2->isLeaf&&quadTree2->val){
				newRoot = quadTree2;
			}
			else if(quadTree2->isLeaf&&quadTree1->isLeaf){
				newRoot = quadTree2;
			}
			else{
                newRoot = quadTree1;
                newRoot->isLeaf = false;
                newRoot->val = false;
				newRoot->topLeft = intersect(quadTree1->topLeft,quadTree2->topLeft);
				newRoot->topRight = intersect(quadTree1->topRight,quadTree2->topRight);
				newRoot->bottomLeft = intersect(quadTree1->bottomLeft,quadTree2->bottomLeft);
				newRoot->bottomRight = intersect(quadTree1->bottomRight,quadTree2->bottomRight);
				if(newRoot->topLeft->isLeaf&&
                   newRoot->topRight->isLeaf&&
                   newRoot->bottomLeft->isLeaf&&
                   newRoot->bottomRight->isLeaf){
					bool result = newRoot->topLeft->val;
					if(result==newRoot->topRight->val&&
                       result==newRoot->bottomLeft->val&&
                       result==newRoot->bottomRight->val){
						newRoot->val = result;
						newRoot->isLeaf = true;
						newRoot->topLeft = NULL;
						newRoot->topRight = NULL;
						newRoot->bottomLeft = NULL;
						newRoot->bottomRight = NULL;
					}
				}				
			}
		}
		return newRoot;
    }
};
__________________________________________________________________________________________________
