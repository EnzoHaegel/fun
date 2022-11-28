/*
** EPITECH PROJECT, 2022
** fun
** File description:
** SoftwareRender
*/

#ifndef SOFTWARERENDER_HPP_
#define SOFTWARERENDER_HPP_

#include "Projection.hpp"
#include "Camera.hpp"
#include "../Utils/Defines.h"
#include <SFML/Graphics.hpp>
#include "../Utils/FPSCounter.h"

// class SoftwareRender:
//     def __init__(self):
//         pg.init()
//         self.RES = self.WIDTH, self.HEIGHT = 1920, 1080
//         self.H_WIDTH, self.H_HEIGHT = self.WIDTH // 2, self.HEIGHT // 2
//         self.FPS = 60
//         self.screen = pg.display.set_mode(self.RES)
//         self.clock = pg.time.Clock()
//         self.create_objects()

//     def create_objects(self):
//         self.camera = Camera(self, [5, 5, -5])
//         self.projection = Projection(self)
//         self.object = []
//         for i in range(15):
//             for j in range(15):
//                 self.object.append(Cube(self, Vec3(i, j, 0)))

//     def draw(self):
//         self.screen.fill(pg.Color('darkslategray'))
//         for obj in self.object:
//             obj.draw()

//     def run(self):
//         pg.mouse.set_pos(self.WIDTH / 2, self.HEIGHT / 2)
//         self.clock.tick(self.FPS)
//         pg.mouse.set_visible(False)
//         while True:
//             self.draw()
//             self.camera.control()
//             for event in pg.event.get():
//                 if event.type == pg.QUIT or (event.type == pg.KEYDOWN and event.key == pg.K_ESCAPE):
//                     pg.quit()
//                     return
//             [exit() for i in pg.event.get() if i.type == pg.QUIT]
//             pg.display.set_caption(str(self.clock.get_fps()))
//             pg.display.flip()

// change this python class to hpp class with SFML


class SoftwareRender {
    public:
        SoftwareRender();
        ~SoftwareRender();
        void run();
        void draw();
        void create_objects();

    protected:
    private:
        FPSCounter counter;
        sf::RenderWindow m_window;
        sf::Texture _texture;
        sf::Sprite _sprite;
        sf::Uint8 *_pixels;
        Camera _camera;
        Projection _projection;
        bool _vsync;
};

#endif /* !SOFTWARERENDER_HPP_ */
