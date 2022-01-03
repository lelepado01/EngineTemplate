//
//  MathCommon.h
//  EngineTemplate
//
//  Created by Gabriele Padovani on 31/10/21.
//

#ifndef MathCommon_h
#define MathCommon_h

#include <SDL.h>

class MathCommon {    
public:
    static bool RectangleContainsPoint(const SDL_Rect& rect, const SDL_Point& point){
        return point.x < rect.x + rect.w && point.x > rect.x && point.y < rect.y + rect.h && point.y > rect.y;
    }
};

#endif /* MathCommon_h */
