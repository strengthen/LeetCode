__________________________________________________________________________________________________
class Solution:
    def mostVisitedPattern(self, username: List[str], timestamp: List[int], website: List[str]) -> List[str]:
        user_to_visit = dict()
        for i, user in enumerate(username):
            if user not in user_to_visit:
                user_to_visit[user] = list()
            user_to_visit[user].append((timestamp[i], website[i]))

        user_to_visit_ordered = dict()
        for k, v in user_to_visit.items():
            user_to_visit_ordered[k] = sorted(v, key=lambda x: x[0])

        three_sequence = dict()
        for k, v in user_to_visit_ordered.items():
            user_three_sequence = set()
            if len(v) > 2:
                dd = len(v)
                for i in range(dd):
                    for j in range(i + 1, dd):
                        for k in range(j + 1, dd):
                            user_three_sequence.add((v[i][1], v[j][1], v[k][1]))
            for key in user_three_sequence:
                if key not in three_sequence:
                    three_sequence[key] = 1
                else:
                    three_sequence[key] += 1

        ans = sorted(three_sequence.items(), key=lambda x: (-x[1], x[0][0], x[0][1], x[0][2]))[0]
        return list(ans[0])

__________________________________________________________________________________________________

__________________________________________________________________________________________________
