/*
** EPITECH PROJECT, 2022
** fun
** File description:
** Camera
*/

#include "Camera.hpp"

Camera::Camera(sf::Vector2i window_size, std::vector<float> position)
{
    position.push_back(1);
    this->_position = position;
    this->_forward = std::vector<float>{0, 0, 1, 1};
    this->_up = std::vector<float>{0, 1, 0, 1};
    this->_right = std::vector<float>{1, 0, 0, 1};
    this->_hfov = PI / 3;
    this->_window_size = window_size;
    this->_vfov = _hfov * (_window_size.y / _window_size.x);
    this->_near = 0.1;
    this->_far = 100;
    this->_movingSpeed = 0.3;
    this->_rotationSpeed = 0.015;
    this->_mouseSensitivity = 0.1;
    this->_yaw = 0;
    this->_pitch = 0;
    this->_roll = 0;
}

Camera::~Camera()
{
}

void Camera::setWindowSize(sf::Vector2i window_size) {
    this->_window_size = window_size;
    this->_vfov = _hfov * (_window_size.y / _window_size.x);
}

void Camera::control(sf::Event::KeyEvent key)
{
    if (key.code == sf::Keyboard::Z) {
        this->_position = matrix_add(this->_position, matrix_mult(this->_forward, this->_movingSpeed));
    }
    if (key.code == sf::Keyboard::S) {
        this->_position = matrix_sub(this->_position, matrix_mult(this->_forward, this->_movingSpeed));
    }
    if (key.code == sf::Keyboard::Q) {
        this->_position = matrix_sub(this->_position, matrix_mult(this->_right, this->_movingSpeed));
    }
    if (key.code == sf::Keyboard::D) {
        this->_position = matrix_add(this->_position, matrix_mult(this->_right, this->_movingSpeed));
    }
    if (key.code == sf::Keyboard::Space) {
        this->_position = matrix_add(this->_position, matrix_mult(this->_up, this->_movingSpeed));
    }
    if (key.code == sf::Keyboard::LShift) {
        this->_position = matrix_sub(this->_position, matrix_mult(this->_up, this->_movingSpeed));
    }
}

void Camera::cameraYaw(float angle)
{
    this->_yaw += angle;
}

void Camera::cameraPitch(float angle)
{
    this->_pitch += angle;
}

void Camera::axiiIdentity()
{
    this->_forward = std::vector<float>{0, 0, 1, 1};
    this->_up = std::vector<float>{0, 1, 0, 1};
    this->_right = std::vector<float>{1, 0, 0, 1};
}

void Camera::cameraUpdateAxii()
{
    std::vector<std::vector<float>> rotate = matrix_mult(rotateX(this->_pitch), rotateY(this->_yaw));
    this->axiiIdentity();
    this->_forward = matrix_mult(this->_forward, rotate);
    this->_right = matrix_mult(this->_right, rotate);
    this->_up = matrix_mult(this->_up, rotate);
}

std::vector<std::vector<float>> Camera::translateMatrix()
{
    return std::vector<std::vector<float>> {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {-this->_position[0], -this->_position[1], -this->_position[2], 1}
    };
}

std::vector<std::vector<float>> Camera::rotateMatrix()
{
    return std::vector<std::vector<float>> {
        {this->_right[0], this->_up[0], this->_forward[0], 0},
        {this->_right[1], this->_up[1], this->_forward[1], 0},
        {this->_right[2], this->_up[2], this->_forward[2], 0},
        {0, 0, 0, 1}
    };
}

std::vector<std::vector<float>> Camera::cameraMatrix()
{
    this->cameraUpdateAxii();
    return matrix_mult(this->translateMatrix(), this->rotateMatrix());
}
