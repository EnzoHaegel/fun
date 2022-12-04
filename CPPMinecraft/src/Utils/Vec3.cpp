/*
** EPITECH PROJECT, 2022
** fun
** File description:
** Vec3
*/

#include "Vec3.hpp"

Vec3::Vec3(float x, float y, float z)
{
    this->_x = x;
    this->_y = y;
    this->_z = z;
}

Vec3::~Vec3()
{
}

float Vec3::getX() const
{
    return this->_x;
}

float Vec3::getY() const
{
    return this->_y;
}

float Vec3::getZ() const
{
    return this->_z;
}

void Vec3::setX(float x)
{
    this->_x = x;
}

void Vec3::setY(float y)
{
    this->_y = y;
}

void Vec3::setZ(float z)
{
    this->_z = z;
}

Vec3 Vec3::get() const
{
    return Vec3(this->_x, this->_y, this->_z);
}

void Vec3::set(const Vec3 &vec)
{
    this->_x = vec.getX();
    this->_y = vec.getY();
    this->_z = vec.getZ();
}

// overload operators
Vec3 Vec3::operator+(const Vec3 &vec) const
{
    return Vec3(this->_x + vec.getX(), this->_y + vec.getY(), this->_z + vec.getZ());
}

Vec3 Vec3::operator-(const Vec3 &vec) const
{
    return Vec3(this->_x - vec.getX(), this->_y - vec.getY(), this->_z - vec.getZ());
}

Vec3 Vec3::operator*(const Vec3 &vec) const
{
    return Vec3(this->_x * vec.getX(), this->_y * vec.getY(), this->_z * vec.getZ());
}

Vec3 Vec3::operator/(const Vec3 &vec) const
{
    return Vec3(this->_x / vec.getX(), this->_y / vec.getY(), this->_z / vec.getZ());
}

Vec3 Vec3::operator+(float val) const
{
    return Vec3(this->_x + val, this->_y + val, this->_z + val);
}

Vec3 Vec3::operator-(float val) const
{
    return Vec3(this->_x - val, this->_y - val, this->_z - val);
}

Vec3 Vec3::operator*(float val) const
{
    return Vec3(this->_x * val, this->_y * val, this->_z * val);
}

Vec3 Vec3::operator/(float val) const
{
    return Vec3(this->_x / val, this->_y / val, this->_z / val);
}

// overload stream operators

std::ostream &operator<<(std::ostream &os, const Vec3 &vec)
{
    os << "x: " << vec.getX() << " y: " << vec.getY() << " z: " << vec.getZ();
    return os;
}

std::istream &operator>>(std::istream &is, Vec3 &vec)
{
    is >> vec._x >> vec._y >> vec._z;
    return is;
}
