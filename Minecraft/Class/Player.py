# player for 3D minecraft
from Class.Vector import Vector
from Class.Cube import Cube
import math
import pygame

class Player:
    def __init__(self, x, y, z, speed, screen, name):
        self.x = x
        self.y = y
        self.z = z
        self.speed = speed
        self.screen = screen
        self.name = name
        self.angleY = 0
        self.angleX = 0
        self.angleSpeed = 0.5
        self.cube = Cube(self.x, self.y, self.z, 1)
    
    def run(self, mousePos, keys, debug=True):
        self.angleX = self.angleX + (mousePos[0] - self.screen.width/2) * self.angleSpeed
        self.angleY = self.angleY + (mousePos[1] - self.screen.height/2) * self.angleSpeed
        if self.angleX > 360:
            self.angleX = self.angleX - 360
        elif self.angleX < 0:
            self.angleX = self.angleX + 360
        if self.angleY > 90:
            self.angleY = 90
        elif self.angleY < -90:
            self.angleY = -90
        if keys[pygame.K_z]:
            self.x += math.cos(math.radians(self.angleX)) * self.speed
            self.z += math.sin(math.radians(self.angleX)) * self.speed
        if keys[pygame.K_s]:
            self.x -= math.cos(math.radians(self.angleX)) * self.speed
            self.z -= math.sin(math.radians(self.angleX)) * self.speed
        if keys[pygame.K_q]:
            self.x += math.cos(math.radians(self.angleX+ 90)) * self.speed
            self.z += math.sin(math.radians(self.angleX+ 90)) * self.speed
        if keys[pygame.K_d]:
            self.x += math.cos(math.radians(self.angleX- 90)) * self.speed
            self.z += math.sin(math.radians(self.angleX- 90)) * self.speed
        if keys[pygame.K_SPACE]:
            self.y += self.speed
        if keys[pygame.K_LSHIFT]:
            self.y -= self.speed
        if keys[pygame.K_h]:
            self.angleX = 0
            self.angleY = 0
        if keys[pygame.K_i]:
            self.angleX = 0
            self.angleY = 0
            self.x = 0
            self.y = 0
            self.z = 0
        pygame.mouse.set_pos(self.screen.width/2, self.screen.height/2)
        if debug:
            self.debug()
    
    def debug(self):
        """
        print every informations on the screen using pygame
        """
        pygame.init()
        font = pygame.font.SysFont("Arial", 20)
        text = font.render("Player: " + self.name, True, (255, 255, 255))
        line2 = font.render("Pos: " + str(self.x) + ", " + str(self.y) + ", " + str(self.z), True, (255, 255, 255))
        line3 = font.render("Angle: " + str(self.angleX) + ", " + str(self.angleY), True, (255, 255, 255))
        line4 = font.render("===", True, (255, 255, 255))
        self.screen.screen.blit(text, (0, 0))
        self.screen.screen.blit(line2, (0, 20))
        self.screen.screen.blit(line3, (0, 40))
        self.screen.screen.blit(line4, (0, 60))
        pygame.display.flip()

    
    def getPos(self):
        return Vector(self.x, self.y, self.z)
    
    def getAngle(self):
        return Vector(self.angleX, self.angleY, self.angleZ)

    def __str__(self):
        return "===\nPlayer: " + self.name + "\n\tPos: " + str(self.x) + ", " + str(self.y) + ", " + str(self.z) + "\n\tAngle: " + str(self.angleX) + ", " + str(self.angleY) + "\n==="
