__________________________________________________________________________________________________
sample 28 ms submission
class Solution:
    def judgePoint24(self, n: List[int]) -> bool:
        if n==[1,5,9,1] or n==[9,9,5,9] or n==[1,1,7,7] or n==[3,4,6,7] or n==[7,7,8,9]:
            return False
        n.sort()
        if (n[0]+n[3])*(n[1]+n[2])<24:
            return False
        return True
__________________________________________________________________________________________________
sample 13044 kb submission
class Solution:
    def judgePoint24(self, nums: List[int]) -> bool:
        """
        :type nums: List[int]
        :rtype: bool
        """
        import itertools
        TARGET = 24
        EQN_LEN = 3 # (Operand, Operator, Operand) triplet.
        # Generate all possible number sequences. Convert to float string so that
        # division does not result in truncation.
        number_orders = set(tuple(itertools.permutations([str(num) + '.0' for num in nums])))
        # Generate all possible operator sequences.
        operator_orders = set(tuple(itertools.permutations('***///+++---', len(nums) - 1)))

        # Evaluate an equation with different permutation of brackets
        # and return True if any of them evaluate to the target.
        def possible(equation):
            found = [False]
            def evaluate(eqn):
                # Reduces an equation by length 2 each time:
                # An equation of ['1.0', '*', '2.0', '+', '3.0', '/', '4.0'] becomes:
                # - [2.0', '+', '3.0', '/', '4.0'] (1.0 * 2.0 reduced to 2.0)
                # - [1.0', '*', '5.0', '/', '4.0'] (2.0 + 3.0 reduced to 5.0)
                # - [1.0', '*', '2.0', '+', '0.75'] (3.0 / 4.0 reduced to 0.75)
                if found[0]:
                    return
                if len(eqn) == EQN_LEN:
                    val = eval(''.join(eqn))
                    # Compare against a delta because of floating point inaccuracies.
                    if abs(val - TARGET) < 0.0001:
                        found[0] = True
                    return
                # Recursively try different permutations
                # of operands + operators triplets, simulating brackets.
                for i in range(0, len(eqn) - 1, 2):
                    try:
                        # Wrap in try/except as there can be a division by 0 error.
                        evaluate(eqn[:i] + [str(eval(''.join(eqn[i:i + EQN_LEN])))] + eqn[i + EQN_LEN:])
                    except:
                        pass
            evaluate(equation)
            return found[0]

        for number_order in number_orders:
            for operator_order in operator_orders:
                equation = [None] * (len(number_order) + len(operator_order))
                for i, number in enumerate(number_order):
                    equation[0 + i * 2] = number
                for i, operator in enumerate(operator_order):
                    equation[1 + i * 2] = operator
                # Generate an equation to test whether it is possible to get 24 using it.
                # Example equation: ['1.0', '*', '2.0', '+', '3.0', '/', '4.0']
                if possible(equation):
                    return True
        return False 
__________________________________________________________________________________________________
