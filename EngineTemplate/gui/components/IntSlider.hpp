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
    
public:
    IntSlider(std::string label, int* c, int min, int max);
    ~IntSlider();
    
    void Update();
    void Draw();
};


#endif /* IntSlider_hpp */
