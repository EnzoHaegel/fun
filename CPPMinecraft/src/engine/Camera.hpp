/*
** EPITECH PROJECT, 2022
** fun
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include <SFML/Graphics.hpp>
#include "../Utils/Defines.h"
#include "../Utils/matrix_functions.h"

class Camera {
    public:
        Camera(sf::Vector2i window_size, std::vector<float> position = {0, 0, 0});
        ~Camera();

        void setWindowSize(sf::Vector2i);
        void control(sf::Event::KeyEvent key);

        void cameraYaw(float angle);
        void cameraPitch(float angle);
        void cameraUpdateAxii();
        void axiiIdentity();

        std::vector<std::vector<float>> translateMatrix();
        std::vector<std::vector<float>> rotateMatrix();
        std::vector<std::vector<float>> cameraMatrix();

        sf::Vector2i _window_size;
        std::vector<float> _position;
        std::vector<float> _forward;
        std::vector<float> _up;
        std::vector<float> _right;
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
