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
    player = Player(0, 0, 0, 120, screen, "Player1")
    casting = Casting(screen.width, screen.height, 300, player)

    while True:
        clock.tick(60)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                return
        if pygame.key.get_pressed()[pygame.K_ESCAPE]:
            return
        player.run(pygame.mouse.get_pos(), pygame.key.get_pressed())
        cube1.draw(screen.screen, casting)
        cube2.draw(screen.screen, casting)
        # for vector in cube1.vectors:
        #     pygame.draw.circle(screen.screen, (255, 0, 0), casting.get2D(vector).getTuple(), 5)
        #rotate the cube
        cube1.move(10, 10, -10)
        cube2.rotateX(10)
        # put the position x y z of the player in the top left corner use the font in assets/fonts/Stone_Head.ttf
        # initialize the font
        pygame.init()
        pygame.font.init()
        font = pygame.font.Font("assets/fonts/Stone_Head.ttf", 30)
        # render the text
        text = font.render("x: %s y: %s z: %s" % (player.x, player.y, player.z), True, (255, 255, 255))
        # put the text on the screen
        screen.screen.blit(text, (0, 0))
        screen.update()

if __name__ == "__main__":
    main()
