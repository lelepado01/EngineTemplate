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
    int x, y, w, h;
    
public:    
    virtual void Update(){};
    virtual void Draw(int offsetX, int offsetY){
        std::cout << "Virtual Method\n";
    };
    
    inline int GetHeight() { return h; };
};

#endif /* UiComponent_hpp */
