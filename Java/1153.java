__________________________________________________________________________________________________
class Solution {
    public boolean canConvert(String str1, String str2) {
        if (str1.length()!=str2.length())
            return false;
        HashSet<Character> c1temp = new HashSet<>();
        HashSet<Character> c2temp = new HashSet<>();
        for (char c : str1.toCharArray())
            c1temp.add(c);
        for (char c : str2.toCharArray())
            c2temp.add(c);
        if (c2temp.size()==26 || c1temp.size() < c2temp.size())
            return str1.equals(str2);
        
        int index = 0;
        HashMap<Character, Integer> hm1 = new HashMap<>();
        HashMap<Character, Integer> hm2 = new HashMap<>();
        for (int i = 0; i < str1.length(); i++) {
            char c1 = str1.charAt(i);
            char c2 = str2.charAt(i);
            int i1 = 0;
            int i2 = 0;
            if (!hm2.containsKey(c2)) {
                if (hm1.containsKey(c1))
                    return false;
                hm2.put(c2, ++index);
                hm1.put(c1, index);
            }
            if (!hm1.containsKey(c1)) {
                hm1.put(c1, hm2.get(c2));
            }
            if (hm1.get(c1) != hm2.get(c2))
                return false;
        }
        return true;
    }
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________
