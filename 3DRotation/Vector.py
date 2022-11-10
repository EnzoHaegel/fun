import math

class Vector:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z
        self.isVisible = True
    
    def getTuple(self):
        """Return a tuple representation of the vector."""
        return (self.x, self.y)
    
    def rotateX(self, angle):
        """Rotate the vector around the X axis by the given angle (in degree)."""
        # use the matrix of rotation
        # | 1 0 0 |
        # | 0 cos -sin |
        # | 0 sin cos |
        c = math.cos(angle)
        s = math.sin(angle)
        y = self.y * c - self.z * s
        z = self.y * s + self.z * c
        return Vector(self.x, y, z)
    
    def rotateY(self, angle):
        """Rotate the vector around the Y axis by the given angle (in radians)."""
        c = math.cos(angle)
        s = math.sin(angle)
        z = self.z * c - self.x * s
        x = self.z * s + self.x * c
        return Vector(x, self.y, z)

    def rotateZ(self, angle):
        """Rotate the vector around the Z axis by the given angle (in radians)."""
        c = math.cos(angle)
        s = math.sin(angle)
        x = self.x * c - self.y * s
        y = self.x * s + self.y * c
        return Vector(x, y, self.z)
    
    def setVisibility(self, isVisible):
        self.isVisible = isVisible

    def __add__(self, other):
        return Vector(self.x + other.x, self.y + other.y, self.z + other.z)

    def __sub__(self, other):
        return Vector(self.x - other.x, self.y - other.y, self.z - other.z)

    def __mul__(self, other):
        return Vector(self.x * other, self.y * other, self.z * other)

    def __div__(self, other):
        return Vector(self.x / other, self.y / other, self.z / other)

    def __str__(self):
        return "Vector(%s, %s, %s)" % (self.x, self.y, self.z)

    def __repr__(self):
        return "Vector(%s, %s, %s)" % (self.x, self.y, self.z)

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y and self.z == other.z

    def __ne__(self, other):
        return self.x != other.x or self.y != other.y or self.z != other.z

    def __neg__(self):
        return Vector(-self.x, -self.y, -self.z)

    def __pos__(self):
        return Vector(self.x, self.y, self.z)

    def __abs__(self):
        return Vector(abs(self.x), abs(self.y), abs(self.z))

    def __nonzero__(self):
        return self.x != 0 or self.y != 0 or self.z != 0

    def __len__(self):
        return 3

    def __getitem__(self, key):
        if key == 0:
            return self.x
        elif key == 1:
            return self.y
        elif key == 2:
            return self.z
        else:
            raise IndexError

    def __setitem__(self, key, value):
        if key == 0:
            self.x = value
        elif key == 1:
            self.y = value
        elif key == 2:
            self.z = value
        else:
            raise IndexError
