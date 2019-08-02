__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
    public String pushDominoes(String dominoes) {
        
        char[] dom = dominoes.toCharArray();
        
        int N = dom.length;
        for(int i=0; i< N;i++){
            
            if(dom[i] == '.') continue;
            
            if(dom[i] == 'R'){
                int count = 0,j=i+1;
              //  System.out.println("Processing R "+ i);
                while(j<N && dom[j] != 'L') {
                    if(dom[j]=='R') {
                        while(i < j) dom[i++] ='R';
                    } 
                    j++;
                    
                }
                int k = i+1;
                int p = j;
                if(j == N && dom[N-1] !='L'){
                    while(k < N) dom[k++] ='R';
                    break;
                }
                j--;
                
                while(k < j){
                  //  System.out.println("Moving ahead  "+ k + ",  " + j);
                    dom[k] = 'R';
                    dom[j] = 'L';
                    k++;
                    j--;
                }
                i=p;
            } else{
                int j = i-1;
                while(j >= 0 && dom[j] !='R' && dom[j] !='L'){
                   // System.out.println("Processing L "+ j);
                    dom[j]='L';
                    j--;
                } 
            }
            
        }
        return new String(dom);
    }
}
__________________________________________________________________________________________________
sample 38520 kb submission
class Solution {
    public String pushDominoes(String dominoes) {
        if (dominoes == null || dominoes.length() <= 1) {
            return dominoes;
        }
        int len = dominoes.length();
        int[] leftDis = new int[len];
        Arrays.fill(leftDis, Integer.MAX_VALUE);
        char prev = '.';
        int lastIndex = -1;
        for (int i = 0; i < len; i++) {
            char c = dominoes.charAt(i);
            if (c == 'R') {
                prev = 'R';
                lastIndex = i;
            } else if (c == 'L') {
                prev = '.';
            } else {
                if (prev == 'R') {
                    leftDis[i] = i - lastIndex;
                }
            }
        }
        int[] rightDis = new int[len];
        Arrays.fill(rightDis, Integer.MAX_VALUE);
        prev = '.';
        lastIndex = len;
        for (int i = len - 1; i >= 0; i--) {
            char c = dominoes.charAt(i);
            if (c == 'L') {
                prev = 'L';
                lastIndex = i;
            } else if (c == 'R') {
                prev = '.';
            } else {
                if (prev == 'L') {
                    rightDis[i] = lastIndex - i;
                }
            }
        }
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < len; i++) {
            char c = dominoes.charAt(i);
            if (c == 'L' || c == 'R') {
                res.append(c);
            } else {
                if (leftDis[i] == rightDis[i]) {
                    res.append('.');
                } else if (leftDis[i] < rightDis[i]) {
                    res.append('R');
                } else {
                    res.append('L');
                }
            }
        }
        return res.toString();
    }
}
__________________________________________________________________________________________________
