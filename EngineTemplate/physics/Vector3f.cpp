//
//  Vector3f.cpp
//  IsometricEngine
//
//  Created by Gabriele Padovani on 08/10/21.
//

#include "Vector3f.hpp"

Vector3f::Vector3f(float x, float y, float z){
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3f::Vector3f(){
    x = 0;
    y = 0;
    z = 0;
}

Vector3f Vector3f::Random(int r){
    return Vector3f(rand() % r, rand() % r,rand() % r);
}

void Vector3f::Add(Vector3f v){
    this->x += v.x;
    this->y += v.y;
    this->z += v.z;
}

void Vector3f::Sub(Vector3f v){
    this->x -= v.x;
    this->y -= v.y;
    this->z -= v.z;
}

void Vector3f::Mult(Vector3f v){
    this->x *= v.x;
    this->y *= v.y;
    this->z *= v.z;
}

void Vector3f::Mult(float f){
    this->x *= f;
    this->y *= f;
    this->z *= f;
}

void Vector3f::Div(Vector3f v){
    this->x /= v.x;
    this->y /= v.y;
    this->z /= v.z;
}

void Vector3f::Div(float f){
    this->x /= f;
    this->y /= f;
    this->z /= f;
}

float Vector3f::Cross(Vector3f v1, Vector3f v2){
    return v1.x * v2.y - v1.y * v2.x;
}

void Vector3f::Normalize(){
    if (x == 0 && y == 0) return;
    
    if (x <= -1 || x <= 1 || y >= 1 || y <= -1 || z >= 1 || z <= -1){
    
        float sum = abs(x) + abs(y) + abs(z);
        x /= sum;
        y /= sum;
        z /= sum;
    }
}

void Vector3f::Rotate(int angle){
    float x2 = cos(angle) * x - sin(angle) * y;
    float y2 = cos(angle) * y + sin(angle) * x;
    x = x2;
    y = y2;
}

int Vector3f::GetAngle(){
    float angle = atan2(y, x);
    return (360+(int)round(180*angle / M_PI) - 30) % 360;
}

float Vector3f::Distance(Vector3f v1, Vector3f v2){
    float dx = v1.x - v2.x;
    float dy = v1.y - v2.y;
    
    return sqrt(abs(dx) * abs(dx) + abs(dy) * abs(dy));
}

bool Vector3f::operator !=(Vector3f v){
    return x != v.x || y != v.y || z != v.z;
}

bool Vector3f::operator ==(Vector3f v){
    return x == v.x && y == v.y && z == v.z;
}

