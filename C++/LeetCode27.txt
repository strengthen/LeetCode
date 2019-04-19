__________________________________________________________________________________________________
4ms
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int tmp_size = nums.size();
        int i = 0;
        while(i < tmp_size)
        {
            if(nums[i] == val)
            {
                nums.erase(nums.begin()+i, nums.begin()+i+1);
                tmp_size -= 1;
            }
            else{
                i++;
            }
        }
        return tmp_size;
    }
};
__________________________________________________________________________________________________
8ms
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0)
            return 0;
        int ptr1, ptr2;
        for(ptr1=0,ptr2=0; ptr1 < nums.size(); ptr1++){
            if(nums[ptr1] != val){
                nums[ptr2++] = nums[ptr1];
            }
        }
        return ptr2;
    }
};
__________________________________________________________________________________________________
8652 kb
static int x = []() {
    std::ios::sync_with_stdio( false );
    std::cin.tie( NULL );
    std::cout.tie( NULL );
    return NULL;
}();

class Solution {
  public:
    int removeElement( vector<int> &nums, int val ) {
        int i = 0;
        int j = nums.size() - 1;
        int result = 0;
        for ( i = 0; i < nums.size(); ++i ) {
            if ( nums[ i ] == val ) {
                while ( j > i ) {
                    if ( nums[ j ] != val ) {
                        swap( nums[ i ], nums[ j ] );
                        result++;
                        j--;
                        break;
                    }
                    j--;
                } 
            } else {
                result++;
            }
        }
        return result;
    }
    void swap( int &a, int &b ) {
        int temp = a;
        a        = b;
        b        = temp;
    }
};
__________________________________________________________________________________________________
8668 kb
static const auto __ = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
	int len = nums.size();
	if (len == 0) return 0;

	int start = -1;
	for (int i = 0; i < len; ++i) {
	  if (nums[i] != val) {
		++start;
		if (start != i) swap(nums[start], nums[i]);
	  }
	}

	return start + 1;
  }
};
__________________________________________________________________________________________________
8768 kb 
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int update = 0, len = nums.size();
        for (int i=0; i<len; i++){
            if (nums[i]!=val){
                nums[update] = nums[i];
                update++;
            }
        }
        return update;
    }
};
__________________________________________________________________________________________________
