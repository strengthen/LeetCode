__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    int maximum69Number (int num) {
        string x = to_string(num);
        for(int i = 0;i < x.size();++i) {
            if(x[i] == '6') {
                x[i] = '9';
                break;
            }
        }
        return stoi(x);
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    int maximum69Number (int num) {
	string temp = to_string(num);
	int six = 0;
	six = temp.find('6');
	if (six != -1 ) {
		temp[six] = '9';
		return stoi(temp);
	}
	return num;
}
};
__________________________________________________________________________________________________
