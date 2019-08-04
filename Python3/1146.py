__________________________________________________________________________________________________
Runtime: 952 ms
Memory Usage: 37.2 MB
from collections import defaultdict
from copy import deepcopy

class SnapshotArray:

    def __init__(self, length: int):
        self.arr = defaultdict(int)
        self.snaps = list()

    def set(self, index: int, val: int) -> None:
        self.arr[index] = val

    def snap(self) -> int:
        self.snaps.append(deepcopy(self.arr))
        return len(self.snaps) - 1

    def get(self, index: int, snap_id: int) -> int:
        return self.snaps[snap_id].get(index, 0)


# Your SnapshotArray object will be instantiated and called as such:
# obj = SnapshotArray(length)
# obj.set(index,val)
# param_2 = obj.snap()
# param_3 = obj.get(index,snap_id)
__________________________________________________________________________________________________

__________________________________________________________________________________________________
