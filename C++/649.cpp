__________________________________________________________________________________________________
sample 8 ms submission
class Solution {
public:
    string predictPartyVictory(string senate) {
      string curr = senate;  
      int rVotes=0;
      int dVotes=0;
      int bal=0;  
        
      while(abs(bal)!=(int)curr.size()){
        string nextStr;  
        bal=0;  
        for (int i=0; i<(int)curr.size(); i++){
          if (curr[i]=='R'){
            if (dVotes==0){
              rVotes++;
              nextStr+='R';
              bal++;  
            } else dVotes--;   
          } else {
            if (rVotes==0){
              dVotes++;
              nextStr+='D'; 
              bal--;  
            } else rVotes--;  
          }
        }
        curr=nextStr;
      }  
    
      if (curr[0]=='R') return "Radiant";
      return "Dire";  
    }
};
__________________________________________________________________________________________________
sample 9100 kb submission
class Solution {
public:
    string predictPartyVictory(string& senate) {
        int i = 0;
        int r_pos = next(senate, 0, 'R');
        int d_pos = next(senate, 0, 'D');
        while (r_pos != -1 && d_pos != -1) {
            if (senate[i] == 'R') {
                senate[d_pos] = '-';
                d_pos = next(senate, d_pos + 1, 'D');
                if (d_pos != -1) r_pos = next(senate, r_pos + 1, 'R');
            } else if (senate[i] == 'D') {
                senate[r_pos] = '-';
                r_pos = next(senate, r_pos + 1, 'R');
                if (r_pos != -1) d_pos = next(senate, d_pos + 1, 'D');
            }
            i = (i + 1) % senate.size();
        }
        return r_pos == -1 ? "Dire" : "Radiant";
    }
    
    int next(const string& senate, int pos, char party) {
        for (int i = 0; i < senate.size(); i++) {
            int idx = (pos + i) % senate.size();
            if (senate[idx] == party) return idx;
        }
        return -1;
    }
};
__________________________________________________________________________________________________
