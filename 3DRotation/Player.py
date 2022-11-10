import pygame
import math
from Vector import Vector

class Player:
    def __init__(self, x, y, z, fov, screen, name="Player"):
        self.x = x
        self.y = y
        self.z = z
        self.angleX = 0 # rotation around the x axis
        self.angleY = 0 # rotation around the y axis
        self.fov = fov
        self.screen = screen
        self.speed = 8
        self.rotationSpeed = 0.01

    def move(self, direction):
        if direction == "forward":
            self.x += math.cos(self.angleY) * self.speed
            self.y += math.sin(self.angleY) * self.speed
        elif direction == "backward":
            self.x -= math.cos(self.angleY) * self.speed
            self.y -= math.sin(self.angleY) * self.speed
        elif direction == "left":
            self.x += math.cos(self.angleY + math.pi/2) * self.speed
            self.y += math.sin(self.angleY + math.pi/2) * self.speed
        elif direction == "right":
            self.x += math.cos(self.angleY - math.pi/2) * self.speed
            self.y += math.sin(self.angleY - math.pi/2) * self.speed
        elif direction == "up":
            self.z += self.speed
        elif direction == "down":
            self.z -= self.speed
    
    def rotate(self, mousePos):
        self.angleY += (mousePos[0] - self.screen[0]/2) * self.rotationSpeed
        self.angleX += (mousePos[1] - self.screen[1]/2) * self.rotationSpeed
        pygame.mouse.set_pos(self.screen[0]/2, self.screen[1]/2)
    
    def run(self, mousePos, keys):
        self.rotate(mousePos)
        if keys[pygame.K_w]:
            self.move("forward")
        if keys[pygame.K_s]:
            self.move("backward")
        if keys[pygame.K_a]:
            self.move("left")
        if keys[pygame.K_d]:
            self.move("right")
        if keys[pygame.K_SPACE]:
            self.move("up")
        if keys[pygame.K_LSHIFT]:
            self.move("down")
        print("Pos: " + str(self.x) + ", " + str(self.y) + ", " + str(self.z))
        print("Angle: " + str(self.angleX) + ", " + str(self.angleY))
    
    def getPos(self):
        return Vector(self.x, self.y, self.z)
    
    def getAngle(self):
        return (self.angleX, self.angleY)
    
    def __str__(self):
        return "Player(x:%s, y:%s, z:%s, angleX%s, angleY%s)" % (self.x, self.y, self.z, self.angleX, self.angleY)
    
    def __repr__(self):
        return "Player(x:%s, y:%s, z:%s, angleX%s, angleY%s)" % (self.x, self.y, self.z, self.angleX, self.angleY)
    
    def __eq__(self, other):
        return self.x == other.x and self.y == other.y and self.z == other.z and self.angleX == other.angleX and self.angleY == other.angleY
    
    def __ne__(self, other):
        return not self.__eq__(other)
    
    def __lt__(self, other):
        return self.x < other.x and self.y < other.y and self.z < other.z and self.angleX < other.angleX and self.angleY < other.angleY
    
    def __le__(self, other):
        return self.x <= other.x and self.y <= other.y and self.z <= other.z and self.angleX <= other.angleX and self.angleY <= other.angleY
    
    def __gt__(self, other):
        return self.x > other.x and self.y > other.y and self.z > other.z and self.angleX > other.angleX and self.angleY > other.angleY
    
    def __ge__(self, other):
        return self.x >= other.x and self.y >= other.y and self.z >= other.z and self.angleX >= other.angleX and self.angleY >= other.angleY
    
    def __add__(self, other):
        return Player(self.x + other.x, self.y + other.y, self.z + other.z, self.angleX + other.angleX, self.angleY + other.angleY)
    
    def __sub__(self, other):
        return Player(self.x - other.x, self.y - other.y, self.z - other.z, self.angleX - other.angleX, self.angleY - other.angleY)
    
    def __mul__(self, other):
        return Player(self.x * other.x, self.y * other.y, self.z * other.z, self.angleX * other.angleX, self.angleY * other.angleY)
    
    def __truediv__(self, other):
        return Player(self.x / other.x, self.y / other.y, self.z / other.z, self.angleX / other.angleX, self.angleY / other.angleY)
    
    def __floordiv__(self, other):
        return Player(self.x // other.x, self.y // other.y, self.z // other.z, self.angleX // other.angleX, self.angleY // other.angleY)