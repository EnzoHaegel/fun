/*
** EPITECH PROJECT, 2022
** fun
** File description:
** Vec3
*/

#ifndef VEC3_HPP_
#define VEC3_HPP_

#include <iostream>

class Vec3 {
    public:
        Vec3(float x, float y, float z);
        ~Vec3();
        float getX() const;
        float getY() const;
        float getZ() const;
        Vec3 get() const;

        void setX(float x);
        void setY(float y);
        void setZ(float z);
        void set(const Vec3 &vec);

        // overload operators
        Vec3 operator+(const Vec3 &vec) const;
        Vec3 operator-(const Vec3 &vec) const;
        Vec3 operator*(const Vec3 &vec) const;
        Vec3 operator/(const Vec3 &vec) const;
        Vec3 operator+(float val) const;
        Vec3 operator-(float val) const;
        Vec3 operator*(float val) const;
        Vec3 operator/(float val) const;

        // overload stream operators
        friend std::ostream &operator<<(std::ostream &os, const Vec3 &vec);
        friend std::istream &operator>>(std::istream &is, Vec3 &vec);

    protected:
    private:
        float _x;
        float _y;
        float _z;

};

#endif /* !VEC3_HPP_ */
