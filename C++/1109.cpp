__________________________________________________________________________________________________
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> change(n + 1, 0);

        for (vector<int> &booking : bookings) {
            booking[0]--;
            booking[1]--;
            change[booking[0]] += booking[2];
            change[booking[1] + 1] -= booking[2];
        }

        vector<int> seats(n, 0);

        for (int i = 0; i < n; i++)
            seats[i] = (i == 0 ? 0 : seats[i - 1]) + change[i];
        
        return seats;
    }
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
