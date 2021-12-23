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
    const static int WidgetPadding = 15;
    const static int WidgetBorder = 2;
    const static int ResizeTriangleSize = 20;
    
    bool moveable;
    bool resizeable; 
    
    int x, y, w, h;
    int componentIndex = 0;
    
    SDL_Texture* labelTexture; 
    
    UiComponent* components[10];
    
    std::optional<SDL_Point> mouseGrab = {};
    
    bool isBeingGrabbed(){ return mouseGrab.has_value(); }; 
};

#endif /* Widget_hpp */
