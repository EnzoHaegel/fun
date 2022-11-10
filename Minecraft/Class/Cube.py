# A class for the cube
import json

class Cube:
    def __init__(self, x, y, z, id=0, size=1):
        self.x = x
        self.y = y
        self.z = z
        self.size = size
        self.id = 0
        self.name = self.fillName()
    
    def fillName(self):
        """
        search on the json Cubes.json the name of the cube with the id
        """
        try:
            with open(file_name, encoding="utf8") as json_file:
                data = json.load(json_file)
                for cube in data['cubes']:
                    if int(cube['id']) == self.id:
                        return cube['name']
        except:
            return 'Unknown'
        return 'Unknown'
    
    def get_json_file_content(self, file_name):
        """
        Get the content of a file in JSON.
        """
        try:
            with open(file_name, encoding="utf8") as json_file:
                return json.load(json_file)
        except:
            return ''

    def __str__(self):
        return "Cube: x=%d, y=%d, z=%d, size=%d" % (self.x, self.y, self.z, self.size)

    def __repr__(self):
        return "Cube(%d, %d, %d, %d)" % (self.x, self.y, self.z, self.size)

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y and self.z == other.z and self.size == other.size

    def __ne__(self, other):
        return not self.__eq__(other)

    def __hash__(self):
        return hash((self.x, self.y, self.z, self.size))

    def __contains__(self, other):
        return self.x <= other.x and self.y <= other.y and self.z <= other.z and self.x + self.size >= other.x + other.size and self.y + self.size >= other.y + other.size and self.z + self.size >= other.z + other.size

    def __iter__(self):
        return iter([self.x, self.y, self.z, self.size])

    def __getitem__(self, index):
        if index == 0:
            return self.x
        elif index == 1:
            return self.y
        elif index == 2:
            return self.z
        elif index == 3:
            return self.size
        else:
            raise IndexError("Index out of range")

    def __setitem__(self, index, value):
        if index == 0:
            self.x = value
        elif index == 1:
            self.y = value
        elif index == 2:
            self.z = value
        elif index == 3:
            self.size = value
        else:
            raise IndexError("Index out of range")

    def __len__(self):
        return 4

    def __add__(self, other):
        return Cube(self.x + other.x, self.y + other.y, self.z + other.z, self.size + other.size)

    def __sub__(self, other):
        return Cube(self.x - other.x, self.y - other.y, self.z - other.z, self.size - other.size)
    
    def __mul__(self, other):
        return Cube(self.x * other, self.y * other, self.z * other, self.size * other)
