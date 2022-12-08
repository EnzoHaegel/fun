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
        Cube(sf::RenderWindow &m_window, sf::Vector3i position, std::vector<std::vector<float>> cameraMatrix, std::vector<std::vector<float>> projectionMatrix, std::vector<std::vector<float>> viewMatrix, sf::Texture &texture);
        ~Cube();

        void setPos(sf::Vector3i pos);
        void translate(sf::Vector3i pos);
        void rotateX(float a);
        void rotateY(float a);
        void rotateZ(float a);
        void scale(float s);
        std::vector<std::vector<float>> screenProjection();
        void draw(std::vector<std::vector<float>> camera_matrix, std::vector<int> face_to_draw = std::vector<int>{0, 1, 2, 3, 4, 5});

        void debugVertices(std::vector<std::vector<float>> vertices);
        bool any_func(std::vector<float> arr, float a, float b);

        sf::Vector3i _pos;
        bool _isSolid;
        sf::Texture &texture;
    protected:
    private:

    sf::RenderWindow &m_window;
    std::vector<std::vector<float>> _vertices;
    std::vector<std::vector<float>> _faces;
    std::vector<std::vector<float>> _cameraMatrix;
    bool _isVisible;
    bool _drawVertices;
    std::string _label;
    std::vector<std::vector<float>> _projectionMatrix;
    std::vector<std::vector<float>> _viewMatrix;
    bool _texture;
};

#endif /* !CUBE_HPP_ */
