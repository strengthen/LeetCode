__________________________________________________________________________________________________
sample 2 ms submission
class Solution {
    public boolean isNStraightHand(int[] hand, int W) {
        int [] groups =new int[W];
        for(int i=0;i<hand.length;i++) {
            groups[hand[i]%W]++;
        }
        int val = groups[0];
        for(int i=1;i<groups.length;i++) {
            if (groups[i] != val) return false;
        }
        return true;
    }
}
__________________________________________________________________________________________________
sample 38356 kb submission
import java.util.*;
class Solution {
    public boolean isNStraightHand(int[] hand, int W) {
        
        if (hand == null || hand.length % W != 0) {
            return false;
        }
        
        int numberOfGroups = hand.length / W;
        
        TreeMap<Integer, Integer> cardToCount = new TreeMap<>();
        for (int i = 0; i < hand.length; i++) {
            int card = hand[i];
            int existingCards = cardToCount.getOrDefault(card, 0);
            cardToCount.put(card, existingCards + 1);
        }
        
        for (int i = 0; i < numberOfGroups; i++) {
            
            Integer lastCard = null;
            
            for (int j = 0; j < W; j++) {
                Map.Entry<Integer,Integer> leastKeyEntry = null; // more appropriate naming should be next larger key
                if (j == 0) {    
                    leastKeyEntry = cardToCount.firstEntry();
                    lastCard = leastKeyEntry.getKey();
                } else {
                    leastKeyEntry = cardToCount.higherEntry(lastCard);
                    if (leastKeyEntry == null || leastKeyEntry.getKey() - lastCard != 1) {
                        

                        return false;
                    }
                    lastCard = leastKeyEntry.getKey();
                }
                
                if (leastKeyEntry.getValue() - 1 == 0) {
                    cardToCount.remove(leastKeyEntry.getKey());
                } else {
                    cardToCount.compute(leastKeyEntry.getKey(), (k, v) -> v - 1);
                }
            }
        }
        return true;
    }
}
__________________________________________________________________________________________________
