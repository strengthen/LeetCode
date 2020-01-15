__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        vector<int>v;
        if(tomatoSlices>4*cheeseSlices||2*cheeseSlices>tomatoSlices){
            return v;
        }
        int k=tomatoSlices-2*cheeseSlices;
        if(k%2!=0){
            return v;
        }
        v.push_back(k/2);
        v.push_back(cheeseSlices-k/2);
        return v;
    }
};
__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if (cheeseSlices > tomatoSlices) {
            return vector<int>(); // can't have more cheese than tomato
        } else if (tomatoSlices % 2 != 0) {
            return vector<int>(); // all burgers have even tomato
        }
        
        int jumbo = 0;
        int small = 0;
        
        jumbo = tomatoSlices / 4; // extract max jumbo
        if (tomatoSlices % 4 != 0) {
            small = 1; // see if two left over for small
        }
        
        if (jumbo + small > cheeseSlices) {
            return vector<int>(); // more tomato in min burger case than cheese
        }
        
        if (jumbo + small < cheeseSlices) {
            int diff = cheeseSlices - jumbo - small;
            if (diff < jumbo) {
                small += 2 * diff; // reallocate jumbo burgers into two smalls to get more cheese
                jumbo -= diff;
            } else {
                return vector<int>(); // if diff too large, impossible
            }
        }
        
        vector<int> result;
        result.push_back(jumbo);
        result.push_back(small);
        
        return result;
    }
};
__________________________________________________________________________________________________
