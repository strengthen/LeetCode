__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
private:
	int get_last(int &x) {
		int n = x % 2;
		x /= 2;
		return n;
	}
public:
	int minFlips(int a, int b, int c) {
		int count = 0;
		int c_last, b_last, a_last;
		while (c != 0) {
			a_last = get_last(a);
			b_last = get_last(b);
			c_last = get_last(c);

			if (c_last) {
				if (!a_last && !b_last)
					count += 1;
			}
			else {
				if (a_last)
					count += 1;
				if (b_last)
					count += 1;
			}
		}
		while (a != 0) {
			if (get_last(a))
				count += 1;
		}
		while (b != 0) {
			if (get_last(b))
				count += 1;
		}
		return count;
	}
};
__________________________________________________________________________________________________
class Solution {
public:
    int minFlips(int a, int b, int c) {
      int mask=1;
      int count=0;
      int bit_a,bit_b,bit_c;
      while (a||b||c){
        bit_a=a&1;
        bit_b=b&1;
        bit_c=c&1;
        if ((bit_a|bit_b)!=bit_c){
          if (bit_a & bit_b){
            count=count+2;
          }
          else{
            ++count;
          }
        }
        a=a>>1;
        b=b>>1;
        c=c>>1;
      }
      return count;
    }
};
__________________________________________________________________________________________________
