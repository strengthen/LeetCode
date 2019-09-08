__________________________________________________________________________________________________
class Solution(object):
	def maximumSum(self, arr):
	
		# scan from left to right
		left_most = [0] * len(arr)
		for i in range(1, len(arr)):
			if arr[i-1] < 0:
				left_most[i] = max(0, left_most[i-1]+arr[i-1])
			else:
				left_most[i] = left_most[i-1] + arr[i-1]

		# scan from right to left
		right_most = [0] * len(arr)
		for i in range(len(arr)-2, -1, -1):
			if arr[i+1] < 0:
				right_most[i] = max(0, right_most[i+1] + arr[i+1])
			else:
				right_most[i] = right_most[i+1] + arr[i+1]

		res = sum(arr) # if all value is positive 
		# one pass check
		for i in range(len(arr)):
			if arr[i] > res: res = arr[i]
			if arr[i] < 0: # delete this value
				total = left_most[i] + right_most[i]
				if total != 0 and total > res: 
					res = total
		return res
__________________________________________________________________________________________________

__________________________________________________________________________________________________
