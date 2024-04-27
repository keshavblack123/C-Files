import math

class Vector2D:
    def __init__(self, x=0.0, y=0.0):
        self.x = x
        self.y = y
    
    def getX(self):
        return self.x
    
    def setX(self, x):
        self.x = x
    
    def getY(self):
        return self.y
    
    def setY(self, y):
        self.y = y
    
    def getMagnitude(self):
        return math.sqrt(self.x * self.x + self.y * self.y)


v = Vector2D(3.0, 4.0)
print(v.getMagnitude())
