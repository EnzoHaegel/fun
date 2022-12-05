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
#include <SFML/Graphics.hpp>

std::vector<std::vector<float>> mfTranslate(Vec3 const &pos);
std::vector<std::vector<float>> mfTranslate(sf::Vector3i pos);
std::vector<std::vector<float>> mfRotateX(float angle);
std::vector<std::vector<float>> mfRotateY(float angle);
std::vector<std::vector<float>> mfRotateZ(float angle);
std::vector<std::vector<float>> mfScale(float scale);

std::vector<std::vector<float>> matrix_mult(float **matrix1, float **matrix2);
std::vector<std::vector<float>> matrix_mult(float **matrix1, float *matrix2);
std::vector<std::vector<float>> matrix_mult(std::vector<std::vector<float>> matrix1, std::vector<std::vector<float>> matrix2);
std::vector<std::vector<float>> matrix_mult88x44(std::vector<std::vector<float>> matrix1, std::vector<std::vector<float>> matrix2);
std::vector<std::vector<float>> matrix_mult(std::vector<std::vector<float>> matrix1, std::vector<float> matrix2);
std::vector<std::vector<float>> matrix_mult(std::vector<std::vector<float>> matrix1, float number);
std::vector<float> matrix_mult(std::vector<float> matrix1, float number);
std::vector<float> matrix_mult(std::vector<float> matrix1, std::vector<float> matrix2);
std::vector<float> matrix_mult(std::vector<float> matrix1, std::vector<std::vector<float>> matrix2);

std::vector<float> matrix_sub(std::vector<float> matrix1, std::vector<float> matrix2);
std::vector<float> matrix_add(std::vector<float> matrix1, std::vector<float> matrix2);

std::vector<float> convert(float *matrix);
std::vector<std::vector<float>> convert(float **matrix);

#endif /* !MATRIX_FUNCTIONS_H_ */
