__________________________________________________________________________________________________
sample 0 ms submission
class CombinationIterator {
    string chars;
    int combLen;
    int state;
    int count1(int s, int len) {
        int res = 0;
        for (int i = 0; i < len; i++) {
            res += s % 2;
            s /= 2;
        }
        return res;
    }
    void findNextState(int len) {
        for (; state > 0; state--) {
            if (count1(state, len) == combLen) {
                break;
            }
        }
    }
public:
    CombinationIterator(string characters, int combinationLength) {
        chars = characters;
        combLen = combinationLength;
        state = (1<<chars.length());
        findNextState(chars.length());
    }
    
    string next() {
        int len = chars.length();
        string res;
        int s = state;
        //cout << state << ", ";
        for (int i = 0; i < len; i++) {
            if (s % 2) {
                res.push_back(chars[len-i-1]);
            }
            s /= 2;
        }
        state--;
        findNextState(len);
        //cout << state << endl;
        reverse(res.begin(), res.end());
        return res;
    }
    
    bool hasNext() {
        return state > 0;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
__________________________________________________________________________________________________
sample 4 ms submission
class CombinationIterator {
    string record;
    int n;
    vector<int> ptr;
    bool flag;
    int len;
    bool moveToNext(){
        for(int i = n - 1; i >= 0; i--){
            if(ptr[i] < len + i - n){
                ptr[i]++;
                i++;
                while(i < n){
                    ptr[i] = ptr[i - 1] + 1;
                    i++;
                }
                return true;
            }
        }
        return false;
    }
public:
    CombinationIterator(string characters, int combinationLength) {
        record = characters;
        len = characters.size();
        n = combinationLength;
        ptr = vector<int>(combinationLength, 0);
        for(int i = 0; i < combinationLength; i++){
            ptr[i] = i;
        }
        flag = true;
    }
    
    string next() {
        string res;
        for(int i : ptr){
            res += record[i];
        }
        flag = moveToNext();
        return res;
    }
    
    bool hasNext() {
        return flag;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
__________________________________________________________________________________________________
