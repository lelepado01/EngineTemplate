//
//  IntSlider.hpp
//  EngineTemplate
//
//  Created by Gabriele Padovani on 30/10/21.
//

#ifndef IntSlider_hpp
#define IntSlider_hpp

#include <stdio.h>

#include "Engine.hpp"
#include "UiComponent.hpp"

class IntSlider : public UiComponent {
protected:
    int* content;
    
    int min;
    int max;
    
    const int sliderPadding = 5; 
    
    SDL_Texture* valueTexture; 
    
public:
    IntSlider(std::string label, int* c, int min, int max);
    ~IntSlider();
    
    void Update(int offsetX, int offsetY) override;
    void Draw(int offsetX, int offsetY) override;
};


#endif /* IntSlider_hpp */
