__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public int superpalindromesInRange(String L, String R) {
    	long[] res = new long[] {1l, 4l, 9l, 121l, 484l, 10201l, 12321l, 14641l, 40804l, 44944l, 1002001l, 1234321l, 4008004l, 100020001l, 102030201l, 104060401l, 121242121l, 123454321l, 125686521l, 400080004l, 404090404l, 10000200001l, 10221412201l, 12102420121l, 12345654321l, 40000800004l, 1000002000001l, 1002003002001l, 1004006004001l, 1020304030201l, 1022325232201l, 1024348434201l, 1210024200121l, 1212225222121l, 1214428244121l, 1232346432321l, 1234567654321l, 4000008000004l, 4004009004004l, 100000020000001l, 100220141022001l, 102012040210201l, 102234363432201l, 121000242000121l, 121242363242121l, 123212464212321l, 123456787654321l, 400000080000004l, 10000000200000001l, 10002000300020001l, 10004000600040001l, 10020210401202001l, 10022212521222001l, 10024214841242001l, 10201020402010201l, 10203040504030201l, 10205060806050201l, 10221432623412201l, 10223454745432201l, 12100002420000121l, 12102202520220121l, 12104402820440121l, 12122232623222121l, 12124434743442121l, 12321024642012321l, 12323244744232321l, 12343456865434321l, 12345678987654321l, 40000000800000004l, 40004000900040004l};
    	long l = Long.parseLong(L);
    	long r = Long.parseLong(R);
    	int sidx = -1;
    	for(int i=0;i<res.length&&l>res[i];i++) {
    		sidx=i;
    	}
    	int eidx = res.length;
    	for(int i=res.length-1;i>=0&&r<res[i];i--) {
    		eidx=i;
    	}
    	return eidx-sidx-1;
    }
}
__________________________________________________________________________________________________
sample 41996 kb submission
class Solution {
    public int superpalindromesInRange(String sL, String sR) {
        long L = Long.valueOf(sL);
        long R = Long.valueOf(sR);
        int M = 100000;
        int ans = 0;
        
        for (int k = 1; k < M; ++k) {
            StringBuilder sb = new StringBuilder(Integer.toString(k));
            for (int i = sb.length() - 2; i >= 0; --i)
                sb.append(sb.charAt(i));
            long v = Long.valueOf(sb.toString());
            v *= v;
            if (v > R) break;
            if (v >= L && isPalindrome(v)) ans++;
        }
        for (int k = 1; k < M; ++k) {
            StringBuilder sb = new StringBuilder(Integer.toString(k));
            for (int i = sb.length() - 1; i >= 0; --i)
                sb.append(sb.charAt(i));
            long v = Long.valueOf(sb.toString());
            v *= v;
            if (v > R) break;
            if (v >= L && isPalindrome(v)) ans++;
        }
        return ans;
    }
    
    public boolean isPalindrome(long x) {
        return x == reverse(x);
    }
    
    public long reverse(long x) {
        long ans = 0;
        while (x > 0) {
            ans = ans * 10 + x % 10;
            x = x / 10;
        }
        return ans;
    }
}
__________________________________________________________________________________________________
