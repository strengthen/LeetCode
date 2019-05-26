__________________________________________________________________________________________________
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
		int mins = customers.size();
		int directly_satisfied = 0;

		for(int i = 0; i < mins; i++) {
			if(!grumpy[i]) {
				directly_satisfied += customers[i];
				customers[i] = 0;
			}
		}

		int secretly_satisfied = 0, sum = 0;
		for(int i = 0, j = 0; j < mins; j++) {
			sum += customers[j];
			if(j - i == X)
				sum -= customers[i++];
			secretly_satisfied = max(secretly_satisfied, sum);
		}

		return directly_satisfied + secretly_satisfied;
	}
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
