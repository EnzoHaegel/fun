/*
** EPITECH PROJECT, 2022
** fun
** File description:
** matrix_functions
*/

#ifndef MATRIX_FUNCTIONS_H_
#define MATRIX_FUNCTIONS_H_

#include <iostream>
#include <vector>
#include "./Vec3.hpp"

std::vector<std::vector<float>> translate(Vec3 const &pos);
std::vector<std::vector<float>> rotateX(float angle);
std::vector<std::vector<float>> rotateY(float angle);
std::vector<std::vector<float>> rotateZ(float angle);
std::vector<std::vector<float>> scale(float scale);

std::vector<std::vector<float>> matrix_mult(float **matrix1, float **matrix2);
std::vector<std::vector<float>> matrix_mult(float **matrix1, float *matrix2);
std::vector<std::vector<float>> matrix_mult(std::vector<std::vector<float>> matrix1, std::vector<std::vector<float>> matrix2);
std::vector<std::vector<float>> matrix_mult(std::vector<std::vector<float>> matrix1, std::vector<float>matrix2);

#endif /* !MATRIX_FUNCTIONS_H_ */
