__________________________________________________________________________________________________
sample 32 ms submission
static const int _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        const int n = A.size();
        const int A0 = A[0];
        const int B0 = B[0];
        uint32_t AA;
        uint32_t AB;
        uint32_t BA;
        uint32_t BB;
        int AAc = 0;
        int ABc = 0;
        int BAc = 0;
        int BBc = 0;
        bool key_A = true;
        bool key_B = true;
        
        if (A0 == B0) {
            key_B = false;
            ABc = INT_MAX;
            BBc = INT_MAX;
        }

        for (int i = 0; i < n; ) {
            AA = (-1);
            AB = (-1);
            BA = (-1);
            BB = (-1);
            const int proc_num = min(i+32, n);
            for (; i < proc_num; i++) {
                const int Ai = A[i];
                const int Bi = B[i];
                
                if (key_A) {
                    AA <<= 1;
                    BA <<= 1;
                    if (Ai == A0)
                        AA |= 1;
                    if (Bi == A0)
                        BA |= 1; 
                    else if ((AA & 1) == 0) {
                        key_A = false;
                        AAc = BAc = INT_MAX;
                    }
                }
                
                if (key_B) {
                    AB <<= 1;
                    BB <<= 1;
                    
                    if (A[i] == B0)
                        AB |= 1;
                    if (B[i] == B0)
                        BB |= 1;
                    else if ((AB & 1) == 0) {
                        key_B = false;
                        ABc = BBc = INT_MAX;
                    }
                } else if (!key_A)
                    return (-1);                
            }
            if (key_A) {
                AAc += __builtin_popcount(~AA);
                BAc += __builtin_popcount(~BA);
            }
            if (key_B) {
                ABc += __builtin_popcount(~AB);
                BBc += __builtin_popcount(~BB);
            }
        }
        return min(min(AAc, ABc), min(BAc, BBc));
    }
};
__________________________________________________________________________________________________
sample 36 ms submission
static int x = []() {std::ios::sync_with_stdio(false);  return 0; }();

class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
    	int size = A.size();
    	int counter[7] = {0};
    	for(int i = 0; i < size; ++i)
    	{
    		if(A[i] == B[i])
    			++counter[A[i]];
    		else
    		{
    			++counter[A[i]];
    			++counter[B[i]];
    		}
    	}
    	int target = -1;
    	for(int i = 1; i <= 6; ++i)
    		if(counter[i] >= size)
    		{
    			target = i;
    			break;
    		}
    	if(target == -1)
    		return -1;

    	int countA = 0, countB = 0;
    	for(int i = 0; i < size; ++i)
    	{
    		if(A[i] == target)
    			++countA;
    		if(B[i] == target)
    			++countB;
    	}
    	return countA > countB ? size - countA : size - countB;
    }
};
__________________________________________________________________________________________________
