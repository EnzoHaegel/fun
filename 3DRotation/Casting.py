from Vector import Vector
from Player import Player

class Casting:
    """
    Casting class
    get the position of a point on the screen with Z axis to render 3D
    """
    def __init__(self, width, height, fov, player: Player):
        self.width = width
        self.height = height
        self.fov = fov
        self.center = Vector(width / 2, height / 2, 0)
        self.scale = (width + height) / 8
        self.player = player

    def get2D(self, vector: Vector):
        """
        calculate the position of a 3D Vector on the screen
        """
        # use the player position with self.player.getPos()
        # use the player angle with self.player.getAngle()
        print(self.player.getPos())
        vector = vector - self.player.getPos()
        vector = vector.rotateX(self.player.getAngle()[0])
        vector = vector.rotateY(self.player.getAngle()[1])

        # calculate the position on the screen
        x = self.center.x + vector.x * self.scale / (vector.z + self.fov)
        y = self.center.y + vector.y * self.scale / (vector.z + self.fov)
        # if x, y is not in the screen, return the closest point on the screen
        if x < 0:
            x = 0
        elif x > self.width:
            x = self.width
        if y < 0:
            y = 0
        elif y > self.height:
            y = self.height
        return Vector(x, y, 0)
