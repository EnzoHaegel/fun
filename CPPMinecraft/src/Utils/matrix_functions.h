/*
** EPITECH PROJECT, 2022
** fun
** File description:
** matrix_functions
*/

#ifndef MATRIX_FUNCTIONS_H_
#define MATRIX_FUNCTIONS_H_

#include <iostream>
#include "../engine/Vec3.hpp"

float** translate(Vec3 const &pos);
float** rotateX(float angle);
float** rotateY(float angle);
float** rotateZ(float angle);
float** scale(float scale);

float **matrix_mult(float **matrix1, float **matrix2);

#endif /* !MATRIX_FUNCTIONS_H_ */
