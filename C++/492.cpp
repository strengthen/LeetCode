__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int s = sqrt(area);
        vector<int> result;
        for(int w = s; w > 0; w--) {
        	if(area % w == 0) {
        		result.push_back(area / w);
        		result.push_back(w);
        		break;
			}
		}
		return result;
    }
};
__________________________________________________________________________________________________
sample 8368 kb submission
class Solution {
public:
    vector<int> constructRectangle(int area) {
        for (int i=floor(sqrt(area)); i>=1; i--)
        if (area % i == 0){
            vector<int> result(2);
            result[0] = area / i;
            result[1] = i;
            return result;
        }
        return vector<int>();
    }
};
__________________________________________________________________________________________________
