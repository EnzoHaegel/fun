from Vector import Vector
from Casting import Casting
from Screen import Screen
import pygame
import pygame.gfxdraw as gfxdraw

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
        self.vectorsCasting = []
        self.texture = pygame.image.load("assets/stone.png")

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
    
    def castVectorsIn2D(self, casting: Casting):
        self.vectorsCasting = []
        for vector in self.vectors:
            self.vectorsCasting.append(casting.get2D(vector))
    
    def rotateX(self, angle):
        for vector in self.vectors:
            vector = vector.rotateX(angle)
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
        self.castVectorsIn2D(casting)
        for vector1 in self.vectors:
            for vector2 in self.vectors:
                if vector1 != vector2:
                    # if the 2 vectors tuple are not in the screen don't draw the line
                    if not casting.get2D(vector1).isVisible and not casting.get2D(vector1).isVisible:
                        continue
                    if vector1.x == vector2.x and vector1.y == vector2.y:
                        pygame.draw.line(screen, self.color, casting.get2D(vector1).getTuple(), casting.get2D(vector2).getTuple())
                    elif vector1.x == vector2.x and vector1.z == vector2.z:
                        pygame.draw.line(screen, self.color, casting.get2D(vector1).getTuple(), casting.get2D(vector2).getTuple())
                    elif vector1.y == vector2.y and vector1.z == vector2.z:
                        pygame.draw.line(screen, self.color, casting.get2D(vector1).getTuple(), casting.get2D(vector2).getTuple())
        if debug:
            self.debug(screen, casting)
        # add the texture to the six face of the cube
        self.drawFace(screen, casting, 0, 1, 2, 3)
        self.drawFace(screen, casting, 4, 5, 6, 7)
        self.drawFace(screen, casting, 0, 1, 5, 4)
        self.drawFace(screen, casting, 2, 3, 7, 6)
        self.drawFace(screen, casting, 1, 3, 7, 5)
        self.drawFace(screen, casting, 0, 2, 6, 4)
    
    def drawFace(self, screen: Screen, casting: Casting, vector1, vector2, vector3, vector4):
        """
        add the texture to the face of the cube
        """
        # fill the face with the texture between the 4 vectors with self.texture

        # get the 4 vectors in 2D
        vector1 = casting.get2D(self.vectors[vector1])
        vector2 = casting.get2D(self.vectors[vector2])
        vector3 = casting.get2D(self.vectors[vector3])
        vector4 = casting.get2D(self.vectors[vector4])
        # met l'image sur le quadrilatère formé par les 4 points
        # pygame.gfxdraw.textured_polygon(screen, (vector1.getTuple(), vector2.getTuple(), vector3.getTuple(), vector4.getTuple()), self.texture, 0, 0)

    
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
