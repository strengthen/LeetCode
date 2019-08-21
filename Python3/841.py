__________________________________________________________________________________________________
sample 60 ms submission
class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        q, seen = [0], {0}
        for node in q:
            for nei in rooms[node]:
                if nei not in seen:
                    q.append(nei)
                    seen.add(nei)
        return len(seen) == len(rooms)
__________________________________________________________________________________________________
sample 13296 kb submission
class Solution:
    def canVisitAllRooms(self, rooms: List[List[int]]) -> bool:
        st = [0]
        entered = set([0])
        while st:
            c = st.pop(-1)
            for k in rooms[c]:
                if k not in entered:
                    st.append(k)
                    entered.add(k)
        return len(entered) == len(rooms)
__________________________________________________________________________________________________
