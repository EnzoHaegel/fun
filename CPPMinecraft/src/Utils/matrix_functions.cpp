/*
** EPITECH PROJECT, 2022
** fun
** File description:
** matrix_functions
*/

#include "matrix_functions.h"
#include <math.h>

std::vector<std::vector<float>> mfTranslate(Vec3 const &pos)
{
    std::vector<std::vector<float>>matrix = {
        {1, 0, 0, pos.getX()},
        {0, 1, 0, pos.getY()},
        {0, 0, 1, pos.getZ()},
        {0, 0, 0, 1}
    };
    return matrix;
}

std::vector<std::vector<float>> mfTtranslate(sf::Vector3i const &pos)
{
    std::vector<std::vector<float>>matrix = {
        {1, 0, 0, (float)pos.x},
        {0, 1, 0, (float)pos.y},
        {0, 0, 1, (float)pos.z},
        {0, 0, 0, 1}
    };
    return matrix;
}

std::vector<std::vector<float>> mfRotateX(float angle)
{
    std::vector<std::vector<float>>matrix = {
        {1, 0, 0, 0},
        {0, cos(angle), -sin(angle), 0},
        {0, sin(angle), cos(angle), 0},
        {0, 0, 0, 1}
    };
    return matrix;
}

std::vector<std::vector<float>> mfRotateY(float angle)
{
    std::vector<std::vector<float>>matrix = {
        {cos(angle), 0, sin(angle), 0},
        {0, 1, 0, 0},
        {-sin(angle), 0, cos(angle), 0},
        {0, 0, 0, 1}
    };
    return matrix;
}

std::vector<std::vector<float>> mfRotateZ(float angle)
{
    std::vector<std::vector<float>>matrix = {
        {cos(angle), -sin(angle), 0, 0},
        {sin(angle), cos(angle), 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };
    return matrix;
}

std::vector<std::vector<float>> mfScale(float scale)
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

std::vector<std::vector<float>> matrix_mult(std::vector<std::vector<float>> matrix1, float number)
{
    std::vector<std::vector<float>>matrix = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            matrix[i][j] = matrix1[i][j] * number;
        }
    }
    return matrix;
}

std::vector<float> matrix_mult(std::vector<float> matrix1, float number)
{
    std::vector<float>matrix = {0, 0, 0, 0};
    for (int i = 0; i < 4; i++) {
        matrix[i] = matrix1[i] * number;
    }
    return matrix;
}

std::vector<float> matrix_mult(std::vector<float> matrix1, std::vector<float> matrix2)
{
    std::vector<float>matrix = {0, 0, 0, 0};
    for (int i = 0; i < 4; i++) {
        matrix[i] = matrix1[i] * matrix2[i];
    }
    return matrix;
}

std::vector<float> matrix_mult(std::vector<float> matrix1, std::vector<std::vector<float>> matrix2)
{
    std::vector<float>matrix = {0, 0, 0, 0};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            matrix[i] += matrix1[j] * matrix2[j][i];
        }
    }
    return matrix;
}

std::vector<std::vector<float>> matrix_mult88x44(std::vector<std::vector<float>> matrix1, std::vector<std::vector<float>> matrix2)
{
    // matrix1 is 8x8
    // matrix2 is 4x4
    std::vector<std::vector<float>>matrix = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return matrix;
}

std::vector<std::vector<float>> convert(float **matrix)
{
    std::vector<std::vector<float>>matrix2 = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            matrix2[i][j] = matrix[i][j];
        }
    }
    return matrix2;
}

std::vector<float> convert(float *matrix)
{
    std::vector<float>matrix2 = {0, 0, 0, 0};
    for (int i = 0; i < 4; i++) {
        matrix2[i] = matrix[i];
    }
    return matrix2;
}

std::vector<float> matrix_sub(std::vector<float>matrix1, std::vector<float>matrix2)
{
    std::vector<float>matrix = {0, 0, 0, 0};
    for (int i = 0; i < 4; i++) {
        matrix[i] = matrix1[i] - matrix2[i];
    }
    return matrix;
}

std::vector<float> matrix_add(std::vector<float>matrix1, std::vector<float>matrix2)
{
    std::vector<float>matrix = {0, 0, 0, 0};
    for (int i = 0; i < 4; i++) {
        matrix[i] = matrix1[i] + matrix2[i];
    }
    return matrix;
}

// Path: CPPMinecraft/src/Utils/matrix_functions.h
