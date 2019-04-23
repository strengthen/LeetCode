__________________________________________________________________________________________________
4ms
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        for(int i=n-1;i>=0;i--){
            if(digits[i]==9)   digits[i]=0; //+1（得到进位）时，如果该位为9，则变为0并向前进位
            else{
                digits[i]++;               //得到进位，如果该位不是9，则+1，并return
                return digits;
            }                
        }
        
        digits[0]=1;
        digits.push_back(0);      //如果遇到所有位都是9，则最后将第一位变成1，末尾加0
        //vector中只有末尾加数的push_back(),没法直接头部插数
        //push_back(val)将一个新的元素加到vector的最后面，位置为当前最后一个元素的下一个元素，
        //新的元素的值是val的拷贝（或者是移动拷贝，即&val）
        return digits;
    }
};
__________________________________________________________________________________________________
4ms
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        for(int i = digits.size()-1; i>=0; --i) {
            if (i==digits.size()-1) {
                carry = (digits[i] + 1)/10;
                digits[i] = (digits[i] + 1)%10;
            }
            else {
                int c = (digits[i] + carry)/10;                
                digits[i] = (digits[i] + carry)%10;
                carry = c;
            }
        }
        if(carry != 0) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
__________________________________________________________________________________________________
8344 kb
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool done = false;
        bool mod = 1;
        int i = digits.size()-1;
        while(mod==1&&i>=0)
        {
            done = true;
            digits[i]+=mod;
            mod = digits[i]/10;
            digits[i]%=10;
            i--;
        }
        if(mod==1)
            digits.insert(digits.begin(),1);
        return digits;
    }
};