__________________________________________________________________________________________________
sample 132 ms submission
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
    Node* construct(vector<vector<int>>& grid)
    {
        return BuildQuadTree(grid, 0, 0, grid.size()); 
    }
    
    Node *BuildQuadTree(vector<vector<int>> &grid, int row, int col, int len)
    {
        if (len == 0)
            return nullptr;
        
        int sublen = len / 2;
        int val = grid[row][col];
        
        for (int i = row; i < row + len; ++i)
        {
            for (int j = col; j < col + len; ++j)
            {
                if (val != grid[i][j])
                {
                    // Different values in grid.
                    return new Node(
                        true,
                        false,
                        BuildQuadTree(grid, row, col, sublen),
                        BuildQuadTree(grid, row, col + sublen, sublen),
                        BuildQuadTree(grid, row + sublen, col, sublen),
                        BuildQuadTree(grid, row + sublen, col + sublen, sublen));
                }
            }
        }
        
        return new Node(
            val == 1,
            true,
            nullptr,
            nullptr,
            nullptr,
            nullptr);
    }
};
__________________________________________________________________________________________________
sample 32888 kb submission
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
    Node* construct(vector<vector<int>>& grid){
        if(grid.size()<=0) return NULL;
        int r=grid.size();
        int c=grid[0].size();
        return construct2(grid,0,r-1,0,c-1);
    }
    Node* construct2(vector<vector<int>>& grid,int x,int tr,int y, int tc){   
        int num=0;
        if(tr<x || tc<y) return NULL;
        Node *root=new Node(false,false,NULL,NULL,NULL,NULL);
        for(int i=x;i<=tr;i++)
        {
            for(int j=y;j<=tc;j++)
            {
                if(num==0)
                {   
                    if(grid[i][j]==1)
                    {
                        num=1;
                    }
                    else
                    {
                        num=2;
                    }
                }
                else if(num==1 && grid[i][j]!=1 || num==2 && grid[i][j]!=0)
                {
                    root->isLeaf=false;
                    root->topLeft=construct2(grid,x,x+(tr-x)/2,y,y+(tc-y)/2);
                    root->topRight=construct2(grid,x,x+(tr-x)/2,y+(tc-y)/2+1,tc);
                    root->bottomLeft=construct2(grid,x+(tr-x)/2+1,tr,y,y+(tc-y)/2);
                    root->bottomRight=construct2(grid,x+(tr-x)/2+1,tr,y+(tc-y)/2+1,tc);  
                    return root;
                }
            }
        }
        root->isLeaf=true;
        root->val=((num==2)?false:true);
        return  root;
    }
};
__________________________________________________________________________________________________
