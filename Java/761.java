__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public String makeLargestSpecial(String S) {
         return visit(0, S);         
    }
    public String visit(int index, String s) {
        if (s.charAt(index) == '0') return "";
        PriorityQueue<String> tokens = new PriorityQueue();
        while(index < s.length() && s.charAt(index) == '1') {
            String token = "1"+visit(index+1, s)+"0";
            index+= token.length();
            tokens.offer(token);
        }
        String result = "";
        while (tokens.size() > 0) result = tokens.poll()+result;
        return result;
    }
}
__________________________________________________________________________________________________
sample 34572 kb submission
class Solution {
    public String makeLargestSpecial(String S) {
        int cnt = 0, i = 0;
		ArrayList<String> v = new ArrayList<String>();
		String res = "";

		for (int j = 0; j < S.length(); ++j) {
			cnt += (S.charAt(j) == '1') ? 1 : -1;

			if (cnt == 0) {
				v.add('1' + makeLargestSpecial(S.substring(i + 1, j)) + '0');
				i = j + 1;
			}
		}

		Collections.sort(v, (x, y) -> y.compareTo(x));

		for (String str : v)
			res += str;

		return res;
    }
}
__________________________________________________________________________________________________
