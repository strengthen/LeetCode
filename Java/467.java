__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public int findSubstringInWraproundString(String p) {
        if(p==null||p.length()==0)return 0;
        int res = 0;
        int[] rec = new int[26];
        int cnt = 1;
        char[] ca = p.toCharArray();
        int start = ca[0]-'a';
        for(int i=1;i<ca.length;i++){
            if((ca[i-1]=='z'&&ca[i]=='a')||(ca[i]==ca[i-1]+1)){//continue
                cnt++;
            }else{//stop sequence
                while(cnt>0){
                    if(cnt>rec[start]){
                        res+=cnt-rec[start];
                        rec[start]=cnt;
                    }
                    cnt--;
                    if(start==25)start=0;
                    else start++;
                }
                cnt=1;
                start=ca[i]-'a';
            }
        }
        while(cnt>0){//last one sequence
            if(cnt>rec[start]){
                res+=cnt-rec[start];
                rec[start]=cnt;
            }
            cnt--;
            if(start==25)start=0;
            else start++;
        }        
        return res;
    }
}
__________________________________________________________________________________________________
sample 3 ms submission
class Solution {
    int[] chs;
    
    public int findSubstringInWraproundString(String p) {
        int[] lens = new int[26];
        int N = p.length();
        chs = new int[N];
        for (int i = 0; i < N; i++) {
            chs[i] = p.charAt(i)-'a';
        }
        
        int start = 0;
        int cur = 0;
        while (cur < N) {
            start = cur;
            while (cur+1 < N && (chs[cur]+1) % 26 == chs[cur+1]) {
                cur++;
            }
            update(lens, start, cur);
            cur++;
        }
        
        int total = 0;
        for (int len: lens) {
            total += len;
        }
        return total;
    }
    
    void update(int[] lens, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (end-i+1 <= lens[chs[i]]) {
                break;
            }
            lens[chs[i]] = end-i+1;
        }
    }
}
__________________________________________________________________________________________________
sample 34912 kb submission
class Solution {
    public int findSubstringInWraproundString(String p) {
		int[] cnt = new int[26];
		int len = 0;
		for(int i=0; i<p.length(); i++) {
			if(i>0 && (p.charAt(i) == p.charAt(i-1) + 1 || p.charAt(i-1) - p.charAt(i) == 25)) {
				len++;
			} else {
				len = 1;
			}
			cnt[p.charAt(i)-'a'] = Math.max(cnt[p.charAt(i)-'a'], len);
		}
		return IntStream.of(cnt).sum();        
    }
}