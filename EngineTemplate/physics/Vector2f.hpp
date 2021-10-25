//
//  Vector2f.hpp
//  ShooterSDL
//
//  Created by Gabriele Padovani on 30/08/21.
//

#ifndef Vector2f_hpp
#define Vector2f_hpp

#include <stdio.h>
#include <math.h>

class Vector2f {
public:
    float x, y;
    
    Vector2f();
    Vector2f(float x, float y);
    
    static Vector2f Random(int r);
    
    void Add(Vector2f v);
    void Sub(Vector2f v);
    void Mult(Vector2f v);
    void Mult(float f);
    void Div(Vector2f v);
    void Div(float f);
    
    static float Cross(Vector2f v1, Vector2f v2);
    static float Distance(Vector2f v1, Vector2f v2);
    
    void Normalize();
    void Rotate(int angle);
    int GetAngle();
    bool operator !=(Vector2f v);
    bool operator ==(Vector2f v);
};

#endif /* Vector2f_hpp */
