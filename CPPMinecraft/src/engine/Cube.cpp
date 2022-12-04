/*
** EPITECH PROJECT, 2022
** fun
** File description:
** Cube
*/

#include "Cube.hpp"

Cube::Cube(sf::RenderWindow m_window, sf::Vector3i position, std::vector<std::vector<float>> cameraMatrix, std::vector<std::vector<float>> projectionMatrix, std::vector<std::vector<float>> viewMatrix)
{
    // this->m_window = m_window;
    this->_pos = position;
    this->_vertices = std::vector<std::vector<float>>{
        std::vector<float>{(float)this->_pos.x + 0, (float)this->_pos.z + 0, (float)this->_pos.y + 0, 1}, // 0
        std::vector<float>{(float)this->_pos.x + 0, (float)this->_pos.z + 1, (float)this->_pos.y + 0, 1}, // 1
        std::vector<float>{(float)this->_pos.x + 1, (float)this->_pos.z + 1, (float)this->_pos.y + 0, 1}, // 2
        std::vector<float>{(float)this->_pos.x + 1, (float)this->_pos.z + 0, (float)this->_pos.y + 0, 1}, // 3
        std::vector<float>{(float)this->_pos.x + 0, (float)this->_pos.z + 0, (float)this->_pos.y + 1, 1}, // 4
        std::vector<float>{(float)this->_pos.x + 0, (float)this->_pos.z + 1, (float)this->_pos.y + 1, 1}, // 5
        std::vector<float>{(float)this->_pos.x + 1, (float)this->_pos.z + 1, (float)this->_pos.y + 1, 1}, // 6
        std::vector<float>{(float)this->_pos.x + 1, (float)this->_pos.z + 0, (float)this->_pos.y + 1, 1}  // 7
    };
    this->_faces = std::vector<std::vector<float>>{
        std::vector<float>{0, 1, 3, 2}, // 0
        std::vector<float>{4, 5, 7, 6}, // 1
        std::vector<float>{0, 4, 5, 1}, // 2
        std::vector<float>{2, 3, 7, 6}, // 3
        std::vector<float>{1, 2, 6, 5}, // 4
        std::vector<float>{0, 3, 7, 4}  // 5
    };
    this->_cameraMatrix = cameraMatrix;
    this->_isVisible = true;
    this->_isSolid = true;
    this->_drawVertices = false;
    this->_label = "Cube";
    this->_projectionMatrix = projectionMatrix;
    this->_viewMatrix = viewMatrix;
}

Cube::~Cube()
{
}

void Cube::translate(sf::Vector3i pos)
{
    this->_vertices = matrix_mult88x44(this->_vertices, mfTranslate(pos));
}

void Cube::rotateX(float a)
{
    this->_vertices = matrix_mult88x44(this->_vertices, mfRotateX(a));
}

void Cube::rotateY(float a)
{
    this->_vertices = matrix_mult88x44(this->_vertices, mfRotateY(a));
}

void Cube::rotateZ(float a)
{
    this->_vertices = matrix_mult88x44(this->_vertices, mfRotateZ(a));
}

void Cube::scale(float s)
{
    this->_vertices = matrix_mult88x44(this->_vertices, mfScale(s));
}

void Cube::screenProjection()
{
    this->_vertices = matrix_mult88x44(this->_vertices, this->_cameraMatrix);
    this->_vertices = matrix_mult88x44(this->_vertices, this->_projectionMatrix);
    for (int i = 0; i < this->_vertices.size(); i++) {
        this->_vertices[i][0] /= this->_vertices[i][3];
        this->_vertices[i][1] /= this->_vertices[i][3];
        this->_vertices[i][2] /= this->_vertices[i][3];
        this->_vertices[i][3] /= this->_vertices[i][3];
    }
    for (int i = 0; i < this->_vertices.size(); i++) {
        if (this->_vertices[i][0] > 2 || this->_vertices[i][0] < -2)
            this->_vertices[i][0] = 0;
        if (this->_vertices[i][1] > 2 || this->_vertices[i][1] < -2)
            this->_vertices[i][1] = 0;
        if (this->_vertices[i][2] > 2 || this->_vertices[i][2] < -2)
            this->_vertices[i][2] = 0;
    }   
    this->_vertices = matrix_mult88x44(this->_vertices, this->_viewMatrix);   
    for (int i = 0; i < this->_vertices.size(); i++) {
        this->_vertices[i].erase(this->_vertices[i].begin() + 2, this->_vertices[i].end());
    }
    
}
