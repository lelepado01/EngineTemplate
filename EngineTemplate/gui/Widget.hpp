//
//  Widget.hpp
//  EngineTemplate
//
//  Created by Gabriele Padovani on 30/10/21.
//

#ifndef Widget_hpp
#define Widget_hpp

#include <stdio.h>
#include <optional>

#include "UiComponent.hpp"


struct Widget {
    int x, y, w, h;
    int componentIndex = 0;
    SDL_Texture* labelTexture; 
    
    UiComponent* components[10];
    
    std::optional<SDL_Point> mouseGrab = {};
};

#endif /* Widget_hpp */
