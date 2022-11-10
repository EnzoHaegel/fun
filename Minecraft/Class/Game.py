import pygame
from Class.Player import Player
from Class.Screen import Screen

class Game:
    def __init__(self, width, height, title):
        pygame.init()
        self.screen = Screen(width, height, title)
        self.clock = pygame.time.Clock()
        self.tick = 60
        # calc the speed to move 5.3 block per second
        self.player = Player(0, 64, 0, 5.3 / self.tick, self.screen, "Player")
        self.running = True
        self.mousePos = (0, 0)
        self.keys = pygame.key.get_pressed()
        self.isDebug = False

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
        pygame.quit()
    
    def draw(self):
        pygame.draw.circle(self.screen.screen, (255, 255, 255), (int(self.player.x), int(self.player.y)), 10)