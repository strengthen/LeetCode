__________________________________________________________________________________________________
16ms
#include <vector>
vector<int> reverse_input;

static const auto speedup = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();


class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;                
        reverse_input.clear();
                
        while (x) {
            reverse_input.push_back(x%10);
            x/=10;
        }
        
        int back = reverse_input.size()-1;
        for (int i=0; i<reverse_input.size()/2; ++i) {
            if (back == i) return true;
            
            if (reverse_input[i] != reverse_input[back]) {
                return false;
            }
            
            --back;
        }
        
        return true;
    }
};
__________________________________________________________________________________________________
28ms
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int temp = x;
        long int n = 0;
        while(x!=0){
            n = n*10  +  x%10;
            x = x/10; 
        }
        if(n==temp) return true;
        else return false;
    }
};
__________________________________________________________________________________________________
32ms
#include<bits/stdc++.h>

class Solution {
public:
    bool isPalindrome(int x) {
        unsigned int revNum=0;
        int nbr = x;
        if (x == 0)
            return true;
        if (x < 0)
            return false;
        
        while (nbr != 0)
        {
            /*
            if (INT_MAX/10 == revNum)
                return false;
                */
            revNum = revNum*10 + nbr%10;
            nbr=nbr/10;
        }
        if ((revNum == x) || ((revNum/10) == x))
            return true;
        else
            return false;
    }
};
__________________________________________________________________________________________________
8000 kb
static int x=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool isPalindrome(int x) {
        if(x == 0) return true;
        if(x<0 || x%10 == 0) return false;
        int sum =0;
        while(sum <= x) {
            if(sum == x || sum == x/10) return true;
            sum *=10;
            sum += x%10;
            x /= 10;
        }
        return false;
    }
};
__________________________________________________________________________________________________
8012 kb
class Solution {
public:
    bool isPalindrome(int x) {
      if(x<0|| (x!=0 &&x%10==0)) return false;
        int sum=0;
        while(x>sum)
        {
            sum = sum*10+x%10;
            x = x/10;
        }
        return (x==sum)||(x==sum/10);
    
    }
};
 static int festio=[](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(0);
    return 0;
 }();
__________________________________________________________________________________________________
