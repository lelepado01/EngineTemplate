//
//  Slider.h
//  EngineTemplate
//
//  Created by Gabriele Padovani on 02/11/21.
//

#ifndef Slider_h
#define Slider_h

#include <stdio.h>
#include <optional>

#include "UiComponent.h"

class Slider : public UiComponent {
protected:
    
    float min;
    float max;
    
    const int sliderPadding = 5;
    const int sliderHandleWidth = 30;
    const int sliderHeight = 50;

    SDL_Texture* valueTexture;
    
    std::optional<float> sliderMouseGrab;
        
public:
    void Update(int offsetX, int offsetY) override {};
    void Draw(int offsetX, int offsetY) override {};
    
    inline bool SliderIsBeingGrabbed() { return sliderMouseGrab.has_value(); };
    
    inline ComponentType GetType() override { return ComponentType::SliderType; };
};

#endif /* Slider_h */
