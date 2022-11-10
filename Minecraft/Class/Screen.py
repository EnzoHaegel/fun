import pygame

class Screen:
    def __init__(self, width, height, title):
        self.width = width
        self.height = height
        self.title = title
        self.screen = pygame.display.set_mode((self.width, self.height))
        self.background = pygame.Surface(self.screen.get_size())
        self.background = self.background.convert()
        self.background.fill((0, 0, 0))
        self.screen.blit(self.background, (0, 0))
        pygame.display.set_caption(self.title)
        pygame.display.flip()
    
    def update(self):
        pygame.display.flip()
        self.screen.blit(self.background, (0, 0))
    
    def __getitem__(self, key):
        if key == 0:
            return self.width
        elif key == 1:
            return self.height
        else:
            raise IndexError