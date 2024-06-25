#include <smash.h>

namespace smash
{
    // Constructors
    Vector2::Vector2() : x(0), y(0) {}
    Vector2::Vector2(float w) : x(w), y(w) {}
    Vector2::Vector2(float x, float y) : x(x), y(y) {}

    // Setters
    void Vector2::set(float xValue, float yValue)
    {
        x = xValue;
        y = yValue;
    }

    // Magnitude and normalization
    float Vector2::length() const
    {
        return std::sqrt(x * x + y * y);
    }

    float Vector2::lengthSquared() const
    {
        return x * x + y * y;
    }

    Vector2& Vector2::normalize()
    {
        float len = length();
        if (len > 0)
        {
            x /= len;
            y /= len;
        }
        return *this;
    }

    Vector2 Vector2::normalized() const
    {
        float len = length();
        if (len > 0)
        {
            return Vector2(x / len, y / len);
        }
        return Vector2(0, 0);
    }

    // Distance
    float Vector2::distance(const Vector2& v) const
    {
        return std::sqrt(distanceSquared(v));
    }

    float Vector2::distanceSquared(const Vector2& v) const
    {
        float dx = x - v.x;
        float dy = y - v.y;
        return dx * dx + dy * dy;
    }

    // Dot and cross product
    float Vector2::dot(const Vector2& v) const
    {
        return x * v.x + y * v.y;
    }

    float Vector2::cross(const Vector2& v) const
    {
        return x * v.y - y * v.x;
    }

    // Utility functions
    Vector2& Vector2::clampMagnitude(float maxLength)
    {
        if (lengthSquared() > maxLength * maxLength)
        {
            normalize();
            x *= maxLength;
            y *= maxLength;
        }
        return *this;
    }

    Vector2 Vector2::clampedMagnitude(float maxLength) const
    {
        if (lengthSquared() > maxLength * maxLength)
        {
            Vector2 result = normalized();
            result.x *= maxLength;
            result.y *= maxLength;
            return result;
        }
        return *this;
    }

    float Vector2::angle(const Vector2& v) const
    {
        float dotProduct = dot(v);
        float lengths = length() * v.length();
        return std::acos(dotProduct / lengths) * (180.0f / 3.14159265358979323846f);
    }

    float Vector2::signedAngle(const Vector2& v) const
    {
        float angle = this->angle(v);
        float crossProduct = this->cross(v);
        return crossProduct < 0 ? -angle : angle;
    }

    Vector2 Vector2::perpendicular() const
    {
        return Vector2(-y, x);
    }

    Vector2 Vector2::reflect(const Vector2& normal) const
    {
        return *this - 2 * dot(normal) * normal;
    }

    // Operators
    Vector2& Vector2::operator=(const Vector2& v)
    {
        x = v.x;
        y = v.y;
        return *this;
    }

    Vector2 Vector2::operator-() const
    {
        return Vector2(-x, -y);
    }

    bool Vector2::operator==(const Vector2& v) const
    {
        return x == v.x && y == v.y;
    }

    bool Vector2::operator!=(const Vector2& v) const
    {
        return !(*this == v);
    }

    Vector2 Vector2::operator+(const Vector2& v) const
    {
        return Vector2(x + v.x, y + v.y);
    }

    Vector2 Vector2::operator-(const Vector2& v) const
    {
        return Vector2(x - v.x, y - v.y);
    }

    Vector2 Vector2::operator*(float scalar) const
    {
        return Vector2(x * scalar, y * scalar);
    }

    Vector2 Vector2::operator/(float scalar) const
    {
        return Vector2(x / scalar, y / scalar);
    }

    Vector2& Vector2::operator+=(const Vector2& v)
    {
        x += v.x;
        y += v.y;
        return *this;
    }

    Vector2& Vector2::operator-=(const Vector2& v)
    {
        x -= v.x;
        y -= v.y;
        return *this;
    }

    Vector2& Vector2::operator*=(float scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Vector2& Vector2::operator/=(float scalar)
    {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    // Static utility functions
    Vector2 Vector2::zero()
    {
        return Vector2(0, 0);
    }

    Vector2 Vector2::one()
    {
        return Vector2(1, 1);
    }

    Vector2 Vector2::up()
    {
        return Vector2(0, 1);
    }

    Vector2 Vector2::down()
    {
        return Vector2(0, -1);
    }

    Vector2 Vector2::left()
    {
        return Vector2(-1, 0);
    }

    Vector2 Vector2::right()
    {
        return Vector2(1, 0);
    }

    Vector2 operator*(float scalar, const Vector2& v)
    {
        return Vector2(v.x * scalar, v.y * scalar);
    }

}