/*
** EPITECH PROJECT, 2022
** fun
** File description:
** matrix_functions
*/

#include "matrix_functions.h"
#include <math.h>

float **translate(Vec3 const &pos)
{
    float **matrix = new float*[4];

    for (int i = 0; i < 4; i++) {
        matrix[i] = new float[4];
        for (int j = 0; j < 4; j++) {
            if (i == j)
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
        }
    }
    matrix[0][3] = pos.getX();
    matrix[1][3] = pos.getY();
    matrix[2][3] = pos.getZ();
    return matrix;
}

float **rotateX(float angle)
{
    float **matrix = new float*[4];

    for (int i = 0; i < 4; i++) {
        matrix[i] = new float[4];
        for (int j = 0; j < 4; j++) {
            if (i == j)
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
        }
    }
    matrix[1][1] = cos(angle);
    matrix[1][2] = -sin(angle);
    matrix[2][1] = sin(angle);
    matrix[2][2] = cos(angle);
    return matrix;
}

float **rotateY(float angle)
{
    float **matrix = new float*[4];

    for (int i = 0; i < 4; i++) {
        matrix[i] = new float[4];
        for (int j = 0; j < 4; j++) {
            if (i == j)
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
        }
    }
    matrix[0][0] = cos(angle);
    matrix[0][2] = sin(angle);
    matrix[2][0] = -sin(angle);
    matrix[2][2] = cos(angle);
    return matrix;
}

float **rotateZ(float angle)
{
    float **matrix = new float*[4];

    for (int i = 0; i < 4; i++) {
        matrix[i] = new float[4];
        for (int j = 0; j < 4; j++) {
            if (i == j)
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
        }
    }
    matrix[0][0] = cos(angle);
    matrix[0][1] = -sin(angle);
    matrix[1][0] = sin(angle);
    matrix[1][1] = cos(angle);
    return matrix;
}

float **scale(float scale)
{
    float **matrix = new float*[4];

    for (int i = 0; i < 4; i++) {
        matrix[i] = new float[4];
        for (int j = 0; j < 4; j++) {
            if (i == j)
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
        }
    }
    matrix[0][0] = scale;
    matrix[1][1] = scale;
    matrix[2][2] = scale;
    return matrix;
}

float **matrix_mult(float **matrix1, float **matrix2)
{
    float **result = new float*[4];

    for (int i = 0; i < 4; i++) {
        result[i] = new float[4];
        for (int j = 0; j < 4; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 4; k++)
                result[i][j] += matrix1[i][k] * matrix2[k][j];
        }
    }
    return result;
}

