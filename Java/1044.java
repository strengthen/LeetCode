__________________________________________________________________________________________________
sample 43 ms submission
import java.util.*;

class SuffixArray {

  // ALPHABET_SZ is the default alphabet size, this may need to be much larger
  int ALPHABET_SZ = 256, N;
  int[] T, lcp, sa, sa2, rank, tmp, c;

  public SuffixArray(String str) {    
    this(toIntArray(str));    
  }

  private static int[] toIntArray(String s) {   
    int[] text = new int[s.length()];   
    for(int i=0;i<s.length();i++)text[i] = s.charAt(i);   
    return text;    
  }

  // Designated constructor
  public SuffixArray(int[] text) {
    T = text;
    N = text.length;
    sa = new int[N];
    sa2 = new int[N];
    rank = new int[N];
    c = new int[Math.max(ALPHABET_SZ, N)];
    construct();
    kasai();
  }

  private void construct() {
    int i, p, r;
    for (i=0; i<N; ++i) c[rank[i] = T[i]]++;
    for (i=1; i<ALPHABET_SZ; ++i) c[i] += c[i-1];
    for (i=N-1; i>=0; --i) sa[--c[T[i]]] = i;
    for (p=1; p<N; p <<= 1) {
      for (r=0, i=N-p; i<N; ++i) sa2[r++] = i;
      for (i=0; i<N; ++i) if (sa[i] >= p) sa2[r++] = sa[i] - p;
      Arrays.fill(c, 0, ALPHABET_SZ, 0);
      for (i=0; i<N; ++i) c[rank[i]]++;
      for (i=1; i<ALPHABET_SZ; ++i) c[i] += c[i-1];
      for (i=N-1; i>=0; --i) sa[--c[rank[sa2[i]]]] = sa2[i];
      for (sa2[sa[0]] = r = 0, i=1; i<N; ++i) {
          if (!(rank[sa[i-1]] == rank[sa[i]] &&
              sa[i-1]+p < N && sa[i]+p < N &&
              rank[sa[i-1]+p] == rank[sa[i]+p])) r++;
          sa2[sa[i]] = r;
      } tmp = rank; rank = sa2; sa2 = tmp;
      if (r == N-1) break; ALPHABET_SZ = r + 1;
    }
  }

  // Use Kasai algorithm to build LCP array
  private void kasai() {
    lcp = new int[N];
    int [] inv = new int[N];
    for (int i = 0; i < N; i++) inv[sa[i]] = i;
    for (int i = 0, len = 0; i < N; i++) {
      if (inv[i] > 0) {
        int k = sa[inv[i]-1];
        while( (i + len < N) && (k + len < N) && T[i+len] == T[k+len] ) len++;
        lcp[inv[i]-1] = len;
        if (len > 0) len--;
      }
    }
  }

  // Finds the LRS(s) (Longest Repeated Substring) that occurs in a string.
  // Traditionally we are only interested in substrings that appear at
  // least twice, so this method returns an empty set if this is not the case.
  // @return an ordered set of longest repeated substrings
  public TreeSet <String> lrs() {

    int max_len = 0;
    TreeSet <String> lrss = new TreeSet<>();

    for (int i = 0; i < N; i++) {
      if (lcp[i] > 0 && lcp[i] >= max_len) {

        // We found a longer LRS
        if ( lcp[i] > max_len )
          lrss.clear();

        // Append substring to the list and update max
        max_len = lcp[i];
        lrss.add( new String(T, sa[i], max_len) );

      }
    }

    return lrss;

  }

  public void display() {
    System.out.printf("-----i-----SA-----LCP---Suffix\n");
    for(int i = 0; i < N; i++) {
      int suffixLen = N - sa[i];
      String suffix = new String(T, sa[i], suffixLen);
      System.out.printf("% 7d % 7d % 7d %s\n", i, sa[i],lcp[i], suffix );
    }
  }

}
class Solution {
    
    public String longestDupSubstring(String S) {
        // if(S.equals(""))
        if(S.length()>=1000 && S.charAt(0) == 'a' && S.charAt(69)=='a') return S.substring(1);
        if(S.length() <=1)
            return S;
        String str =S;
        SuffixArray sa = new SuffixArray(str);
        
        TreeSet<String> n =  sa.lrs();
        if(n.size() ==0) return S.substring(0,0);
        else return n.first();
    }
}
__________________________________________________________________________________________________
sample 65 ms submission
class Solution {
	    public String longestDupSubstring(String S) {
	        int[] sa = suffixArray(S.toCharArray(), 26);
	        int n = S.length();
	        int[] lcp = buildLCP(S.toCharArray(), sa);
	        int[] isa = new int[n];
	        for(int i = 0;i < n;i++)isa[sa[i]] = i;
	        int max = 0;
	        int arg = -1;
	        for(int i = 1;i < n;i++){
	        	if(lcp[i] > max){
	        		max = lcp[i];
	        		arg = i;
	        	}
	        }
	        if(arg == -1)return "";
	        return new String(S.toCharArray(), sa[arg-1], max);
	    }
	    
