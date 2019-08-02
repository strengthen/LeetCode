__________________________________________________________________________________________________
sample 1 ms submission
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface Master {
 *     public int guess(String word) {}
 * }
 */
class Solution {
    public void findSecretWord(String[] wordlist, Master master) {
        int score = -1;
        String randomString = null;
        do {
            randomString = wordlist[new Random().nextInt(wordlist.length)];
            score = master.guess(randomString);
        } while (score == -1);
    
        if (score == 6) {
            return;
        }
        
        String[] sublist = getSubsetWithMatchingScore(score, randomString, wordlist);
        if (sublist.length == 1) {
            master.guess(sublist[0]);
            return;
        }
        findSecretWord(sublist, master);
    }
    
    private String[] getSubsetWithMatchingScore(int score, String word, String[] wordlist) {
        List<String> sublist = new ArrayList<>();
        for (String str: wordlist) {
            int tempScore = 0;
            for (int i = 0; i < str.length(); i++) {
                if (str.charAt(i) == word.charAt(i)) {
                    tempScore++;
                }
            }
            if (tempScore == score) {
                sublist.add(str);
            }
        }
        
        return sublist.toArray(new String[0]);
    }
}
__________________________________________________________________________________________________
sample 25704 kb submission
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface Master {
 *     public int guess(String word) {}
 * }
 */
class Solution {
    public void findSecretWord(String[] wordlist, Master master) {
        int[] count = new int[6];
        String pick = "";
        for (int t = 0, len = wordlist.length; t < 10; t++) {
            int min = len;
            for (int i = 0; i < len; i++) {
                for (int j = 0; j < len; j++) {
                    if (i != j) {
                        int match = match(wordlist[i], wordlist[j]);
                        count[match] += 1;
                    }
                }

                int max = 0;
                for (int j = 0; j < 6; j++) {
                    max = Math.max(max, count[j]);
                }

                Arrays.fill(count, 0);
                if (max < min) {
                    min = max;
                    pick = wordlist[i];
                }
            }


            int match = master.guess(pick);
            System.out.println(pick);
            if (match == 6) {
                break;
            }

            int nl = 0;
            for (int i = 0; i < len; i++) {
                if (match(pick, wordlist[i]) == match) {
                    wordlist[nl++] = wordlist[i];
                }
            }
            len = nl;
        }
    }

    private int match(String a, String b) {
        int ret = 0;
        for (int i = 0; i < 6; i++) {
            if (a.charAt(i) == b.charAt(i)) {
                ret += 1;
            }
        }
        return ret;
    }
}
__________________________________________________________________________________________________
