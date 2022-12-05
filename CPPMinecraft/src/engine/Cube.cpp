/*
** EPITECH PROJECT, 2022
** fun
** File description:
** Cube
*/

#include "Cube.hpp"

Cube::Cube(sf::RenderWindow &m_window, sf::Vector3i position, std::vector<std::vector<float>> cameraMatrix, std::vector<std::vector<float>> projectionMatrix, std::vector<std::vector<float>> viewMatrix)
    :   m_window(m_window)
{
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

void Cube::debugVertices(std::vector<std::vector<float>> vertices)
{
    std::cout << "Vertices:" << std::endl;
    for (int i = 0; i < vertices.size(); i++) {
        std::cout << "v" << i << ": ";
        for (int j = 0; j < vertices[i].size(); j++) {
            std::cout << vertices[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<float>> Cube::screenProjection()
{
    std::vector<std::vector<float>> tmp_vertices = matrix_mult88x44(this->_vertices, this->_cameraMatrix);
    tmp_vertices = matrix_mult88x44(tmp_vertices, this->_projectionMatrix);

    for (int i = 0; i < tmp_vertices.size(); i++) {
        tmp_vertices[i][0] /= tmp_vertices[i][3];
        tmp_vertices[i][1] /= tmp_vertices[i][3];
        tmp_vertices[i][2] /= tmp_vertices[i][3];
        tmp_vertices[i][3] /= tmp_vertices[i][3];
    }
    for (int i = 0; i < tmp_vertices.size(); i++) {
        if (tmp_vertices[i][0] > 2 || tmp_vertices[i][0] < -2)
            tmp_vertices[i][0] = 0;
        if (tmp_vertices[i][1] > 2 || tmp_vertices[i][1] < -2)
            tmp_vertices[i][1] = 0;
        if (tmp_vertices[i][2] > 2 || tmp_vertices[i][2] < -2)
            tmp_vertices[i][2] = 0;
    }   
    tmp_vertices = matrix_mult88x44(tmp_vertices, this->_viewMatrix);   
    for (int i = 0; i < tmp_vertices.size(); i++) {
        tmp_vertices[i].erase(tmp_vertices[i].begin() + 2, tmp_vertices[i].end());
    }
    for (int i = 0; i < tmp_vertices.size(); i++) {
        tmp_vertices[i][0] /= 2;
        tmp_vertices[i][1] /= 2;
    }
    return(tmp_vertices);
}

void Cube::draw(std::vector<std::vector<float>> camera_matrix)
{
    this->_cameraMatrix = camera_matrix;
    std::vector<std::vector<float>> twoDvertices = this->screenProjection();

    if (this->_drawVertices) {
        for (int i = 0; i < twoDvertices.size(); i++) {
            if (!any_func(twoDvertices[i], 1920/2, 1080/2)) {
                sf::CircleShape circle(2);
                circle.setFillColor(sf::Color::White);
                circle.setPosition(twoDvertices[i][0], twoDvertices[i][1]);
                this->m_window.draw(circle);
            }
        }
    }
    // draw the 4 lines of each faces [0, 1, 2, 3, 0]
    for (int i = 0; i < this->_faces.size(); i++) {
        for (int j = 0; j < this->_faces[i].size() - 1; j++) {
            if (any_func(twoDvertices[this->_faces[i][j]], 1920/2, 1080/2) || any_func(twoDvertices[this->_faces[i][j + 1]], 1920/2, 1080/2))
                continue;
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(twoDvertices[this->_faces[i][j]][0], twoDvertices[this->_faces[i][j]][1])),
                sf::Vertex(sf::Vector2f(twoDvertices[this->_faces[i][j + 1]][0], twoDvertices[this->_faces[i][j + 1]][1]))
            };
            this->m_window.draw(line, 2, sf::Lines);
        }
    }
}

bool Cube::any_func(std::vector<float> arr, float a, float b)
{
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == a || arr[i] == b)
            return(true);
    }
    return(false);
}
