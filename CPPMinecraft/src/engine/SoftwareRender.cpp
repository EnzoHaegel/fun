/*
** EPITECH PROJECT, 2022
** fun
** File description:
** SoftwareRender
*/

#include "SoftwareRender.hpp"

SoftwareRender::SoftwareRender() : m_window({LENGTH, HEIGHT}, "Minecraft")
{
    m_window.setFramerateLimit(FPS);
    m_window.setMouseCursorVisible(false);
    _vsync = false;
    _debug = false;
    _fullscreen = true;
    // get width and length of the window
    _length = m_window.getSize().x;
    _width = m_window.getSize().y;
    m_window.setPosition({m_window.getPosition().x, 0});
    // window full screen
    m_window.create(sf::VideoMode::getDesktopMode(), "Minecraft", sf::Style::Fullscreen);
}

SoftwareRender::~SoftwareRender()
{
}

void SoftwareRender::run()
{
    constexpr unsigned TPS = M_TPS;
    const sf::Time timePerUpdate = sf::seconds(1.0f / float(TPS));
    unsigned ticks = 0;

    sf::Clock timer;
    auto lastTime = sf::Time::Zero;
    auto lag = sf::Time::Zero;

    while (m_window.isOpen()) {
        // Get Size
        getSize();

        //Get times
        auto time = timer.getElapsedTime();
        auto elapsed = time - lastTime;
        lastTime = time;
        lag += elapsed;

        //Real time update
        // state.handleInput();
        // state.update(elapsed);
        counter.update();

        //Fixed time update
        while (lag >= timePerUpdate) {
            ticks++;
            lag -= timePerUpdate;
            // state.fixedUpdate(elapsed);
        }

        m_window.clear();
        m_window.setVerticalSyncEnabled(_vsync);

        //Handle window events
        handleEvent();

        // debug
        debug();

        // draw a white square
        draw();

        m_window.display();
    }
}

void SoftwareRender::handleEvent()
{
    sf::Event event;

    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                m_window.close();
            }
            if (event.key.code == sf::Keyboard::F1) {
                _vsync = !_vsync;
                std::cout << "Vsync: " << _vsync << std::endl;
            }
            if (event.key.code == sf::Keyboard::F3) {
                _debug = !_debug;
            }
            // f11 full screen
            if (event.key.code == sf::Keyboard::F11) {
                _fullscreen = !_fullscreen;
                if (_fullscreen) {
                    m_window.create(sf::VideoMode::getDesktopMode(), "Minecraft", sf::Style::Fullscreen);
                } else {
                    m_window.create(sf::VideoMode(_length, _width), "Minecraft");
                }
            }
        }
    }
}

void SoftwareRender::debug()
{
    if (_debug) {
        counter.draw(m_window, _vsync);
    }
}

void SoftwareRender::draw()
{
    // draw a white line from the top left corner to the bottom right
    sf::Vertex line[] = 
    {
        sf::Vertex(sf::Vector2f(0, 0)),
        sf::Vertex(sf::Vector2f(_length, _width))
    };

    m_window.draw(line, 20, sf::Lines);
}

void SoftwareRender::getSize()
{
    _length = m_window.getSize().x;
    _width = m_window.getSize().y;
}