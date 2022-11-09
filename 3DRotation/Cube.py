from Vector import Vector
from Casting import Casting
from Screen import Screen
import pygame

class Cube:
    def __init__(self, x=0, y=0, z=0, size=1, color=(255, 255, 255)):
        self.x = x*size
        self.y = y*size
        self.z = z*size
        self.rotationX = 0
        self.rotationY = 0
        self.rotationZ = 0
        self.size = size
        self.vectors = self.getVectors()
        self.color = color

    def getVectors(self):
        return [
            Vector(self.x, self.y, self.z),
            Vector(self.x + self.size, self.y, self.z),
            Vector(self.x, self.y + self.size, self.z),
            Vector(self.x + self.size, self.y + self.size, self.z),
            Vector(self.x, self.y, self.z + self.size),
            Vector(self.x + self.size, self.y, self.z + self.size),
            Vector(self.x, self.y + self.size, self.z + self.size),
            Vector(self.x + self.size, self.y + self.size, self.z + self.size)
            ]
    
    def rotateX(self, angle):
        for vector in self.vectors:
            vector.rotateX(angle)
        self.rotationX += angle

    def rotateY(self, angle):
        for vector in self.vectors:
            vector.rotateY(angle)
        self.rotationY += angle
    
    def rotateZ(self, angle):
        for vector in self.vectors:
            vector.rotateZ(angle)
        self.rotationZ += angle
    
    def move(self, x, y, z):
        self.x += x
        self.y += y
        self.z += z
        self.vectors = self.getVectors()
    
    def moveX(self, x):
        self.x += x
        self.vectors = self.getVectors()
    
    def moveY(self, y):
        self.y += y
        self.vectors = self.getVectors()
    
    def moveZ(self, z):
        self.z += z
        self.vectors = self.getVectors()
    
    def draw(self, screen: Screen, casting: Casting, debug=False):
        for vector1 in self.vectors:
            for vector2 in self.vectors:
                if vector1 != vector2:
                    if vector1.x == vector2.x and vector1.y == vector2.y:
                        pygame.draw.line(screen, self.color, casting.get2D(vector1).getTuple(), casting.get2D(vector2).getTuple())
                    elif vector1.x == vector2.x and vector1.z == vector2.z:
                        pygame.draw.line(screen, self.color, casting.get2D(vector1).getTuple(), casting.get2D(vector2).getTuple())
                    elif vector1.y == vector2.y and vector1.z == vector2.z:
                        pygame.draw.line(screen, self.color, casting.get2D(vector1).getTuple(), casting.get2D(vector2).getTuple())
        if debug:
            self.debug(screen, casting)
    
    def debug(self, screen: Screen, casting: Casting):
        for vector in self.vectors:
            pygame.draw.circle(screen, (255, 0, 0), casting.get2D(vector).getTuple(), 5)

    def __add__(self, other):
        return Cube(self.x + other.x, self.y + other.y, self.z + other.z, self.size)

    def __sub__(self, other):
        return Cube(self.x - other.x, self.y - other.y, self.z - other.z, self.size)

    def __mul__(self, other):
        return Cube(self.x * other, self.y * other, self.z * other, self.size)

    def __div__(self, other):
        return Cube(self.x / other, self.y / other, self.z / other, self.size)

    def __str__(self):
        return "Cube(%s, %s, %s, %s)" % (self.x, self.y, self.z, self.size)

    def __repr__(self):
        return "Cube(%s, %s, %s, %s)" % (self.x, self.y, self.z, self.size)

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y and self.z == other.z and self.size == other.size

    def __ne__(self, other):
        return self.x != other.x or self.y != other.y or self.z != other.z or self.size != other.size

    def __neg__(self):
        return Cube(-self.x, -self.y, -self.z, self.size)

    def __pos__(self):
        return Cube(self.x, self.y, self.z, self.size)

    def __abs__(self):
        return Cube(abs(self.x), abs(self.y), abs(self.z), self.size)

    def __nonzero__(self):
        return self.x != 0 or self.y != 0 or self.z != 0 or self.size != 0

    def __len__(self):
        return 4

    def __getitem__(self, key):
        if key == 0:
            return self.x
        elif key == 1:
            return self.y
        elif key == 2:
            return self.z
        elif key == 3:
            return self.size
        else:
            raise IndexError
