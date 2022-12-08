/*
** EPITECH PROJECT, 2022
** fun
** File description:
** SoftwareRender
*/

#include "SoftwareRender.hpp"

SoftwareRender::SoftwareRender() :
    m_window({LENGTH, HEIGHT}, "Minecraft"),
    _camera(Camera(sf::Vector2i(LENGTH, HEIGHT), std::vector<float>{5, 5, -5})),
    _projection(Projection(_camera._near, _camera._far, _camera._hfov, _camera._vfov, this->getSize())),
    _world(World(this->m_window, _camera.cameraMatrix(), _projection._projectionMatrix, _projection._viewMatrix))
{
    m_window.setFramerateLimit(FPS);
    m_window.setMouseCursorVisible(false);
    _vsync = false;
    _debug = false;
    _fullscreen = true;
    m_window.setPosition({m_window.getPosition().x, 0});
    // window full screen
    m_window.create(sf::VideoMode::getDesktopMode(), "Minecraft", sf::Style::Fullscreen);
    // get width and length of the window
    _length = m_window.getSize().x;
    _width = m_window.getSize().y;

    // put mouse in the middle of the screen
    sf::Mouse::setPosition(sf::Vector2i(_length / 2, _width / 2), m_window);

    // create Cube objects
    create_objects();

    // text for debug
    m_text.move(0, 20);
    m_text.setOutlineColor(sf::Color::Black);
    m_text.setFillColor({255, 255, 255});
    m_text.setOutlineThickness(2);
    m_text.setFont(ResourceHolder::get().fonts.get("arial"));
    m_text.setCharacterSize(15);
}

SoftwareRender::~SoftwareRender()
{
}

void SoftwareRender::create_objects()
{
    // _cubes.push_back(Cube(this->m_window, sf::Vector3i{4, 4, 4}, _camera.cameraMatrix(), _projection._projectionMatrix, _projection._viewMatrix));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            _cubes.push_back(Cube(this->m_window, sf::Vector3i{i, j, 4}, _camera.cameraMatrix(), _projection._projectionMatrix, _projection._viewMatrix));
        }
    }
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

        // draw cubes
        // for (auto &cube : _cubes) {
        //     cube.draw(_camera.cameraMatrix());
        // }

        // run World
        _world.run(_camera.cameraMatrix());

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
            _camera.control(event.key);
        }
    }
    _camera.mouseControl(sf::Mouse::getPosition(m_window));
}

void SoftwareRender::debug()
{
    if (_debug) {
        counter.draw(m_window, _vsync);
        // put _camera position
        m_text.setString("Camera position: " + std::to_string(_camera._position[0]) + " " + std::to_string(_camera._position[1]) + " " + std::to_string(_camera._position[2]));
        m_window.draw(m_text);
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

sf::Vector2i SoftwareRender::getSize()
{
    this->_length = m_window.getSize().x;
    this->_width = m_window.getSize().y;

    return sf::Vector2i(LENGTH, HEIGHT);
}

const sf::RenderWindow &SoftwareRender::getWindow() const
{
    return m_window;
}
