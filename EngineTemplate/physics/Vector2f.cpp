//
//  Vector2f.cpp
//  ShooterSDL
//
//  Created by Gabriele Padovani on 30/08/21.
//

#include "Vector2f.hpp"

Vector2f::Vector2f(float x, float y){
    this->x = x;
    this->y = y;
}

Vector2f::Vector2f(){
    x = 0;
    y = 0;
}

Vector2f Vector2f::Random(int r){
    return Vector2f(rand() % r, rand() % r);
}

void Vector2f::Add(Vector2f v){
    this->x += v.x;
    this->y += v.y;
}

void Vector2f::Sub(Vector2f v){
    this->x -= v.x;
    this->y -= v.y;
}

void Vector2f::Mult(Vector2f v){
    this->x *= v.x;
    this->y *= v.y;
}

void Vector2f::Mult(float f){
    this->x *= f;
    this->y *= f;
}

void Vector2f::Div(Vector2f v){
    this->x /= v.x;
    this->y /= v.y;
}

void Vector2f::Div(float f){
    this->x /= f;
    this->y /= f;
}

float Vector2f::Cross(Vector2f v1, Vector2f v2){
    return v1.x * v2.y - v1.y * v2.x;
}

void Vector2f::Normalize(){
    if (x == 0 && y == 0) return;
    
    if (x <= -1 || x <= 1 || y >= 1 || y <= -1){
    
        float sum = abs(x) + abs(y);
        x /= sum;
        y /= sum;

    }
}

void Vector2f::Rotate(int angle){
    float x2 = cos(angle) * x - sin(angle) * y;
    float y2 = cos(angle) * y + sin(angle) * x;
    x = x2;
    y = y2; 
}

int Vector2f::GetAngle(){
    float angle = atan2(y, x);
    return (360+(int)round(180*angle / M_PI) - 30) % 360;
}

float Vector2f::Distance(Vector2f v1, Vector2f v2){
    float dx = v1.x - v2.x;
    float dy = v1.y - v2.y;
    
    return sqrt(abs(dx) * abs(dx) + abs(dy) * abs(dy));
}

bool Vector2f::operator !=(Vector2f v){
    return x != v.x || y != v.y;
}

bool Vector2f::operator ==(Vector2f v){
    return x == v.x && y == v.y;
}

