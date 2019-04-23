__________________________________________________________________________________________________
4ms
class Solution {
    private Map<String, Integer> map;
    
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> res = new ArrayList<>();
        int n = s.length();
        int m = words.length;
        if(n == 0 || m == 0){
            return res;
        }
        int len = words[0].length();
        int window = len * m;
        if(n < window){
            return res;
        }
    
        map = new HashMap<>();
        for (String word : words) {
            map.put(word, map.getOrDefault(word, 0) + 1);
        }

        for(int i = 0; i < len; i++){
            for(int j = i; j < n - window + 1; j += len){
                int k;
                Map<String, Integer> curMap = new HashMap<>();
                for(k = m - 1; k >= 0; k--){
                    String temp = s.substring(j + k * len, j + (k + 1) * len);
                    if(!map.containsKey(temp)){
                        j += k * len;
                        break;
                    }
                    curMap.put(temp, curMap.getOrDefault(temp, 0) + 1);
                    if(curMap.get(temp) > map.get(temp)){
                        j += k * len;
                        break;
                    }
                }
                if(k < 0){
                    res.add(j);
                }
            }
        }
        return res;
    }
}
__________________________________________________________________________________________________
5ms
class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
int N = s.length();
	List<Integer> indexes = new ArrayList<Integer>(s.length());
	if (words.length == 0) {
		return indexes;
	}
	int M = words[0].length();
	if (N < M * words.length) {
		return indexes;
	}
	int last = N - M + 1;
	
	//map each string in words array to some index and compute target counters
	Map<String, Integer> mapping = new HashMap<String, Integer>(words.length);
	int [][] table = new int[2][words.length];
	int failures = 0, index = 0;
	for (int i = 0; i < words.length; ++i) {
		Integer mapped = mapping.get(words[i]);
		if (mapped == null) {
			++failures;
			mapping.put(words[i], index);
			mapped = index++;
		}
		++table[0][mapped];
	}
	
	//find all occurrences at string S and map them to their current integer, -1 means no such string is in words array
	int [] smapping = new int[last];
	for (int i = 0; i < last; ++i) {
		String section = s.substring(i, i + M);
		Integer mapped = mapping.get(section);
		if (mapped == null) {
			smapping[i] = -1;
		} else {
			smapping[i] = mapped;
		}
	}
	
	//fix the number of linear scans
	for (int i = 0; i < M; ++i) {
		//reset scan variables
		int currentFailures = failures; //number of current mismatches
		int left = i, right = i;
		Arrays.fill(table[1], 0);
		//here, simple solve the minimum-window-substring problem
		while (right < last) {
			while (currentFailures > 0 && right < last) {
				int target = smapping[right];
				if (target != -1 && ++table[1][target] == table[0][target]) {
					--currentFailures;
				}
				right += M;
			}
			while (currentFailures == 0 && left < right) {
				int target = smapping[left];
				if (target != -1 && --table[1][target] == table[0][target] - 1) {
					int length = right - left;
					//instead of checking every window, we know exactly the length we want
					if ((length / M) ==  words.length) {
						indexes.add(left);
					}
					++currentFailures;
				}
				left += M;
			}
		}
		
	}
	return indexes;
}}
__________________________________________________________________________________________________
6ms
class Solution {
   public List<Integer> findSubstring(String s, String[] words) {
    List<Integer> res = new ArrayList<Integer>();
    int wordNum = words.length;
    if (wordNum == 0) {
        return res;
    }
    int wordLen = words[0].length();
    HashMap<String, Integer> allWords = new HashMap<String, Integer>();
    for (String w : words) {
        int value = allWords.getOrDefault(w, 0);
        allWords.put(w, value + 1);
    }
    //将所有移动分成 wordLen 类情况
    for (int j = 0; j < wordLen; j++) {
        HashMap<String, Integer> hasWords = new HashMap<String, Integer>();
        int num = 0; //记录当前 HashMap2（这里的 hasWords 变量）中有多少个单词
        //每次移动一个单词长度
        for (int i = j; i < s.length() - wordNum * wordLen + 1; i = i + wordLen) {
            boolean hasRemoved = false; //防止情况三移除后，情况一继续移除
            while (num < wordNum) {
                String word = s.substring(i + num * wordLen, i + (num + 1) * wordLen);
                if (allWords.containsKey(word)) {
                    int value = hasWords.getOrDefault(word, 0);
                    hasWords.put(word, value + 1);
                    //出现情况三，遇到了符合的单词，但是次数超了
                    if (hasWords.get(word) > allWords.get(word)) {
                        // hasWords.put(word, value);
                        hasRemoved = true;
                        int removeNum = 0;
                        //一直移除单词，直到次数符合了
                        while (hasWords.get(word) > allWords.get(word)) {
                            String firstWord = s.substring(i + removeNum * wordLen, i + (removeNum + 1) * wordLen);
                            int v = hasWords.get(firstWord);
                            hasWords.put(firstWord, v - 1);
                            removeNum++;
                        }
                        num = num - removeNum + 1; //加 1 是因为我们把当前单词加入到了 HashMap 2 中
                        i = i + (removeNum - 1) * wordLen; //这里依旧是考虑到了最外层的 for 循环，看情况二的解释
                        break;
                    }
                //出现情况二，遇到了不匹配的单词，直接将 i 移动到该单词的后边（但其实这里
                //只是移动到了出现问题单词的地方，因为最外层有 for 循环， i 还会移动一个单词
                //然后刚好就移动到了单词后边）
                } else {
                    hasWords.clear();
                    i = i + num * wordLen;
                    num = 0;
                    break;
                }
                num++;
            }
            if (num == wordNum) {
                res.add(i);

            }
            //出现情况一，子串完全匹配，我们将上一个子串的第一个单词从 HashMap2 中移除
            if (num > 0 && !hasRemoved) {
                String firstWord = s.substring(i, i + wordLen);
                int v = hasWords.get(firstWord);
                hasWords.put(firstWord, v - 1);
                num = num - 1;
            }
        }
    }
    return res;
}    
}
__________________________________________________________________________________________________
36188 kb
class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
    List<Integer> result = new ArrayList<>(s.length());
    if (words == null || words.length == 0) {
      return result;
    }
    Map<String, Integer> map = new HashMap<>();
    for (String word : words) {
      map.put(word, map.getOrDefault(word, 0) + 1);
    }
    int wordLength = words[0].length();
    int numOfWords = words.length;
    int totalLength = wordLength * numOfWords;
    for (int offset = 0; offset < wordLength; offset++) {
      Map<String, Integer> wordToCounter = new HashMap<>(map);
      int diff = numOfWords;
      for (int toAddIndex = offset; toAddIndex + wordLength <= s.length(); toAddIndex += wordLength) {
        String toAdd = s.substring(toAddIndex, toAddIndex + wordLength);
        wordToCounter.put(toAdd, wordToCounter.getOrDefault(toAdd, 0) - 1);
        if (wordToCounter.get(toAdd) >= 0) {
          diff--;
        }
        if (toAddIndex >= offset + totalLength) {
          String toRemove = s.substring(toAddIndex - totalLength, toAddIndex - totalLength + wordLength);
          wordToCounter.put(toRemove, wordToCounter.getOrDefault(toRemove, 0) + 1);
          if (wordToCounter.get(toRemove) > 0) {
            diff++;
          }
        }
        if (diff == 0) {
          result.add(toAddIndex + wordLength - totalLength);
        }
      }
    }
    return result;
    }
}
__________________________________________________________________________________________________
36232 kb
class Solution {
    public static List<Integer> findSubstring(String s, String[] words) {
		List<Integer> sol = new ArrayList<Integer>();
		if (words.length == 0 || words[0].length() == 0)
			return sol;
		int wordLen = words[0].length(), listLen = words.length, strLen = s.length(), maxIdx = strLen - wordLen * listLen;
		if (maxIdx < 0)
			return sol;
		Map<String, Integer> map = new HashMap<String, Integer>(listLen*4);
		for (String ss : words)
			map.put(ss, map.getOrDefault(ss, 0) + 1);
		
        char cs[] = s.toCharArray();
		for (int i = 0; i < wordLen; i++) {
			for (int j = i; j <= maxIdx; j += wordLen) {
                String fi = new String(cs,j, wordLen);
                if(map.getOrDefault(fi, 0)==0){
                    continue;
                }
                Map<String, Integer> temp = new HashMap<String, Integer>(listLen*4);
				for (int k = listLen - 1; k >= 0; k--) {
					String str = new String(cs,k * wordLen + j, wordLen);
					int num = temp.getOrDefault(str, 0) + 1;
					if (num > map.getOrDefault(str, 0)) {
						j += k * wordLen;
						break;
					} else if (k == 0)
						sol.add(j);
					else
						temp.put(str, num);
				}
			}
		}
		return sol;
	}
}
__________________________________________________________________________________________________
