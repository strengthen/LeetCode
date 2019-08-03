__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
    public List<Boolean> camelMatch(String[] queries, String pattern) {
      List<Boolean> res = new ArrayList<>();
      for (String query : queries) {
        res.add(match(query, pattern));
      }
      return res;
    }
  
    boolean match(String query, String pattern) {
      int queryPoint = 0;
      int patternPoint = 0;
      while (queryPoint < query.length() 
             && patternPoint < pattern.length()) {
        while (queryPoint < query.length() 
               && query.charAt(queryPoint) !=
               pattern.charAt(patternPoint)) {
          if (isCapital(query.charAt(queryPoint)))
            return false;
          queryPoint++;
        }
        if (queryPoint == query.length()) {
          return false;
        }
        queryPoint++;
        patternPoint++;
      }
      if (patternPoint == pattern.length()) {
        while (queryPoint < query.length()) {
          if (isCapital(query.charAt(queryPoint)))
            return false;
          queryPoint++;
        }
        return true;
      }
      return false;
    }
  
    boolean isCapital(char c) {
      return c >='A' && c <= 'Z';
    }
}
__________________________________________________________________________________________________
sample 34700 kb submission
class Solution {
    public List<Boolean> camelMatch(String[] queries, String pattern) {
        return Arrays.stream(queries).map(q -> doesMatchPattern(q, pattern)).collect(Collectors.toList());
    }
    
    private boolean doesMatchPattern(String query, String pattern) {
        char[] queryArr = query.toCharArray();
        int j = 0;
        for (int i = 0; i < queryArr.length; i++) {
            if (j < pattern.length() && queryArr[i] == pattern.charAt(j)) {
                j++;
            } else if (Character.isUpperCase(queryArr[i])) {
                return false;
            }
        }
        
        return j == pattern.length();
    }
}
__________________________________________________________________________________________________
