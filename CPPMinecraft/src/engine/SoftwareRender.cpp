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
    m_window.setPosition({m_window.getPosition().x, 0});
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
        m_window.display();
    }
}
