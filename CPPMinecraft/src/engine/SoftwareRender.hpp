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
#include "Cube.hpp"
#include "../Utils/Defines.h"
#include "../Utils/FPSCounter.h"
#include "../ResourceManager/ResourceHolder.h"
#include "../Game/World.hpp"
#include <SFML/Graphics.hpp>
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
        sf::Vector2i getSize();

        sf::RenderWindow m_window;
        const sf::RenderWindow& getWindow() const;
        
        Camera _camera;
        Projection _projection;

    protected:
    private:
        FPSCounter counter;
        sf::Texture _texture;
        sf::Sprite _sprite;
        sf::Uint8 *_pixels;
        bool _vsync;
        bool _debug;
        bool _fullscreen;
        int _width;
        int _length;

        std::vector<Cube> _cubes;

        sf::Text m_text;
        sf::Font m_font;

        World _world;
};

#endif /* !SOFTWARERENDER_HPP_ */
