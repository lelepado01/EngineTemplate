//
//  FloatSlider.hpp
//  EngineTemplate
//
//  Created by Gabriele Padovani on 30/10/21.
//

#ifndef FloatSlider_hpp
#define FloatSlider_hpp

#include <stdio.h>

#include "Engine.hpp"
#include "UiComponent.hpp"

class FloatSlider : public UiComponent {
protected:
    float* content;
    
    float min;
    float max;
    
    const int sliderPadding = 5;

    SDL_Texture* valueTexture;

public:
    FloatSlider(std::string label, float* c, float min, float max);
    ~FloatSlider();
    
    void Update(int offsetX, int offsetY) override;
    void Draw(int offsetX, int offsetY) override;
};


#endif /* FloatSlider_hpp */
