__________________________________________________________________________________________________
sample 1 ms submission
class Solution {
    public String[] uncommonFromSentences(String A, String B) {
        HashMap<String, Integer> map = new HashMap<>();
        List<String> wordList = new ArrayList<>();
        simpleSplit(A, wordList);
        simpleSplit(B, wordList);
        int wordNum = wordList.size(), count = 0;
        boolean[] commons = new boolean[wordNum];
        for(int i = 0; i < wordNum; ++i){
            String word = wordList.get(i);
        	Integer b = map.get(word);
        	if(b == null){
            	map.put(word, i);
            	commons[i] = true;
            	++count;
            }else{
            	if(b != -1){
            		--count;
            		commons[b] = false;
            		map.replace(word, b, -1);
            	}
            }
        }
        String[] result = new String[count];
        for(int i = 0, index = 0; i < wordNum; ++i){
        	if(commons[i]){
        		result[index++] = wordList.get(i);
        	}
        }
        return result;
    }
    private void simpleSplit(String str, List<String> wordList){
        int len = str.length(), begin = 0, end = 0;
        while(begin < len){
            end = begin;
            while(++end < len && str.charAt(end) != ' ');
            wordList.add(str.substring(begin, end));
            begin = end + 1;
        }
    }
}
__________________________________________________________________________________________________
sample 35064 kb submission
class Solution {
    public String[] uncommonFromSentences(String A, String B) {
        Map<String,Integer> map = new HashMap();
        String []listA = A.split(" ");
        String []listB = B.split(" ");
        for(int i=0;i<listA.length;i++){
            if(map.containsKey(listA[i])){
                int val = map.get(listA[i]);
                map.put(listA[i],++val);
            }else{
                map.put(listA[i],1);
            }
        }
        for(int j=0;j<listB.length;j++){
            if(map.containsKey(listB[j])){
                int val = map.get(listB[j]);
                map.put(listB[j],++val);
            }else{
                map.put(listB[j],1);
            }
        }
        Map<String,Integer> res =  map.
            entrySet().
            stream().
            filter(x->x.getValue()==1).
            collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));
        List<String> res1 = res.keySet().stream().collect(Collectors.toList());
        String [] result = res1.stream().toArray(String[]::new);
        return result;
    }
}
__________________________________________________________________________________________________
