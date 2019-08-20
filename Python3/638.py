__________________________________________________________________________________________________
sample 64 ms submission
class Solution:
    def shoppingOffers(self, prices, specials, needs):
        def price(special):
            return special[-1]
        def buy_at_cost(needs_remaining):
            return sum(prices[i] * needs_remaining[i] for i in range(len(needs_remaining)))
        def fits(special, needs_remaining):
            for i, qty in enumerate(needs_remaining):
                if special[i] > qty:
                    return False
            return True
        def subtract_special_items(needs_remaining, special):
            return [needs_remaining[i] - special[i] for i in range(len(needs_remaining))]
        def helper(dollars_spent, needs_remaining, start_idx):
            result = buy_at_cost(needs_remaining) + dollars_spent
            for i in range(start_idx, len(specials)):
                special = specials[i]
                if fits(special, needs_remaining):
                    result = min(
                        result,
                        helper(
                            dollars_spent + price(special),
                            subtract_special_items(needs_remaining, special),
                            i
                        )
                    )
            return result
        return helper(0, needs, 0)
__________________________________________________________________________________________________
sample 13116 kb submission
class Solution:
    
    def shoppingOffers(self, price: List[int], special: List[List[int]], needs: List[int],cost=0) -> int:
        
        for x in needs:
            if x<0:
                return float('inf')
      
        c=cost
        for x in range(len(price)):
            c+=price[x]*needs[x]
        
        def deduct(A,B):
            alen=len(A)
            for i in range(alen):
                A[i]-=B[i]
        def add(A,B):
            alen=len(A)
            for i in range(alen):
                A[i]+=B[i]
        
        for x in special:
            if x[-1]+cost>c:
                continue
            deduct(needs,x)
            c=min(c,self.shoppingOffers(price,special,needs,cost+x[-1]))
            add(needs,x)
            
        return c
__________________________________________________________________________________________________
