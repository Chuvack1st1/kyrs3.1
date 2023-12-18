#pragma once

struct Vector2 {
    float x = 0, y = 0;
    Vector2() : x(0), y(0) {}
    Vector2(float SetX, float SetY) : x(SetX), y(SetY) {}
    Vector2(const Vector2& otherVector) : x(otherVector.x), y(otherVector.y) {}
    Vector2 operator+(const Vector2& other) const {
        return Vector2(x + other.x, y + other.y);
    }
    Vector2& operator += (const Vector2& other) {
        x += other.x;
        y += other.y;
        return *this;  // Возвращаем *this для поддержки цепочки операций (a += b += c)
    }
};
