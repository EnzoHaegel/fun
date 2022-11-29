/*
** EPITECH PROJECT, 2022
** fun
** File description:
** Projection
*/

#ifndef PROJECTION_HPP_
#define PROJECTION_HPP_

#include <SFML/Graphics.hpp>
#include <math.h>

class Projection {
    public:
        Projection(float near, float far, float hfov, float vfov, sf::Vector2i size);
        ~Projection();

        float _near;
        float _far;
        float _right;
        float _left;
        float _top;
        float _bottom;
        std::vector<std::vector<float>> _projectionMatrix;
        std::vector<std::vector<float>> _viewMatrix;
    protected:
    private:
};

#endif /* !PROJECTION_HPP_ */
