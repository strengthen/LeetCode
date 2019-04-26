__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    struct CNode{
        int color;
        int n;
        CNode(int c, int num) : color(c), n(num) {};
    };

    int getRemovePoints(CNode preNode, int l, int r,vector<CNode> &cnVec, vector<vector<int>> &points)
    {
        int n = cnVec.size();
        if(r >= n || l > r) return preNode.n * preNode.n;
        if(preNode.n == 0) {
            if(points[l][r] != -1) return points[l][r];
            preNode.color = cnVec[l].color;
            preNode.n = cnVec[l].n;
            points[l][r] = getRemovePoints(preNode, l+1, r, cnVec, points);
            return points[l][r];
        }
        if(preNode.color == cnVec[l].color) {
            preNode.n += cnVec[l].n;
            return getRemovePoints(preNode, l+1, r, cnVec, points);
        }

        //pre color != first color
        int maxp = preNode.n * preNode.n + getRemovePoints(CNode(0,0), l, r, cnVec, points);
        for(int i=l+1; i<=r; ++i) {
            if(preNode.color == cnVec[i].color) {
                maxp = max(maxp, getRemovePoints(preNode, i, r, cnVec, points) + getRemovePoints(CNode(0,0), l, i-1, cnVec, points));
            }
        }
        return maxp;
    }

    int removeBoxes(vector<int>& boxes) {
        vector<CNode> cnVec;
        int curColor = 0;
        int nc = 0;
        for(int i=0; i < boxes.size(); ++i) {
            if(boxes[i] != curColor) {
                if(nc > 0) {
                    CNode node(curColor, nc);
                    cnVec.push_back(node);
                }
                nc = 1;
                curColor = boxes[i];
            }else{
                ++nc;
            }
        }
        CNode node(curColor, nc);
        cnVec.push_back(node);

        CNode preNode(0, 0);
        int n = cnVec.size();
        vector<vector<int>> points(n, vector<int>(n, -1));
        return getRemovePoints(preNode, 0, n-1, cnVec, points);
    }
};
__________________________________________________________________________________________________
sample 13200 kb submission
const int maxn = 101;

class Solution {
private:
public:
    int dfs(vector<int>& boxes,int (&d)[maxn][maxn][maxn],int i, int j, int k) {
        if (d[i][j][k]>0) return d[i][j][k];
        if (i > j) return 0;
        while (i<j && boxes[i+1]==boxes[i]) i++,k++;
        d[i][j][k]=(k+1)*(k+1)+dfs(boxes,d,i+1,j,0);
        
        for (int m=i+1; m<=j; ++m) {
            if (boxes[i]!=boxes[m]) continue;
            d[i][j][k]=max(d[i][j][k],dfs(boxes,d,i+1,m-1,0)+dfs(boxes,d,m,j,k+1));
        }       
        
        return d[i][j][k];
    }

    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        int d[maxn][maxn][maxn]={};
        return dfs(boxes,d,0, n-1, 0);
    }
};
__________________________________________________________________________________________________
