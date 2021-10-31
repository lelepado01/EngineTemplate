//
//  Checkbox.hpp
//  EngineTemplate
//
//  Created by Gabriele Padovani on 29/10/21.
//

#ifndef Checkbox_hpp
#define Checkbox_hpp

#include <stdio.h>

#include "Engine.hpp"
#include "UiComponent.hpp"

class Checkbox : public UiComponent {
private:
    SDL_Texture* labelTexture;

protected:
    bool* content;
        
public:
    Checkbox(std::string label, bool* c, int x, int y);
    ~Checkbox();
    
    void Update() override;
    void Draw(int offsetX, int offsetY) override;
};

#endif /* Checkbox_hpp */