__________________________________________________________________________________________________
sample 36 ms submission
import datetime
import calendar
class Solution:
    def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
        tmp = datetime.date(year, month, day)
        return calendar.day_name[tmp.weekday()]
__________________________________________________________________________________________________
import datetime
class Solution:
    def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
        d = datetime.datetime(year=year, month=month, day=day)
        res = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"]
        return res[d.isoweekday() % 7]
__________________________________________________________________________________________________

