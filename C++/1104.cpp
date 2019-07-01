__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> result;
        result.push_back(label); //taking bottom up approach, so the label itself must be included 
        int height=log2(label); //height of label from root
        
        while(height!=0){
            int left=pow(2,height-1); // rank of left limit of the previous level 
            int right=pow(2,height)-1;// rank of right limit of the previous level
            label=left+(right-label/2);// as the previous level is sorted in different order than current one.
                                       //So the new label is adjusted accordingly
            result.push_back(label);  //newly found label is appened to result
            height--;
        }
        
        reverse(result.begin(),result.end()); //required top to down, so the array is reversed. 
        return result;
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> path;
        helper(label, path);
        reverse(path.begin(), path.end());
        return path;
    }
private:
    void helper(int label, vector<int> &path) {
        if (label <= 0) {
            return;
        }
        path.push_back(label);
        int k = floor(log2(label));
        label = (1 << k) + (1 << (k + 1)) - 1 - label;
        helper(label / 2, path);
    }
};
__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int level = 0;
        while ((1 << level) <= label) level++;

        vector<int>res(level);
        for (; label >= 1; label /= 2, level--) {
            res[level-1] = label;
            label = ((1 << level) - 1) - label + (1 << (level-1));
        }
        return res;
    }
};