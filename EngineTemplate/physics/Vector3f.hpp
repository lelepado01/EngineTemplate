//
//  Vector3f.hpp
//  IsometricEngine
//
//  Created by Gabriele Padovani on 08/10/21.
//

#ifndef Vector3f_hpp
#define Vector3f_hpp

#include <stdio.h>
#include <math.h>


class Vector3f {
public:
    float x, y, z;
    
    Vector3f();
    Vector3f(float x, float y, float z);
    
    static Vector3f Random(int r);
    
    void Add(Vector3f v);
    void Sub(Vector3f v);
    void Mult(Vector3f v);
    void Mult(float f);
    void Div(Vector3f v);
    void Div(float f);
    
    static float Cross(Vector3f v1, Vector3f v2);
    static float Distance(Vector3f v1, Vector3f v2);
    
    void Normalize();
    void Rotate(int angle);
    int GetAngle();
    bool operator !=(Vector3f v);
    bool operator ==(Vector3f v);
};



#endif /* Vector3f_hpp */
