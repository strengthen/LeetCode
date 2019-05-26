__________________________________________________________________________________________________
class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], X: int) -> int:
        
        # Part 1 requires counting how many customers
        # are already satisfied, and removing them
        # from the customer list.
        already_satisfied = 0
        for i in range(len(grumpy)):
            if grumpy[i] == 0: #He's happy
                already_satisfied += customers[i]
                customers[i] = 0
        
        # Part 2 requires finding the optinal number
        # of unhappy customers we can make happy.
        best_we_can_make_satisfied = 0
        current_satisfied = 0
        for i, customers_at_time in enumerate(customers):
            current_satisfied += customers_at_time # Add current to rolling total
            if i >= X: # We need to remove some from the rolling total
                current_satisfied -= customers[i - X]
            best_we_can_make_satisfied = max(best_we_can_make_satisfied, current_satisfied)
        
        # The answer is the sum of the solutions for the 2 parts.
        return already_satisfied + best_we_can_make_satisfied
__________________________________________________________________________________________________

__________________________________________________________________________________________________
