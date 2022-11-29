/*
** EPITECH PROJECT, 2022
** fun
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "SoftwareRender.hpp"

class Camera {
    public:
        Camera(SoftwareRender *render, std::vector<float> position = {0.0, 0.0, 0.0});
        ~Camera();

        SoftwareRender *_render;
        float *_position;
        float *_forward;
        float *_up;
        float *_right;
        float _hfov;
        float _vfov;
        float _near;
        float _far;
        float _movingSpeed;
        float _rotationSpeed;
        float _mouseSensitivity;

        float _yaw;
        float _pitch;
        float _roll;

    protected:
    private:
};

#endif /* !CAMERA_HPP_ */
