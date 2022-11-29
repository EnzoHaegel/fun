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
#include <iostream>

class SoftwareRender {
    public:
        SoftwareRender();
        ~SoftwareRender();
        void run();
        void draw();
        void create_objects();
        void handleEvent();
        void debug();
        void getSize();

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
        bool _debug;
        bool _fullscreen;
        int _width;
        int _length;
};

#endif /* !SOFTWARERENDER_HPP_ */
