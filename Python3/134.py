__________________________________________________________________________________________________
sample 48 ms submission
class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        minor = 0
        current_gas = 0
        start = 0
        
        for i in range(len(gas)):
            current_gas += gas[i] - cost[i]
            if current_gas < 0:
                minor += current_gas
                current_gas = 0
                start = i + 1
        
        if current_gas + minor >= 0:
            return start
        return -1        
__________________________________________________________________________________________________
sample 13760 kb submission
#
# @lc app=leetcode id=134 lang=python3
#
# [134] Gas Station
#
class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        start = rest = overall = 0
        for i in range(len(gas)):
            rest += gas[i] - cost[i]
            overall += gas[i] - cost[i]
            if rest < 0:
                rest, start = 0, i + 1
        return start if overall >=0 else -1       
__________________________________________________________________________________________________
