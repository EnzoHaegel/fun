/*
** EPITECH PROJECT, 2022
** fun
** File description:
** Cube
*/

#ifndef CUBE_HPP_
#define CUBE_HPP_

#include "../Utils/Defines.h"
#include "../Utils/matrix_functions.h"
#include <SFML/Graphics.hpp>
#include <string>

class Cube {
    public:
        Cube(sf::RenderWindow &m_window, sf::Vector3i position, std::vector<std::vector<float>> cameraMatrix, std::vector<std::vector<float>> projectionMatrix, std::vector<std::vector<float>> viewMatrix);
        ~Cube();

        void setPos(sf::Vector3i pos);
        void translate(sf::Vector3i pos);
        void rotateX(float a);
        void rotateY(float a);
        void rotateZ(float a);
        void scale(float s);
        std::vector<std::vector<float>> screenProjection();
        void draw(std::vector<std::vector<float>> camera_matrix);

        void debugVertices(std::vector<std::vector<float>> vertices);
        bool any_func(std::vector<float> arr, float a, float b);

    protected:
    private:

    sf::RenderWindow &m_window;
    sf::Vector3i _pos;
    std::vector<std::vector<float>> _vertices;
    std::vector<std::vector<float>> _faces;
    std::vector<std::vector<float>> _cameraMatrix;
    bool _isVisible;
    bool _isSolid;
    bool _drawVertices;
    std::string _label;
    std::vector<std::vector<float>> _projectionMatrix;
    std::vector<std::vector<float>> _viewMatrix;
};

#endif /* !CUBE_HPP_ */
