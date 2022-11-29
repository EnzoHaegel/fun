/*
** EPITECH PROJECT, 2022
** fun
** File description:
** Camera
*/

#include "Camera.hpp"

Camera::Camera(SoftwareRender *render, float *position)
{
    this->_render = render;
    // add a 1 to the position array
    position.push_back(1);
    this->_position = position;
    this->_forward = new float[3];
    this->_up = new float[3];
    this->_right = new float[3];
    this->_hfov = 90;
    this->_vfov = 90;
    this->_near = 0.1;
    this->_far = 1000;
    this->_movingSpeed = 0.1;
    this->_rotationSpeed = 0.1;
    this->_mouseSensitivity = 0.1;
    this->_yaw = 0;
    this->_pitch = 0;
    this->_roll = 0;
}

Camera::~Camera()
{
}

