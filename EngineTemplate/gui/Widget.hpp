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
    int minWidth, minHeight;
    int componentIndex = 0;
    
    SDL_Texture* labelTexture; 
    
    std::vector<UiComponent*> components = std::vector<UiComponent*>(10);
    
    std::optional<SDL_Point> mouseMoveGrab = {};
    std::optional<SDL_Point> mouseResizeGrab = {};

    bool isBeingMoved(){ return mouseMoveGrab.has_value(); };
    bool isBeingResized(){ return mouseResizeGrab.has_value(); };
    bool isBeingInteractedWith(){
        for (int i = 0; i < componentIndex; i++) {
            if (components[i]->GetType() == ComponentType::SliderType){
                if (((Slider*)components[i])->SliderIsBeingGrabbed()) return true;
            }
        }
        return false;
    };
    
    void addComponent(UiComponent* component){
        components[componentIndex] = component;
        
        w = std::max(w, component->GetWidth());
        h += component->GetHeight();
        
        minWidth = w;
        minHeight = h;
        
        componentIndex += 1;
    }
};

#endif /* Widget_hpp */