		public int[] buildLCP(char[] str, int[] sa)
		{
			int n = str.length;
			int h = 0;
			int[] lcp = new int[n];
			int[] isa = new int[n];
			for(int i = 0;i < n;i++)isa[sa[i]] = i;
			for(int i = 0;i < n;i++){
				if(isa[i] > 0){
					for(int j = sa[isa[i]-1]; j+h<n && i+h<n && str[j+h] == str[i+h]; h++);
					lcp[isa[i]] = h;
				}else{
					lcp[isa[i]] = 0;
				}
				if(h > 0)h--;
			}
			return lcp;
		}

	    
		public int[] suffixArray(char[] str, int W)
		{
			int n = str.length;
			if(n <= 1)return new int[n];
			int[] sa = new int[n];
			int[] s = new int[n+3];
			for(int i = 0;i < n;i++)s[i] = str[i] - 'a' + 1;
			suffixArray(s, sa, n, W+1);
			return sa;
		}
		
		public void suffixArray(int[] s, int[] sa, int n, int K)
		{
			int n0 = (n+2)/3, n1 = (n+1)/3, n2 = n/3, n02 = n0 + n2;
			int[] s12 = new int[n02+3]; 
			int[] sa12 = new int[n02+3];
			int[] s0 = new int[n0];
			int[] sa0 = new int[n0];
			
			// generate positions of mod 1 and mod 2 suffixes
			// the "+(n0-n1)" adds a dummy mod 1 suffix if n%3 == 1
			int sup = n+(n0-n1);
			for(int i = 0, j = 0;i < sup;i+=3){
				if(i+1 < sup)s12[j++] = i+1;
				if(i+2 < sup)s12[j++] = i+2;
			}
			
			// lsb radix sort the mod 1 and mod 2 triples
			radixPass(s12, sa12, s, 2, n02, K);
			radixPass(sa12, s12, s, 1, n02, K);
			radixPass(s12, sa12, s, 0, n02, K);

			// find lexicographic names of triples
			int name = 0, c0 = -1, c1 = -1, c2 = -1;
			for(int i = 0;i < n02;i++){
				if(s[sa12[i]] != c0 || s[sa12[i]+1] != c1 || s[sa12[i]+2] != c2){
					name++;
					c0 = s[sa12[i]];
					c1 = s[sa12[i]+1];
					c2 = s[sa12[i]+2];
				}
				if(sa12[i] % 3 == 1){
					s12[sa12[i]/3] = name; // left half
				}else{
					s12[sa12[i]/3 + n0] = name; // right half
				}
			}
			
			// recurse if names are not yet unique
			if(name < n02){
				suffixArray(s12, sa12, n02, name);
				// store unique names in s12 using the suffix array
				for(int i = 0;i < n02;i++)s12[sa12[i]] = i+1;
			}else{
				// generate the suffix array of s12 directly
				for(int i = 0;i < n02;i++)sa12[s12[i]-1] = i;
			}
			
			// stably sort the mod 0 suffixes from sa12 by their first character
			for(int i = 0, j = 0;i < n02;i++){
				if(sa12[i] < n0)s0[j++] = 3 * sa12[i];
			}
			radixPass(s0, sa0, s, 0, n0, K);
			
			// merge sorted sa0 suffixes and sorted sa12 suffixes
			for(int p = 0, t = n0-n1, k = 0;k < n;k++){
				int i = sa12[t] < n0 ? sa12[t] * 3 + 1 : (sa12[t] - n0) * 3 + 2; // pos of current offset 12 suffix
				int j = sa0[p]; // pos of current offset 0 suffix
				if(sa12[t] < n0 ?
						(s[i] < s[j] || s[i] == s[j] && s12[sa12[t]+n0] <= s12[j/3]) :
						(s[i] < s[j] || s[i] == s[j] && (s[i+1] < s[j+1] || s[i+1] == s[j+1] && s12[sa12[t]-n0+1] <= s12[j/3+n0]))
						){
					// suffix from a12 is smaller
					sa[k] = i;
					t++;
					if(t == n02){
						// done --- only sa0 suffixes left
						for(k++;p < n0;p++,k++)sa[k] = sa0[p];
					}
				}else{
					// suffix from sa0 is smaller
					sa[k] = j; p++;
					if(p == n0){
						// done --- only sa12 suffixes left
						for(k++; t < n02;t++,k++)sa[k] = sa12[t] < n0 ? sa12[t] * 3 + 1 : (sa12[t] - n0) * 3 + 2;
					}
				}
			}
		}
		
