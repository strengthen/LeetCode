__________________________________________________________________________________________________
class Solution {
public:
    vector<vector<int>> dirs{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    void cleanRoom(Robot& robot) {
        unordered_set<string> visited;
        helper(robot, 0, 0, 0, visited);
    }
    void helper(Robot& robot, int x, int y, int dir, unordered_set<string>& visited) {
        robot.clean();
        visited.insert(to_string(x) + "-" + to_string(y));
        for (int i = 0; i < 4; ++i) {
            int cur = (i + dir) % 4, newX = x + dirs[cur][0], newY = y + dirs[cur][1];
            if (!visited.count(to_string(newX) + "-" + to_string(newY)) && robot.move()) {
                helper(robot, newX, newY, cur, visited);
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnLeft();
                robot.turnLeft();
            }
            robot.turnRight();
        }
    }
};
__________________________________________________________________________________________________

__________________________________________________________________________________________________
