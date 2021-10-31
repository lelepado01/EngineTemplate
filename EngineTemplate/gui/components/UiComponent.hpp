//
//  UiComponent.hpp
//  EngineTemplate
//
//  Created by Gabriele Padovani on 29/10/21.
//

#ifndef UiComponent_hpp
#define UiComponent_hpp

class UiComponent {
protected:
    std::string label; 
    void* content;
    int w, h;
    
public:    
    virtual void Update(int offsetX, int offsetY){
        std::cout << "Virtual Method Update\n";
    };
    virtual void Draw(int offsetX, int offsetY){
        std::cout << "Virtual Method Draw\n";
    };
    
    inline int GetHeight() { return h; };
};

#endif /* UiComponent_hpp */
