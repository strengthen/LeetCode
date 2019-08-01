__________________________________________________________________________________________________
sample 2 ms submission
import java.util.ArrayList;
import java.util.List;

/*
 * @lc app=leetcode id=638 lang=java
 *
 * [638] Shopping Offers
 */
class Solution {
    public int shoppingOffers(List<Integer> price, List<List<Integer>> special, List<Integer> needs) {
        return getMinPrice(price, special, needs, 0);
    }

    private int getMinPrice(List<Integer> price, List<List<Integer>> special, List<Integer> needs, int offerIndex) {
        int min = getDirectPrice(price, needs);
        if (offerIndex == special.size()) {
            return min;
        }
        for (int i = offerIndex; i < special.size(); i++) {
            List<Integer> offer = special.get(i);
            if (isValidOffer(offer, needs)) {
                List<Integer> rest = new ArrayList<>();
                for (int j = 0; j < needs.size(); j++) {
                    rest.add(needs.get(j) - offer.get(j));
                }
                min = Math.min(min, offer.get(offer.size() - 1) + getMinPrice(price, special, rest, i));
            }
        }
        return min;
    }

    private int getDirectPrice(List<Integer> price, List<Integer> needs) {
        int total = 0;
        for (int i = 0; i < price.size(); i++) {
            total += price.get(i) * needs.get(i);
        }
        return total;
    }

    private boolean isValidOffer(List<Integer> offer, List<Integer> needs) {
        for (int i = 0; i < needs.size(); i++) {
            if (needs.get(i) < offer.get(i)) {
                return false;
            }
        }
        return true;
    }
}
__________________________________________________________________________________________________
sample 39588 kb submission
class Solution {
    public int shoppingOffers(List<Integer> price, List<List<Integer>> special, List<Integer> needs) {
        return shoppingOffersA(price, special, needs);
    }
    
    Map<Integer, Integer> computedPrices = new HashMap<>();
    public int shoppingOffersA(List<Integer> price, List<List<Integer>> special, List<Integer> needs) {
        if(isCompleted(needs)) {
            return 0;
        }
        
        int key = getKey(needs);
        if(computedPrices.containsKey(key)) {
            return computedPrices.get(key);
        }
        
        List<List<Integer>> validSpecial = new ArrayList<>(special.size());
        for(List<Integer> offer: special) {
            if(isOfferValid(offer, needs)) {
                validSpecial.add(offer);
            }
        }
        
        int minCost = withOutSpecialPrice(needs, price);
        
        for(List<Integer> offer: validSpecial) {
            int offerPrice = offer.get(offer.size()-1);
            List<Integer> newNeeds = computeNextNeed(needs, offer);
            int totalCost = shoppingOffersA(price, validSpecial, newNeeds) + offerPrice;
            minCost = Math.min(minCost, totalCost);
        }
        
        computedPrices.put(key, minCost);
        return minCost;
    }
    
    
    private List<Integer> computeNextNeed(List<Integer> needs, List<Integer> offer) {
        
        List<Integer> newNeeds = new ArrayList<>(needs.size());
        for(int i=0;i<needs.size();i++) {
            newNeeds.add(needs.get(i)-offer.get(i));
        }
        return newNeeds;
    }
    
    private boolean isCompleted(List<Integer> needs) {
        for(int need: needs) {
            if(need>0){
                return false;
            }
        }
        return true;
    }
    
    private boolean isOfferValid(List<Integer> offer, List<Integer> needs) {
        for(int i=0;i<needs.size();i++) {
            if(needs.get(i)<offer.get(i)) {
                return false;
            }
        }
        return true;
    }
    
    private int getKey(List<Integer> quantities) {
        int val = 0;
        for(int q: quantities) {
            val = (val*10) + q;
        }
        return val;
    }
    public int withOutSpecialPrice(List < Integer > needs, List < Integer > price) {
        int sum = 0;
        for (int i = 0; i < needs.size(); i++) {
            sum += needs.get(i) * price.get(i);
        }
        return sum;
    }
}
__________________________________________________________________________________________________
