
#ifndef _VECTOR_2_HPP
#define _VECTOR_2_HPP

namespace smash
{
    struct Vector2
    {
        float x, y;

        // Constructors
        Vector2();
        Vector2(float w);
        Vector2(float x, float y);

        // Setters
        void set(float xValue, float yValue);

        // Magnitude and normalization
        float length() const;
        float lengthSquared() const;
        Vector2& normalize();
        Vector2 normalized() const;

        // Distance
        float distance(const Vector2& v) const;
        float distanceSquared(const Vector2& v) const;

        // Dot and cross product
        float dot(const Vector2& v) const;
        float cross(const Vector2& v) const;

        // Utility functions
        Vector2& clampMagnitude(float maxLength);
        Vector2 clampedMagnitude(float maxLength) const;
        float angle(const Vector2& v) const;
        float signedAngle(const Vector2& v) const;
        Vector2 perpendicular() const;
        Vector2 reflect(const Vector2& normal) const;

        // Operators
        Vector2& operator=(const Vector2& v);
        Vector2 operator-() const;
        bool operator==(const Vector2& v) const;
        bool operator!=(const Vector2& v) const;
        Vector2 operator+(const Vector2& v) const;
        Vector2 operator-(const Vector2& v) const;
        Vector2 operator*(float scalar) const;
        Vector2 operator/(float scalar) const;
        Vector2& operator+=(const Vector2& v);
        Vector2& operator-=(const Vector2& v);
        Vector2& operator*=(float scalar);
        Vector2& operator/=(float scalar);

        // Static utility functions
        static Vector2 zero();
        static Vector2 one();
        static Vector2 up();
        static Vector2 down();
        static Vector2 left();
        static Vector2 right();
    };
    // Additional non member operators
    Vector2 operator*(float scalar, const Vector2& v);
}

#endif