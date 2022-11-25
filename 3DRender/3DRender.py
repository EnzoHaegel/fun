import pygame
from math import cos, sin, pi, sqrt
import math
import numpy as np
WHITE = (255, 255, 255)
WIDTH, HEIGHT = 1920, 1080


class Cube:
    def __init__(self, x, y, z, size):
        self.x = x + WIDTH / 2 - size / 2
        self.y = y + HEIGHT / 2 - size / 2
        self.z = z
        self.size = size
        self.points = self.initPoints()
        self.rotationX = 45
        self.rotationY = 0
        self.rotationZ = 0
        self.projection_matrix = np.matrix([
            [1, 0, 0],
            [0, 1, 0]
        ])
        self.projected_points = self.projection2D()

    def initPoints(self):
        points = []
        # append points as a np matrix
        points.append(np.matrix([self.x, self.y, self.z]))
        points.append(np.matrix([self.x + self.size, self.y, self.z]))
        points.append(
            np.matrix([self.x + self.size, self.y + self.size, self.z]))
        points.append(np.matrix([self.x, self.y + self.size, self.z]))
        points.append(np.matrix([self.x, self.y, self.z + self.size]))
        points.append(
            np.matrix([self.x + self.size, self.y, self.z + self.size]))
        points.append(
            np.matrix([self.x + self.size, self.y + self.size, self.z + self.size]))
        points.append(
            np.matrix([self.x, self.y + self.size, self.z + self.size]))
        return points
    
    def getRelativePoint(self, pointId):
        return self.points[pointId] - self.points[0]

    def rotateX(self, angle):
        self.rotationX += angle
        new_points = []
        rotation_matrixX = np.matrix([
            [1, 0, 0],
            [0, cos(self.rotationX), -sin(self.rotationX)],
            [0, sin(self.rotationX), cos(self.rotationX)]
        ])
        for point in self.points:
            new_points.append(np.dot(rotation_matrixX, point.reshape((3, 1))))
        self.points = new_points
    
    def rotateY(self, angle):
        self.rotationY += angle
        new_points = []
        rotation_matrixY = np.matrix([
            [cos(self.rotationY), 0, sin(self.rotationY)],
            [0, 1, 0],
            [-sin(self.rotationY), 0, cos(self.rotationY)]
        ])
        for point in self.points:
            new_points.append(np.dot(rotation_matrixY, point.reshape((3, 1))))
        self.points = new_points
    
    def rotateZ(self, angle):
        self.rotationZ += angle
        new_points = []
        rotation_matrixZ = np.matrix([
            [cos(self.rotationZ), -sin(self.rotationZ), 0],
            [sin(self.rotationZ), cos(self.rotationZ), 0],
            [0, 0, 1]
        ])
        for point in self.points:
            new_points.append(np.dot(rotation_matrixZ, point.reshape((3, 1))))
        self.points = new_points

    def projection2D(self, camera = np.matrix([100, 0, 0])):
        projected_points = []
        for point in self.points:
            # get relative point
            relative_point = point - camera
            # project point
            projected_point = np.dot(self.projection_matrix, relative_point.reshape((3, 1)))
            # append projected point
            projected_points.append(projected_point)
        return projected_points
    
    def draw(self, screen):
        # get projected points
        # self.rotateX(0)
        # self.rotateY(0)
        # self.rotateZ(0)
        self.projected_points = self.projection2D()
        # draw lines with projected points
        self.drawLineToPoints(screen, 0, 1)
        self.drawLineToPoints(screen, 1, 2)
        self.drawLineToPoints(screen, 2, 3)
        self.drawLineToPoints(screen, 3, 0)
        self.drawLineToPoints(screen, 4, 5)
        self.drawLineToPoints(screen, 5, 6)
        self.drawLineToPoints(screen, 6, 7)
        self.drawLineToPoints(screen, 7, 4)
        self.drawLineToPoints(screen, 0, 4)
        self.drawLineToPoints(screen, 1, 5)
        self.drawLineToPoints(screen, 2, 6)
        self.drawLineToPoints(screen, 3, 7)

    def debug(self):
        print(self.x, self.y, self.z, self.size)
        print(self.points)
        print(self.rotationX, self.rotationY, self.rotationZ)
        print(self.projection_matrix)
        print(self.projected_points)

    def drawLineToPoints(self, screen, pointId1, pointId2, color=WHITE):
        pygame.draw.line(screen, color, (self.projected_points[pointId1][0, 0], self.projected_points[pointId1][1, 0]), (self.projected_points[pointId2][0, 0], self.projected_points[pointId2][1, 0]))

    def __str__(self):
        # print cube info
        position = "Position: " + str(self.x) + ", " + str(self.y) + ", " + str(self.z)
        size = "Size: " + str(self.size)
        rotation = "Rotation: " + str(self.rotationX) + ", " + str(self.rotationY) + ", " + str(self.rotationZ)
        points = "Points: " + str(self.points)
        return position + "\n" + size + "\n" + rotation + "\n" + points + "\n"

def main():
    pygame.init()
    screen = pygame.display.set_mode((1920, 1080))
    pygame.display.set_caption("3D Render")
    clock = pygame.time.Clock()
    cube1 = Cube(0, 0, 0, 100)
    clock.tick(60)

    while True:
        clock.tick(60)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                return
        if pygame.key.get_pressed()[pygame.K_ESCAPE]:
            pygame.quit()
            return
        screen.fill((0, 0, 0))
        cube1.draw(screen)
        print(cube1)
        pygame.display.update()


if __name__ == "__main__":
    main()