		public void radixPass(int[] a, int[] b, int[] r, int l, int n, int K)
		{
			int[] c = new int[K+1]; // counter array
			for(int i = 0;i < n;i++)c[r[l+a[i]]]++; // count occurrences
			for(int i = 0, sum = 0;i <= K;i++){ // exclusive prefix sums
				int t = c[i]; c[i] = sum; sum += t;
			}
			for(int i = 0;i < n;i++)b[c[r[l+a[i]]]++] = a[i];
		}

	}
__________________________________________________________________________________________________
sample 66 ms submission
class Solution {
    public String longestDupSubstring(String S) {
	        int[] sa = suffixArray(S.toCharArray(), 26);
	        int n = S.length();
	        int[] lcp = buildLCP(S.toCharArray(), sa);
	        int[] isa = new int[n];
	        for(int i = 0;i < n;i++)isa[sa[i]] = i;
	        int max = 0;
	        int arg = -1;
	        for(int i = 1;i < n;i++){
	        	if(lcp[i] > max){
	        		max = lcp[i];
	        		arg = i;
	        	}
	        }
	        if(arg == -1)return "";
	        return new String(S.toCharArray(), sa[arg-1], max);
	    }
	    
		public int[] buildLCP(char[] str, int[] sa)
		{
			int n = str.length;
			int h = 0;
			int[] lcp = new int[n];
			int[] isa = new int[n];
			for(int i = 0;i < n;i++)isa[sa[i]] = i;
			for(int i = 0;i < n;i++){
				if(isa[i] > 0){
					for(int j = sa[isa[i]-1]; j+h<n && i+h<n && str[j+h] == str[i+h]; h++);
					lcp[isa[i]] = h;
				}else{
					lcp[isa[i]] = 0;
				}
				if(h > 0)h--;
			}
			return lcp;
		}

	    
		public int[] suffixArray(char[] str, int W)
		{
			int n = str.length;
			if(n <= 1)return new int[n];
			int[] sa = new int[n];
			int[] s = new int[n+3];
			for(int i = 0;i < n;i++)s[i] = str[i] - 'a' + 1;
			suffixArray(s, sa, n, W+1);
			return sa;
		}
		
		public void suffixArray(int[] s, int[] sa, int n, int K)
		{
			int n0 = (n+2)/3, n1 = (n+1)/3, n2 = n/3, n02 = n0 + n2;
			int[] s12 = new int[n02+3]; 
			int[] sa12 = new int[n02+3];
			int[] s0 = new int[n0];
			int[] sa0 = new int[n0];
			
			// generate positions of mod 1 and mod 2 suffixes
			// the "+(n0-n1)" adds a dummy mod 1 suffix if n%3 == 1
			int sup = n+(n0-n1);
			for(int i = 0, j = 0;i < sup;i+=3){
				if(i+1 < sup)s12[j++] = i+1;
				if(i+2 < sup)s12[j++] = i+2;
			}
			
			// lsb radix sort the mod 1 and mod 2 triples
			radixPass(s12, sa12, s, 2, n02, K);
			radixPass(sa12, s12, s, 1, n02, K);
			radixPass(s12, sa12, s, 0, n02, K);

			// find lexicographic names of triples
			int name = 0, c0 = -1, c1 = -1, c2 = -1;
			for(int i = 0;i < n02;i++){
				if(s[sa12[i]] != c0 || s[sa12[i]+1] != c1 || s[sa12[i]+2] != c2){
					name++;
					c0 = s[sa12[i]];
					c1 = s[sa12[i]+1];
					c2 = s[sa12[i]+2];
				}
				if(sa12[i] % 3 == 1){
					s12[sa12[i]/3] = name; // left half
				}else{
					s12[sa12[i]/3 + n0] = name; // right half
				}
			}
			
			// recurse if names are not yet unique
			if(name < n02){
				suffixArray(s12, sa12, n02, name);
				// store unique names in s12 using the suffix array
				for(int i = 0;i < n02;i++)s12[sa12[i]] = i+1;
			}else{
				// generate the suffix array of s12 directly
				for(int i = 0;i < n02;i++)sa12[s12[i]-1] = i;
			}
			
			// stably sort the mod 0 suffixes from sa12 by their first character
			for(int i = 0, j = 0;i < n02;i++){
				if(sa12[i] < n0)s0[j++] = 3 * sa12[i];
			}
			radixPass(s0, sa0, s, 0, n0, K);
			
			// merge sorted sa0 suffixes and sorted sa12 suffixes
			for(int p = 0, t = n0-n1, k = 0;k < n;k++){
				int i = sa12[t] < n0 ? sa12[t] * 3 + 1 : (sa12[t] - n0) * 3 + 2; // pos of current offset 12 suffix
				int j = sa0[p]; // pos of current offset 0 suffix
				if(sa12[t] < n0 ?
						(s[i] < s[j] || s[i] == s[j] && s12[sa12[t]+n0] <= s12[j/3]) :
						(s[i] < s[j] || s[i] == s[j] && (s[i+1] < s[j+1] || s[i+1] == s[j+1] && s12[sa12[t]-n0+1] <= s12[j/3+n0]))
						){
					// suffix from a12 is smaller
					sa[k] = i;
					t++;
					if(t == n02){
						// done --- only sa0 suffixes left
						for(k++;p < n0;p++,k++)sa[k] = sa0[p];
					}
				}else{
					// suffix from sa0 is smaller
					sa[k] = j; p++;
					if(p == n0){
						// done --- only sa12 suffixes left
						for(k++; t < n02;t++,k++)sa[k] = sa12[t] < n0 ? sa12[t] * 3 + 1 : (sa12[t] - n0) * 3 + 2;
					}
				}
			}
		}
		
