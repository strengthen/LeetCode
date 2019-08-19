__________________________________________________________________________________________________
sample 148 ms submission
class Solution:

    def __init__(self, radius: float, x_center: float, y_center: float):
        self.radius = radius
        self.x_center = x_center
        self.y_center = y_center
        

    def randPoint(self) -> List[float]:
        rho = math.sqrt(random.random())*self.radius
        theta = random.random()*math.pi*2
        return [self.x_center + rho*math.cos(theta), self.y_center + rho*math.sin(theta)]

# Your Solution object will be instantiated and called as such:
# obj = Solution(radius, x_center, y_center)
# param_1 = obj.randPoint()
__________________________________________________________________________________________________
sample 156 ms submission
from random import random
from math import pi, sin, cos, sqrt

class Solution:
    def __init__(self, radius: float, x_center: float, y_center: float):
        self.radius = radius
        self.x_center = x_center
        self.y_center = y_center

    def randPoint(self) -> List[float]:
        if self.radius is None or self.radius < 0:
            return []
        r = self.radius*sqrt(random())
        theta = 2*pi*random()
        x = self.x_center + r*cos(theta)
        y = self.y_center + r*sin(theta)
        return [x,y]
        
# Your Solution object will be instantiated and called as such:
# obj = Solution(radius, x_center, y_center)
# param_1 = obj.randPoint()
__________________________________________________________________________________________________
