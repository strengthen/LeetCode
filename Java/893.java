__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    private String hash(String a) {
            char[] count = new char[52];
            int index = 0;
            Arrays.fill(count, 'a');
            for (char c : a.toCharArray()) {
                count[c - 'a' + 26 * (index % 2)]++;
                index++;
            }
            return new String(count);
        }

        public int numSpecialEquivGroups(String[] A) {
            HashSet<String> set = new HashSet<>();
            for (String aString : A) {
                set.add(hash(aString));
            }
            return set.size();
        }
}
__________________________________________________________________________________________________
sample 36340 kb submission
class Solution {
    public int numSpecialEquivGroups(String[] A) {
        final List<List<Character>> input = 
            Arrays.stream(A)
            .map(str -> str.chars().mapToObj(ch -> Character.valueOf((char) ch)).collect(Collectors.toList()))
            .collect(Collectors.toList());
        
        final Set<String> group = new HashSet();
        input.forEach(charList -> {
            final List<Character> sortedEven = 
                IntStream.range(0, charList.size())
                .filter(index -> index % 2 == 0)
                .mapToObj(index -> charList.get(index))
                .sorted()
                .collect(Collectors.toList());
            
            final List<Character> sortedOdd = 
                IntStream.range(0, charList.size())
                .filter(index -> index % 2 == 1)
                .mapToObj(index -> charList.get(index))
                .sorted()
                .collect(Collectors.toList());
            
            group.add(sortedEven.toString() + sortedOdd.toString());
        });
        
        return group.size();
    }
}
__________________________________________________________________________________________________
