__________________________________________________________________________________________________
class Solution:
    def smallestSufficientTeam(self, req_skills: List[str], people: List[List[str]]) -> List[int]:
        people = [(lst, i) for i, lst in enumerate(people)]
        people.sort(key=lambda x : len(x[0]), reverse=True)
        reqs = {skill : i for i, skill in enumerate(req_skills)}
        n = len(reqs)
        nstates = (1 << n)
        dp = [list(range(len(people))) for state in range(nstates)]
        dp[0] = []
        for lst, i in people:
            skill = 0
            for item in lst:
                idx = reqs.get(item, None)
                if idx is not None:
                    skill |= (1 << idx)
            for key, value in enumerate(dp):
                new = (skill | key)
                if new != key and len(dp[new]) > len(value) + 1:
                    dp[new] = value + [i]
        return sorted(dp[nstates - 1])
__________________________________________________________________________________________________

__________________________________________________________________________________________________
