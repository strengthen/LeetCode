__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    int clumsy(int N) 
    {
        if (N <= 2) return N;
        if (N <= 4) return N + 3;
        
        if ((N - 4) % 4 == 0) return N + 1;
        else if ((N - 4) % 4 <= 2) return N + 2;
        else return N - 1;
    }
};
__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    int clumsy(int N)
    {
      if (N <= 1) return N;
      
      int answer = 0;
      int temp = N;
      vector<char> ops = {'*', '/', '+', '-'};
      for (int n = N-1, op = 0; n >= 1; --n)
      {
        const auto oprtr = ops[op++ % 4];
        
        //cout << "answer " << answer << " n " << n << " oprtr " << oprtr << endl;
        switch (oprtr)
        {
          case '*':
            temp *= n;
            break;
          case '/':
            temp /= n;
            break;
          case '+':
            temp += n;
            break;
          case '-':
            answer += temp;
            temp = -n;
            break;
          default:
            break;
        }
        //cout << "  answer " << answer << endl;
      }
      return answer + temp;
    }
};
__________________________________________________________________________________________________
