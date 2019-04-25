__________________________________________________________________________________________________
sample 4 ms submission
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = num;
        
        while (l <= r) {
            int m = l + (r-l)/2;
            if (m >= num/m) r = m-1;
            else l = m+1;
        }
        
        return l == num/l && num%l == 0;
    }
};
__________________________________________________________________________________________________
sample 7832 kb submission
class Solution {
public:
    bool isPerfectSquare(int num) { /*if(num==1||num==4||num==9||num==16||num==25||num==36||num==49||num==64||num==81||num==100||num==808201||num==104976||num==100489||num==64516||num==93025||num==361201||num==223729||num==2401||num==602176||num==84100||num==804609||num==765625||num==8836||num==972196||num==559504||num==24025||num==16641||num==373321||num==309136||num==87025||num==829921||num==32761||num==641601||num==241081||num==380689||num==1156||num==401956||num==324||num==2147395600)
        return true;
      return false;*/
      int start=46341;
      int end=0;
      int idx;
      while(1)
      {
        idx=(start+end)/2*((start+end)/2);
        if(idx>num)
          start = (start+end)/2;
        else if(idx<num)
          end = (start+end)/2;
        else
          return true;
        if((start+end)/2*((start+end)/2)==idx)
        {
          cout<<idx;
          return false;
        }
        cout<<idx<<endl;
      }
    }
};
__________________________________________________________________________________________________
