__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
bool isPalindrome(int x){
    return isPalindrome(to_string(x));
}
bool isPalindrome(const string& x){
    if(x.empty()){
        return true;
    }
    int i = 0;
    int j = x.size()-1;
    while(i<j){
        if(x[i]!=x[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

bool isPrime(int x){
    int q = sqrt(x);
    for(int i=2;i<=q;i++){
        if(x%i==0){
            return false;
        }
    }
    return true;
}

int makePalindrome(int x){
    auto tmp = makePalindrome(to_string(x));
    return atoi(tmp.c_str());
}
string makePalindrome(const string& str){
    string tmp(str);
    int i = 0;
    int j = str.size() -1;
    while(i<j){
        if(tmp[i]<tmp[j]){
            tmp[j] = tmp[i];
        }
        else if(tmp[i]>tmp[j]){
            tmp[j] = tmp[i];
            if(isPalindrome(tmp.substr(i+1,j-i-1))){
                // could be a recursive version, which is more effective
                return tmp;
            }
        }
        i++;
        j--;
    }
    if(tmp.size()%2){
        i = j = tmp.size()/2;
        if(tmp[i]<'9'){
            tmp[i]+=1;
            return tmp;
        }
        else{
            tmp[i] = '0';
            i--;
            j++;
        }   
    }
    else{
        i = tmp.size()/2 - 1;
        j = i + 1;
    }
    while(i>=0&&j<tmp.size()){
        if(tmp[i]<'9'){
            tmp[i] = tmp[j] = tmp[i] + 1;
            return tmp;
        }
        else{
            tmp[i] = tmp[j] ='0';
        }
    }
    tmp[0] = '1';
    tmp +='1';
    return tmp;
}
    
int nextPalindrome(int N) {
	string tmp = to_string(N);
	int i, j;
	if (tmp.size() % 2) {
		i = j = tmp.size() / 2;
		if (tmp[i] < '9') {
			tmp[i] += 1;
			return atoi(tmp.c_str());
		}
		else {
			tmp[i] = '0';
			i--;
			j++;
		}
	}
	else {
		i = tmp.size() / 2 - 1;
		j = i + 1;
	}
	while (i >= 0 && j < tmp.size()) {
		if (tmp[i] < '9') {
			tmp[i] = tmp[j] = tmp[i] + 1;
			return atoi(tmp.c_str());
		}
		else {
			tmp[i] = tmp[j] = '0';
		}
		i--;
		j++;
	}
	tmp[0] = '1';
	tmp = tmp + '1';
	return atoi(tmp.c_str());
}

public:
    int primePalindrome(int N) {
        if(N==1){
            return 2;
        }
        if(!isPalindrome(N)){
            N = makePalindrome(N);
        }
        while(true){
            if(isPrime(N)){
                return N;
            }
            N = nextPalindrome(N);
        }
    }
   
};
__________________________________________________________________________________________________
sample 8364 kb submission
class Solution {
public:
    bool isPrime(int N) {
        if (N <= 1) return false;
        for (int i = 2; i * i <= N; i++) {
            if (N % i == 0) return false;
        }   
        return true;
    }
    
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int mask = 1;
        while (x / mask >= 10) mask *= 10;
        while (x > 0) {
            if ((x / mask) != (x % 10)) return false;
            x %= mask;
            x /= 10;
            mask /= 100;
        }
        return true;
    }
    
    int primePalindrome(int N) {
        while (true) {
            if (isPalindrome(N) && isPrime(N))
                return N;
            ++N;
        }
    }
};
__________________________________________________________________________________________________
