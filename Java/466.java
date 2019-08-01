__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public int getMaxRepetitions(String s1, int n1, String s2, int n2) {
    
    
    if (n1 == 0) {
            return 0;
        }
        
        int l1 = s1.length();
        int l2 = s2.length();
        int[] indexr = new int[l2 + 1];
        int[] countr = new int[l2 + 1];       
        // index: how many characters of s1 find corresponding ones in s2 so far
        int index = 0, count = 0;
        
        // for the whole s1 * n1 string
        for (int i = 0; i < n1; i++) {
            // for each s1
            for (int j = 0; j < l1; j++) {
                if (s1.charAt(j) == s2.charAt(index)) {
                    index++;
                }
                // complete one repetition of s2
                if (index == l2) {
                    index = 0;
                    count++;
                }
            }
            countr[i] = count;
            // after s1 * i, which character of s2 is now
            indexr[i] = index;
            
            for (int k = 0; k < i; k++) {
                // if find a pattern after s1 * i
                if (indexr[k] == index) {
                    // no pattern before s1 * k
                    int prev_count = countr[k];
                    // the total complete patterns
                    // (n1 - 1 - k) / (i - k): the number of patterns
                    int pattern_count = (countr[i] - countr[k]) * ((n1 - 1 - k) / (i - k));
                    // remain part which is not a full pattern
                    int remain_count = countr[k + (n1 - 1 - k) % (i - k)] - countr[k];
                    return (prev_count + pattern_count + remain_count) / n2;
                }
            }
        }
        return countr[n1 - 1] / n2;
    }
}
__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
	
	int[] F(String prefix, String s1, int n1, String s2) {

		StringBuilder sb = new StringBuilder(prefix);
		for(int i=0; i<n1; ++i) {
			sb.append(s1);
		}

		return F(sb.toString(), s2);
	}

	int[] F(String s1, String s2) {

		int pos = 0;

		int cnt = 0;
		for(int i=0; i<s1.length(); ++i) {
			if(s1.charAt(i) == s2.charAt(pos)) {
				++pos;
				if(pos == s2.length()) {
					pos = 0;
					++cnt;
				}
			}
		}

		return new int[]{pos, cnt};
	}
    
    public int getMaxRepetitions(String s1, int n1, String s2, int n2) {

        if(n1 == 0) return 0;
         int[] ind = new int[s2.length() ];  //startngIndex -> X
         Arrays.fill(ind, -1);
         int[][] cnt = new int[2* (s2.length() + 2)][2];  // X -> number of s2 we can obtain
             
         int loopStart = -1;
         int loopLen = -1;

         StringBuilder sb = new StringBuilder();
         for(int X=1; ; ++X) {
         	sb.append(s1);

         	int[] tmp = F(sb.toString(), s2);
             cnt[X] = tmp;
         	if(ind[tmp[0]] > 1) {
         		loopStart = ind[tmp[0]];
         		loopLen = X - ind[tmp[0]];
                break;
         	}else {
         		ind[tmp[0]] = X;
         	}


         }
         int x = (loopStart == 0? 0: cnt[loopStart - 1][1]);
         int y = cnt[loopStart + loopLen - 1][1] - x;
         int total = 0;
         if(n1 <= loopStart) {
         	total = F("", s1, n1, s2)[1];
         }else {
         	int part1 = ((n1 - loopStart + 1)/loopLen) * y + x;
         	int part2 = F((loopStart == 0?"": s2.substring(0, cnt[loopStart - 1][0]) ), s1, (n1-loopStart + 1)%loopLen, s2)[1];
            
         	total = part1 + part2;
         }
         return total/n2;

    }
}
__________________________________________________________________________________________________
sample 35328 kb submission
class Solution {
    public int getMaxRepetitions(String s1, int n1, String s2, int n2) {
        int i = 0;
        int j = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        while(cnt1 < n1)
        {
            while(i < s1.length())
            {
                if(s1.charAt(i) == s2.charAt(j))
                {
                    i++;
                    j++;
                    if(j == s2.length())
                    {
                        j = 0;
                        cnt2++;
                    }
                }
                else
                {
                    i++;
                }
                
                    if(i == s1.length())
                    {
                        i = 0;
                        cnt1++;
                        break;
                    }
            }
        }
        
        return cnt2/n2;
    }
}