#pragma once
#include <iostream>
#include <cmath>
#ifndef VECTOR2_H
#define VECTOR2_H

struct Vector2 {
    float x = 0, y = 0;

    Vector2() : x(0), y(0) {}

    Vector2(float SetX, float SetY) : x(SetX), y(SetY) {}

    Vector2(const Vector2& otherVector) : x(otherVector.x), y(otherVector.y) {}

    Vector2 operator+(const Vector2& other) const {
        return Vector2(x + other.x, y + other.y);
    }

    Vector2& operator+=(const Vector2& other) {
        x += other.x;
        y += other.y;
        return *this;
    }
    Vector2 operator-(const Vector2& other) const {
        return Vector2(x - other.x, y - other.y);
    }

    Vector2& operator-=(const Vector2& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }
    Vector2 operator/(float scalar) const {
        // Уникайте ділення на нуль, перевірте перед діленням
        if (scalar != 0.0f) {
            return Vector2(x / scalar, y / scalar);
        }
        else {
            std::cerr << "Error: Division by zero!" << std::endl;
            // Повернення вектору, щоб уникнути непередбачуваного стану
            return *this;
        }
    }

    Vector2& operator/=(float scalar) {
        // Уникайте ділення на нуль, перевірте перед діленням
        if (scalar != 0.0f) {
            x /= scalar;
            y /= scalar;
        }
        else {
            std::cerr << "Error: Division by zero!" << std::endl;
        }
        return *this;
    }

    // Додаткові операції

    Vector2 operator*(float scalar) const {
        return Vector2(x * scalar, y * scalar);
    }

    Vector2& operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    bool operator==(const Vector2& other) const {
        return (x == other.x) && (y == other.y);
    }

    bool operator!=(const Vector2& other) const {
        return !(*this == other);
    }

    float Length() const {
        return std::sqrt(x * x + y * y);
    }

    Vector2 Normalize() const {
        float length = Length();
        if (length != 0.0f) {
            return *this / length;
        }
        else {
            std::cerr << "Error: Normalizing a zero-length vector!" << std::endl;
            return *this;
        }
    }
};


#endif // VECTOR2_H
