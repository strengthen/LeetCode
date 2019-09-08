__________________________________________________________________________________________________
sample 0 ms submission
class Solution {
public:
    int dayofweek(int d, int m, int y)  
    {  
        static int t[] = { 0, 3, 2, 5, 0, 3, 
                           5, 1, 4, 6, 2, 4 };  
        y -= m < 3;  
        return ( y + y / 4 - y / 100 +  
                 y / 400 + t[m - 1] + d) % 7;  
    }  
    string dayOfTheWeek(int day, int month, int year) 
    {
        vector<string> v{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        return v[dayofweek(day,month,year)];
    }
};
__________________________________________________________________________________________________
class Solution {
public:
    vector<string> days= {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    string dayOfTheWeek(int d, int m, int y, int c = 0) {
        if (m < 3) m += 12, y -= 1;
        c = y / 100, y = y % 100;
        int w = (c / 4 - 2 * c + y + y / 4 + 13 * (m + 1) / 5 + d - 1) % 7;
        return days[(w + 7) % 7];
    }
};

__________________________________________________________________________________________________
