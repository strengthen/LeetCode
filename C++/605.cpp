__________________________________________________________________________________________________
sample 8 ms submission
static auto x = [](){std::ios::sync_with_stdio(false);cin.tie(nullptr);return nullptr;}();

class Solution{
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n){
		int count=1;
		
		for(int i=0;i<flowerbed.size();i++)
			if(!flowerbed[i]) count++;
			else{
				n-=(count-1)/2;
				count=0;
			}
		n-=count/2;
		
		return n<=0;
	}
};
__________________________________________________________________________________________________
sample 10760 kb submission
class Solution {
public:

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
	int result = 0;
	int count = 1;
	// edge case: left and right
	for (int i = 0; i < flowerbed.size(); i++) {
		if (flowerbed[i] == 0) {
			count++;
		}
		else {
			result += (count - 1) / 2;
			count = 0;
		}
	}
	if (count != 0) {
		result += count / 2;
	}
	return result >= n;
}
};
__________________________________________________________________________________________________
