/*
** EPITECH PROJECT, 2022
** fun
** File description:
** World
*/

#include "World.hpp"
#include <random>

World::World(sf::RenderWindow &m_window, std::vector<std::vector<float>> cameraMatrix, std::vector<std::vector<float>> projectionMatrix, std::vector<std::vector<float>> viewMatrix)
    : _m_window(m_window), _cameraMatrix(cameraMatrix), _projectionMatrix(projectionMatrix), _viewMatrix(viewMatrix)
{
    // std::vector<std::vector<std::vector<Cube>>> _cubes;
    if (!_texture.loadFromFile("assets/texture/stone.png"))
        std::cout << "Error loading texture" << std::endl;
    _texture.setSmooth(true);
    _texture.setRepeated(true);
    for (int x = 0; x < 10; x++) {
        std::vector<std::vector<Cube>> _cubesX;
        for (int y = 0; y < 10; y++) {
            std::vector<Cube> _cubesY;
            for (int z = 0; z < 10; z++) {
                // random 70% chance to add a Cube
                Cube cube(m_window, sf::Vector3i(x, y, z), cameraMatrix, projectionMatrix, viewMatrix, _texture);
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> dis(0, 100);
                // if (dis(gen) > 70)
                //     cube._isSolid = false;
                _cubesY.push_back(cube);
            }
            _cubesX.push_back(_cubesY);
        }
        _cubes.push_back(_cubesX);
    }
}

World::~World()
{
}

void World::run(std::vector<std::vector<float>> cameraMatrix)
{
    _cameraMatrix = cameraMatrix;
    for (auto &x : _cubes) {
        for (auto &y : x) {
            for (auto &z : y) {
                std::vector<int> faces_to_draw = {0, 1, 2, 3, 4, 5};
                // for every faces of the cube, if you have a cube next to it, remove the face from the list
                if (z._pos.y > 0 && _cubes[z._pos.x][z._pos.y - 1][z._pos.z]._isSolid)
                    faces_to_draw.erase(std::remove(faces_to_draw.begin(), faces_to_draw.end(), 0), faces_to_draw.end());
                if (z._pos.y < 9 && _cubes[z._pos.x][z._pos.y + 1][z._pos.z]._isSolid)
                    faces_to_draw.erase(std::remove(faces_to_draw.begin(), faces_to_draw.end(), 1), faces_to_draw.end());
                if (z._pos.x > 0 && _cubes[z._pos.x - 1][z._pos.y][z._pos.z]._isSolid)
                    faces_to_draw.erase(std::remove(faces_to_draw.begin(), faces_to_draw.end(), 2), faces_to_draw.end());
                if (z._pos.x < 9 && _cubes[z._pos.x + 1][z._pos.y][z._pos.z]._isSolid)
                    faces_to_draw.erase(std::remove(faces_to_draw.begin(), faces_to_draw.end(), 3), faces_to_draw.end());
                if (z._pos.z < 9 && _cubes[z._pos.x][z._pos.y][z._pos.z + 1]._isSolid)
                    faces_to_draw.erase(std::remove(faces_to_draw.begin(), faces_to_draw.end(), 4), faces_to_draw.end());
                if (z._pos.z > 0 && _cubes[z._pos.x][z._pos.y][z._pos.z - 1]._isSolid)
                    faces_to_draw.erase(std::remove(faces_to_draw.begin(), faces_to_draw.end(), 5), faces_to_draw.end());
                // std::cout << "faces to draw: " << faces_to_draw.size() << std::endl;
                z.draw(_cameraMatrix, faces_to_draw);
            }
        }
    }
}
