/*
** EPITECH PROJECT, 2022
** fun
** File description:
** matrix_functions
*/

#include "matrix_functions.h"
#include <math.h>

std::vector<std::vector<float>> translate(Vec3 const &pos)
{
    std::vector<std::vector<float>>matrix = {
        {1, 0, 0, pos.getX()},
        {0, 1, 0, pos.getY()},
        {0, 0, 1, pos.getZ()},
        {0, 0, 0, 1}
    };
    return matrix;
}

std::vector<std::vector<float>> rotateX(float angle)
{
    std::vector<std::vector<float>>matrix = {
        {1, 0, 0, 0},
        {0, cos(angle), -sin(angle), 0},
        {0, sin(angle), cos(angle), 0},
        {0, 0, 0, 1}
    };
    return matrix;
}

std::vector<std::vector<float>> rotateY(float angle)
{
    std::vector<std::vector<float>>matrix = {
        {cos(angle), 0, sin(angle), 0},
        {0, 1, 0, 0},
        {-sin(angle), 0, cos(angle), 0},
        {0, 0, 0, 1}
    };
    return matrix;
}

std::vector<std::vector<float>> rotateZ(float angle)
{
    std::vector<std::vector<float>>matrix = {
        {cos(angle), -sin(angle), 0, 0},
        {sin(angle), cos(angle), 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
    return matrix;
}

std::vector<std::vector<float>> scale(float scale)
{
    std::vector<std::vector<float>>matrix = {
        {scale, 0, 0, 0},
        {0, scale, 0, 0},
        {0, 0, scale, 0},
        {0, 0, 0, 1}
    };
    return matrix;
}

std::vector<std::vector<float>> matrix_mult(float **matrix1, float **matrix2)
{
    std::vector<std::vector<float>>matrix = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return matrix;
}

std::vector<std::vector<float>> matrix_mult(float **matrix1, float *matrix2)
{
    std::vector<std::vector<float>>matrix = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                matrix[i][j] += matrix1[i][k] * matrix2[k];
            }
        }
    }
    return matrix;
}

std::vector<std::vector<float>> matrix_mult(std::vector<std::vector<float>> matrix1, std::vector<std::vector<float>> matrix2)
{
    std::vector<std::vector<float>>matrix = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return matrix;
}

std::vector<std::vector<float>> matrix_mult(std::vector<std::vector<float>> matrix1, std::vector<float>matrix2)
{
    std::vector<std::vector<float>>matrix = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                matrix[i][j] += matrix1[i][k] * matrix2[k];
            }
        }
    }
    return matrix;
}


// Path: CPPMinecraft/src/Utils/matrix_functions.h
