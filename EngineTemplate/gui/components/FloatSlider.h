//
//  FloatSlider.h
//  EngineTemplate
//
//  Created by Gabriele Padovani on 30/10/21.
//

#ifndef FloatSlider_h
#define FloatSlider_h

#include <stdio.h>

#include "Engine.h"
#include "Slider.h"
#include "UiComponent.h"

class FloatSlider : public Slider {
private:
    float* content;
    
    inline float getPercentageInRange() { return ((float)*(content) - min) / (max - min); };
    inline float getValueOfSliderFromPercentage(float perc) { return perc * (max - min) + min; };

    std::string getValueAsFormattedString();

    bool updateSliderValue(int newX, int offsetX);
    
public:
    FloatSlider(const std::string& label, float* c, float min, float max);
    ~FloatSlider();
    
    void Update(int offsetX, int offsetY) override;
    void Draw(int offsetX, int offsetY) override;
};


#endif /* FloatSlider_h */
