__________________________________________________________________________________________________
sample 0 ms submission
/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */
/*
- - - + + + +
- - - + + + +
- - - z + + +
- - - - - - -
- - - - - - -

*/
        //x,y++排除
        //x++,y++排除
        //x++,y排除
//
class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
    vector<vector<int>> re;
        int middle;
    for(int x=1;x<1001;x++)
    {
        int left=1,right=1000;
        while(left<=right)
        {
            middle=(left+right)/2;
            if(customfunction.f(x,middle)<z)
                left=(left+right)/2+1;
            else if(customfunction.f(x,middle)>z)
                right=middle-1;
            else 
            {          
                re.push_back(vector<int>{x,middle});
                break;
            }

        }
    }
        return re;
    return re;
    }
};
__________________________________________________________________________________________________
sample 4 ms submission
/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        
        vector<vector<int>> ans;
        
        for(int i = 1; i <= 1000; i++) {
            for(int j = 1; j <= 1000; j++) {
            
                if(customfunction.f(i, j) == z) {
                    
                    vector<int> tmp(2);
                    tmp[0] = i;
                    tmp[1] = j;
                    ans.push_back(tmp);
                } else if(customfunction.f(i, j) >= z)
                    break;
                
            }
        }
        return ans;
    }
};
__________________________________________________________________________________________________
