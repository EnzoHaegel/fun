/*
** EPITECH PROJECT, 2022
** fun
** File description:
** World
*/

#ifndef WORLD_HPP_
#define WORLD_HPP_

#include <vector>
#include <SFML/Graphics.hpp>
#include "../engine/Cube.hpp"

class World {
    public:
        World(sf::RenderWindow &m_window, std::vector<std::vector<float>> cameraMatrix, std::vector<std::vector<float>> projectionMatrix, std::vector<std::vector<float>> viewMatrix);
        ~World();

        void run(std::vector<std::vector<float>> cameraMatrix);

    protected:
    private:
        std::vector<std::vector<std::vector<Cube>>> _cubes;
        sf::RenderWindow &_m_window;
        std::vector<std::vector<float>> _cameraMatrix;
        std::vector<std::vector<float>> _projectionMatrix;
        std::vector<std::vector<float>> _viewMatrix;
};

#endif /* !WORLD_HPP_ */
