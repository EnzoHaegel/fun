import pygame
from Cube import Cube
from Vector import Vector
from Casting import Casting
from Player import Player
from Screen import Screen

def main():
    cube1 = Cube(-0.5, -0.5, 1, 500)
    cube2 = Cube(-0.5, -1.5, 1, 500)
    screen = Screen(1920, 1080)
    clock = pygame.time.Clock()
    player = Player(0, 0, 0, 90, screen, "Player1")
    casting = Casting(screen.width, screen.height, 300, player)

    while True:
        clock.tick(60)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                return
        if pygame.key.get_pressed()[pygame.K_ESCAPE]:
            return
        player.run(pygame.mouse.get_pos(), pygame.key.get_pressed())
        cube1.draw(screen.screen, casting, True)
        cube2.draw(screen.screen, casting, True)
        # for vector in cube1.vectors:
        #     pygame.draw.circle(screen.screen, (255, 0, 0), casting.get2D(vector).getTuple(), 5)
        #rotate the cube
        cube1.move(10, 10, -10)
        screen.update()

if __name__ == "__main__":
    main()
