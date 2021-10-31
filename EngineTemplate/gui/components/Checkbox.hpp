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
    bool mouseHasClickedAlready = false;
    
    const int checkboxFillPadding = 5;

protected:
    bool* content;
        
public:
    Checkbox(std::string label, bool* c);
    ~Checkbox();
    
    void Update(int offsetX, int offsetY) override;
    void Draw(int offsetX, int offsetY) override;
};

#endif /* Checkbox_hpp */
