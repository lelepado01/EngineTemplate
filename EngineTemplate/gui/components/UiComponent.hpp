//
//  UiComponent.hpp
//  EngineTemplate
//
//  Created by Gabriele Padovani on 29/10/21.
//

#ifndef UiComponent_hpp
#define UiComponent_hpp

#include "math_common.hpp"

class UiComponent {
protected:
    std::string label; 
    void* content;
    int w, h;
    
    const int textPadding = 15;
    const int textLetterSize = 12; 
    
public:    
    virtual void Update(int offsetX, int offsetY){
        std::cout << "Virtual Method Update\n";
    };
    virtual void Draw(int offsetX, int offsetY){
        std::cout << "Virtual Method Draw\n";
    };
    
    inline int GetWidth() { return w + (int)label.length() * 20; };
    inline int GetHeight() { return h; };
};

#endif /* UiComponent_hpp */
