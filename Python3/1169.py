__________________________________________________________________________________________________
sample 68 ms submission
class Solution:
    def invalidTransactions(self, transactions: List[str]) -> List[str]:        
        by_name = collections.defaultdict(list)
        invalid = []
        for transaction in transactions:
            name, time, _, city = transaction.split(',')
            time = int(time)
            by_name[name].append((time, city))
        for transaction in transactions:
            name, time, amount, city = transaction.split(',')
            time = int(time)
            amount = int(amount)
            if amount >= 1000:
                invalid.append(transaction)
                continue
            if name not in by_name:
                continue
            if all(city == other_city or abs(time - other_time) > 60
                   for other_time, other_city in by_name[name]):
                continue
            invalid.append(transaction)
        return invalid
__________________________________________________________________________________________________
sample 72 ms submission
class Solution:
    def invalidTransactions(self, transactions: List[str]) -> List[str]:
        dicti, ans = collections.defaultdict(list), set()
        for i, t in enumerate(transactions):
            name, time, amount, city = t.split(",")
            if int(amount) > 1000:
                ans.add(i)
            dicti[name].append([int(time), city, i])
        for d in dicti:
            dicti[d].sort()
            pq = collections.deque()
            for t, c, i in dicti[d]:
                while pq and pq[0][0] < t - 60:
                    pq.popleft()
                for t2, c2, i2 in pq:
                    if c != c2:
                        ans.add(i2)
                        ans.add(i)
                pq.append([t, c, i])
        return [transactions[a] for a in ans]
__________________________________________________________________________________________________
