//
//  UiComponent.h
//  EngineTemplate
//
//  Created by Gabriele Padovani on 29/10/21.
//

#ifndef UiComponent_h
#define UiComponent_h

#include <stdio.h>
#include <string>
#include <iostream>

#include "MathCommon.h"

enum ComponentType{
    EmptyType,
    CheckboxType,
    SliderType,
    TextType,
    TextWithValueType
};

class UiComponent {
protected:
    std::string label;
    void* content;
    int w, h;
    
    SDL_Texture* labelTexture;
    
    const int textPadding = 15;
    const int textLetterSize = 12; 
    
public:
    
    virtual void Update(int offsetX, int offsetY){
        std::cout << "Virtual Method Update\n";
    };
    
    virtual void Draw(int offsetX, int offsetY){
        std::cout << "Virtual Method Draw\n";
    };

    inline int GetWidth() const { return w + (int)label.length() * 20; };
    inline int GetHeight() const { return h; };
    
    virtual inline ComponentType GetType(){ return ComponentType::EmptyType; }; 
};

#endif /* UiComponent_h */
