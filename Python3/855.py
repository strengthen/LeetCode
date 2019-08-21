__________________________________________________________________________________________________
sample 52 ms submission
class ExamRoom:

    def __init__(self, N: int):
        # intuition, need to track seats and pop the furthest slot up
        # need to be clear about distance calculation
        # [1,2,3,4,5], pick 3, distance is 2
        # [1,2,3,4], pick 2, distance is 1
        # formula is dist = (j-i)//2, pick = i+(j-i)//2
        #self.seats = [False]*N
        self.slots = [(1-N, 0, N-1)]
        self.total = N
        
    
    def seat(self) -> int:
        #if not self.slots: return -1
        n, beg, end = heapq.heappop(self.slots)
        res =beg+ (end-beg)//2
        if beg==0:
            res = beg
        elif end==self.total-1:
            res = end
        # we don't care about the special rule? since here we only have 0/N-1 taken
        # we need to care about special spacing rule when 0/N-1 leaves
        if res>beg: heapq.heappush(self.slots, (-((res-1-beg)//2), beg, res-1))
        if res<end: heapq.heappush(self.slots, (-((end-res-1)//2), res+1, end))
        #print(self.slots)
        return res
    
    def leave(self, p: int) -> None:
        i = 0
        beg, end = p, p
        while i<len(self.slots):
            n,b,e = self.slots[i]
            if b==p+1 or e==p-1:
                beg = min(beg, b) # find leftmost interval could be L, p+1, p
                end = max(end, e) # fint rightmost interval, could be R, p-1, p
                self.slots[-1], self.slots[i]=self.slots[i], self.slots[-1]
                self.slots.pop()
                #N-=1
            else:
                i+=1
        heapq.heapify(self.slots)
        if beg<=end:
            if beg==0 or end==self.total-1:heapq.heappush(self.slots, (-(end-beg), beg, end))
            else: heapq.heappush(self.slots, (-((end-beg)//2), beg, end))
        #print(self.slots)

# Your ExamRoom object will be instantiated and called as such:
# obj = ExamRoom(N)
# param_1 = obj.seat()
# obj.leave(p)
__________________________________________________________________________________________________
sample 13204 kb submission
class ExamRoom:

    def __init__(self, N):
        self.N = N
        self.students = []

    def seat(self):
        # Let's determine student, the position of the next
        # student to sit down.
        if not self.students:
            student = 0
        else:
            # Tenatively, dist is the distance to the closest student,
            # which is achieved by sitting in the position 'student'.
            # We start by considering the left-most seat.
            dist, student = self.students[0], 0
            for i, s in enumerate(self.students):
                if i:
                    prev = self.students[i-1]
                    # For each pair of adjacent students in positions (prev, s),
                    # d is the distance to the closest student;
                    # achieved at position prev + d.
                    d = (s - prev) // 2
                    if d > dist:
                        dist, student = d, prev + d

            # Considering the right-most seat.
            d = self.N - 1 - self.students[-1]
            if d > dist:
                student = self.N - 1

        # Add the student to our sorted list of positions.
        bisect.insort(self.students, student)
        return student

    def leave(self, p):
        #if p in self.students:
        self.students.remove(p)


# Your ExamRoom object will be instantiated and called as such:
# obj = ExamRoom(N)
# param_1 = obj.seat()
# obj.leave(p)
__________________________________________________________________________________________________
