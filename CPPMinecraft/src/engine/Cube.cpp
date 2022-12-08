/*
** EPITECH PROJECT, 2022
** fun
** File description:
** Cube
*/

#include "Cube.hpp"

Cube::Cube(sf::RenderWindow &m_window, sf::Vector3i position, std::vector<std::vector<float>> cameraMatrix, std::vector<std::vector<float>> projectionMatrix, std::vector<std::vector<float>> viewMatrix, sf::Texture &texture)
    :   m_window(m_window), texture(texture)
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
        std::vector<float>{0, 1, 2, 3}, // 0 - 0 0 0 -> 1 1 0
        std::vector<float>{4, 5, 6, 7}, // 1 - 0 0 1 -> 1 1 1
        std::vector<float>{0, 4, 5, 1}, // 2 - 0 0 0 -> 0 0 1
        std::vector<float>{2, 3, 7, 6}, // 3 - 1 1 0 -> 1 1 1
        std::vector<float>{1, 2, 6, 5}, // 4 - 0 1 0 -> 1 1 1
        std::vector<float>{0, 3, 7, 4}  // 5 - 0 0 0 -> 1 0 0
    };
    this->_cameraMatrix = cameraMatrix;
    this->_isVisible = true;
    this->_isSolid = true;
    this->_drawVertices = false;
    this->_label = "Cube";
    this->_projectionMatrix = projectionMatrix;
    this->_viewMatrix = viewMatrix;
    this->_texture = true;
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
    for (size_t i = 0; i < vertices.size(); i++) {
        std::cout << "v" << i << ": ";
        for (size_t j = 0; j < vertices[i].size(); j++) {
            std::cout << vertices[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<float>> Cube::screenProjection()
{
    std::vector<std::vector<float>> tmp_vertices = matrix_mult88x44(this->_vertices, this->_cameraMatrix);
    tmp_vertices = matrix_mult88x44(tmp_vertices, this->_projectionMatrix);

    for (size_t i = 0; i < tmp_vertices.size(); i++) {
        tmp_vertices[i][0] /= tmp_vertices[i][3];
        tmp_vertices[i][1] /= tmp_vertices[i][3];
        tmp_vertices[i][2] /= tmp_vertices[i][3];
        tmp_vertices[i][3] /= tmp_vertices[i][3];
    }
    for (size_t i = 0; i < tmp_vertices.size(); i++) {
        if (tmp_vertices[i][0] > 2 || tmp_vertices[i][0] < -2)
            tmp_vertices[i][0] = 0;
        if (tmp_vertices[i][1] > 2 || tmp_vertices[i][1] < -2)
            tmp_vertices[i][1] = 0;
        if (tmp_vertices[i][2] > 2 || tmp_vertices[i][2] < -2)
            tmp_vertices[i][2] = 0;
    }   
    tmp_vertices = matrix_mult88x44(tmp_vertices, this->_viewMatrix);   
    for (size_t i = 0; i < tmp_vertices.size(); i++) {
        tmp_vertices[i].erase(tmp_vertices[i].begin() + 2, tmp_vertices[i].end());
    }
    for (size_t i = 0; i < tmp_vertices.size(); i++) {
        tmp_vertices[i][0] /= 2;
        tmp_vertices[i][1] /= 2;
    }
    return(tmp_vertices);
}

void Cube::draw(std::vector<std::vector<float>> camera_matrix, std::vector<int> face_to_draw)
{
    this->_cameraMatrix = camera_matrix;
    std::vector<std::vector<float>> twoDvertices = this->screenProjection();

    if (this->_drawVertices) {
        for (size_t i = 0; i < twoDvertices.size(); i++) {
            if (!any_func(twoDvertices[i], 1920/2, 1080/2)) {
                sf::CircleShape circle(2);
                circle.setFillColor(sf::Color::White);
                circle.setPosition(twoDvertices[i][0], twoDvertices[i][1]);
                this->m_window.draw(circle);
            }
        }
    }

    bool is_visible = true;
    // draw the 4 lines of each faces [0, 1, 2, 3, 0]
    for (size_t i = 0; i < this->_faces.size(); i++) {
        if (std::find(face_to_draw.begin(), face_to_draw.end(), i) == face_to_draw.end())
            continue;
        for (size_t j = 0; j < this->_faces[i].size() - 1; j++)
            if (any_func(twoDvertices[this->_faces[i][j]], 1920/2, 1080/2) || any_func(twoDvertices[this->_faces[i][j + 1]], 1920/2, 1080/2))
                is_visible = false;
        if (!is_visible)
            continue;
        sf::ConvexShape convex;
        // M of coordinates (x,y) is inside the rectangle iff
        // (0<AM⋅AB<AB⋅AB)∧(0<AM⋅AD<AD⋅AD)
        // (scalar product of vectors)
        // check if the middle of the screen is inside the rectangle
        // if not, don't draw it
        sf::Vector2f AB(twoDvertices[this->_faces[i][1]][0] - twoDvertices[this->_faces[i][0]][0], twoDvertices[this->_faces[i][1]][1] - twoDvertices[this->_faces[i][0]][1]);
        sf::Vector2f AD(twoDvertices[this->_faces[i][3]][0] - twoDvertices[this->_faces[i][0]][0], twoDvertices[this->_faces[i][3]][1] - twoDvertices[this->_faces[i][0]][1]);
        sf::Vector2f AM(1920/2 - twoDvertices[this->_faces[i][0]][0], 1080/2 - twoDvertices[this->_faces[i][0]][1]);
        float ABAB = AB.x * AB.x + AB.y * AB.y;
        float ADAD = AD.x * AD.x + AD.y * AD.y;
        float ABAM = AB.x * AM.x + AB.y * AM.y;
        float ADAM = AD.x * AM.x + AD.y * AM.y;

        convex.setPointCount(4);
        convex.setPoint(0, sf::Vector2f(twoDvertices[this->_faces[i][0]][0], twoDvertices[this->_faces[i][0]][1]));
        convex.setPoint(1, sf::Vector2f(twoDvertices[this->_faces[i][1]][0], twoDvertices[this->_faces[i][1]][1]));
        convex.setPoint(2, sf::Vector2f(twoDvertices[this->_faces[i][2]][0], twoDvertices[this->_faces[i][2]][1]));
        convex.setPoint(3, sf::Vector2f(twoDvertices[this->_faces[i][3]][0], twoDvertices[this->_faces[i][3]][1]));
        if (this->_texture) {
            // set the texture
            convex.setTexture(&this->texture);
        } else {
            convex.setFillColor(sf::Color::Transparent);
            convex.setOutlineColor(sf::Color::White);
            convex.setOutlineThickness(1);
        }
        if (!(ABAM < 0 || ABAM > ABAB || ADAM < 0 || ADAM > ADAD)) {
            if (_texture) {
                convex.setFillColor(sf::Color(0, 0, 0, 25));
            } else {
                convex.setOutlineColor(sf::Color::Blue);
                convex.setOutlineThickness(4);
            }
        }
        this->m_window.draw(convex);
        is_visible = true;
    }
}

bool Cube::any_func(std::vector<float> arr, float a, float b)
{
    for (size_t i = 0; i < arr.size(); i++) {
        if (static_cast<int>(arr[i]) == a || static_cast<int>(arr[i]) == b)
            return(true);
    }
    return(false);
}
