/*
** EPITECH PROJECT, 2022
** fun
** File description:
** Projection
*/

#include "Projection.hpp"

Projection::Projection(float near, float far, float hfov, float vfov, sf::Vector2i size)
{
    this->_near = near;
    this->_far = far;
    this->_right = tan(hfov / 2);
    this->_left = -this->_right;
    this->_top = tan(vfov / 2);
    this->_bottom = -this->_top;
    
    float m00 = 2 / (this->_right - this->_left);
    float m11 = 2 / (this->_top - this->_bottom);
    float m22 = (this->_far + this->_near) / (this->_far - this->_near); 
    float m32 = -2 * this->_near * this->_far / (this->_far - this->_near);

    this->_projectionMatrix = std::vector<std::vector<float>>{
        std::vector<float>{m00, 0, 0, 0},
        std::vector<float>{0, m11, 0, 0},
        std::vector<float>{0, 0, m22, 1},
        std::vector<float>{0, 0, m32, 0}
    };

    float HW = size.x;
    float HH = size.y;
    this->_viewMatrix = std::vector<std::vector<float>>{
        std::vector<float>{HW, 0, 0, 0},
        std::vector<float>{0, -HH, 0, 0},
        std::vector<float>{0, 0, 1, 0},
        std::vector<float>{HW, HH, 0, 1}
    };
}

Projection::~Projection()
{
}
