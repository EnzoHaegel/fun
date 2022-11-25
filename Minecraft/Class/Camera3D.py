import pygame
from Class.Screen import Screen
from Class.Vector import Vector
from Class.Cube import Cube
import math

class Camera3D:
    def __init__(self, position: Vector, rotation: tuple, screen: Screen):
        self.position = position
        self.rotation = rotation
        self.screen = screen
    
    def update(self, position: Vector, rotation: tuple, screen: Screen):
        self.position = position
        self.rotation = rotation
        self.screen = screen
    
    def renderObject(self, obj, screen):
        """
        Render a 3D object on the screen.
        """
        # check if object is a cube
        if isinstance(obj, Cube):
            # the distance between camera and the cube at 0 the cube take the full height of the camera
            distance = self.getDistance(obj.getPosition())
            # the size of the cube on the screen
            size = 100 / distance
            # the 2D points of the cube
            points = []
            # get the 2D points of the cube
            objPoints = obj.getPoints()
            for point in objPoints:
                points.append(self.get2DPoint(point))
            # draw the cube
            pygame.draw.polygon(screen, (255, 255, 255), points)
            
    
    def get2DPoint(self, point: Vector):
        """
        Get a 2D point from a 3D point.
        """
        # get the angle between the camera and the point
        angle = self.getAngle(point)
        # get the distance between the camera and the point
        distance = self.getDistance(point)
        # get the 2D point
        x = math.tan(angle) * distance
        y = math.tan(angle) * distance
        return (x, y)
    
    def getAngle(self, point: Vector):
        """
        Get the angle between the camera and a point.
        """
        # get the angle between the camera and the point
        angle = math.atan2(point.y - self.position.y, point.x - self.position.x)
        # get the angle between the camera and the point
        angle = math.atan2(point.z - self.position.z, angle)
        # return the angle
        return angle
    
    def getDistance(self, point: Vector):
        """
        Get the distance between the camera and a point.
        """
        # get the distance between the camera and the point
        distance = math.sqrt((point.x - self.position.x) ** 2 + (point.y - self.position.y) ** 2 + (point.z - self.position.z) ** 2)
        # return the distance
        return distance
    
    def render(self, objects):
        """
        Render all objects on the screen.
        """
        # render all objects
        for obj in objects:
            self.renderObject(obj, self.screen.screen)
    
    def run(self, objects, position: Vector, rotation: tuple, screen: Screen):
        """
        Update the camera and render all objects on the screen.
        """
        self.update(position, rotation, screen)
        self.render(objects)