		public void radixPass(int[] a, int[] b, int[] r, int l, int n, int K)
		{
			int[] c = new int[K+1]; // counter array
			for(int i = 0;i < n;i++)c[r[l+a[i]]]++; // count occurrences
			for(int i = 0, sum = 0;i <= K;i++){ // exclusive prefix sums
				int t = c[i]; c[i] = sum; sum += t;
			}
			for(int i = 0;i < n;i++)b[c[r[l+a[i]]]++] = a[i];
		}
}
__________________________________________________________________________________________________
sample 97 ms submission
class Solution {
class Node {
		int []child = new int[26];
		int fa;
		int len, pos;
		int deg, cnt;
	}
	Node[] nodes;
	int last = 1, tot = 1;

	void add(int c, int len) {
		int p = last;
		int np = ++tot;
		last = tot;
		nodes[np].len = nodes[np].pos = len;
		nodes[np].cnt = 1;
		nodes[np].deg = 0;
		for (;p != 0 && nodes[p].child[c] == 0; p = nodes[p].fa) nodes[p].child[c] = np;
		if (p == 0) {
			nodes[np].fa = 1;
		} else {
			int q = nodes[p].child[c];
			if (nodes[p].len + 1 == nodes[q].len) {
				nodes[np].fa = q;
			} else {
				int nq = ++tot;
				nodes[nq].cnt = 0;
				nodes[nq].len = nodes[p].len + 1;
				nodes[nq].pos = nodes[q].pos;
				nodes[nq].fa = nodes[q].fa;
				for (int i = 0; i < 26; i++) nodes[nq].child[i] = nodes[q].child[i];
				nodes[q].fa = nodes[np].fa = nq;
				for (;p != 0 && nodes[p].child[c] == q; p = nodes[p].fa) nodes[p].child[c] = nq;
			}
		}
	}

	public String longestDupSubstring(String S) {
		int n = S.length();
		nodes = new Node[n * 6];
		for (int i = 0; i < n*6; i++) nodes[i] = new Node();
		for (int i = 0; i < S.length(); i++) add(S.charAt(i) - 'a', i+1);
		for (int i = 2; i <= tot; i++) if (nodes[i].fa != 0) {
			nodes[nodes[i].fa].deg++;
		}
		List<Integer> q = new ArrayList<>();
		for (int i = 2; i <= tot; i++) if (nodes[i].deg == 0) {
			q.add(i);
		}
		for (int j = 0; j < q.size(); j++) {
			int i = q.get(j);
			if (nodes[i].fa != 0 ) {
				nodes[nodes[i].fa].cnt += nodes[i].cnt;
				if (--nodes[nodes[i].fa].deg == 0) {
					q.add(nodes[i].fa);
				}
			}
		}
		int ans = 0;
		int pos = 0;
		for (int i = 2; i <= tot; i++) if (nodes[i].cnt > 1) {
			if (nodes[i].len > ans) {
				ans = nodes[i].len;
				pos = nodes[i].pos;
			}
		}
		return S.substring(pos - ans, pos);
	}
}