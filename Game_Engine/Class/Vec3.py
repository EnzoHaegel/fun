class Vec3:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def __add__(self, other):
        return Vec3(self.x + other.x, self.y + other.y, self.z + other.z)

    def __sub__(self, other):
        return Vec3(self.x - other.x, self.y - other.y, self.z - other.z)

    def __mul__(self, other):
        return Vec3(self.x * other.x, self.y * other.y, self.z * other.z)

    def __div__(self, other):
        return Vec3(self.x / other.x, self.y / other.y, self.z / other.z)

    def __str__(self):
        return "Vec3(%s, %s, %s)" % (self.x, self.y, self.z)

    def __repr__(self):
        return "Vec3(%s, %s, %s)" % (self.x, self.y, self.z)
