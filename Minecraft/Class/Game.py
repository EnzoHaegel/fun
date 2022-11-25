import pygame
from Class.Player import Player
from Class.Screen import Screen
from Class.Camera3D import Camera3D
from Class.Cube import Cube

class Game:
    def __init__(self, width, height):
        pygame.init()
        self.screen = Screen(width, height)
        self.clock = pygame.time.Clock()
        self.tick = 60
        # calc the speed to move 5.3 block per second
        self.player = Player(0, 64, 0, 5.3 / self.tick, self.screen, "Player")
        self.running = True
        self.mousePos = (0, 0)
        self.keys = pygame.key.get_pressed()
        self.isDebug = False
        self.objects = []
        self.addCubeToObjects()
        self.camera = Camera3D(self.screen, self.player, self.objects)

    def run(self):
        while self.running:
            self.clock.tick(60)
            self.mousePos = pygame.mouse.get_pos()
            self.keys = pygame.key.get_pressed()
            self.player.run(self.mousePos, self.keys, self.isDebug)
            self.screen.update()
            self.draw()
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    self.running = False
            if self.keys[pygame.K_ESCAPE]:
                self.running = False
            if event.type == pygame.KEYUP and event.key == pygame.K_F3:
                self.isDebug = not self.isDebug
            self.camera.run(self.objects, self.player.getPos(), self.player.getAngle(), self.screen)
        pygame.quit()
    
    def addCubeToObjects(self):
        for x in range(-10, 10):
            for y in range(-10, 10):
                for z in range(-10, 10):
                    self.objects.append(Cube(x, y, z, 0))
    
    def draw(self):
        pygame.draw.circle(self.screen.screen, (255, 255, 255), (int(self.player.x), int(self.player.y)), 10)