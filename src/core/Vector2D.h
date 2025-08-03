//
// Created by halma on 2025. 08. 03.
//

#ifndef VECTOR2D_H
#define VECTOR2D_H

struct Vector2D {
    float x;
    float y;
    explicit Vector2D(const float x = 0, const float y = 0) : x(x), y(y) {}
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }
    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }
    Vector2D operator*(const float scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }
    Vector2D operator/(const float scalar) const {
        if (scalar != 0) {
            return Vector2D(x / scalar, y / scalar);
        }
        return Vector2D(0, 0);
    }
    bool operator==(const Vector2D& other) const {
        return (x == other.x && y == other.y);
    }
    bool operator!=(const Vector2D& other) const {
        return !(*this == other);
    }
};

#endif //VECTOR2D_H
