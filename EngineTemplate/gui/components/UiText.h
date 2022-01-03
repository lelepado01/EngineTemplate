//
//  UiText.h
//  EngineTemplate
//
//  Created by Gabriele Padovani on 21/12/21.
//

#ifndef UiText_h
#define UiText_h

#include <stdio.h>
#include <string>

#include "UiComponent.h"
#include "../../engine/Engine.h"

class UiText : public UiComponent {
protected: 
    
public:
    UiText(const std::string& label);
    ~UiText();
    
    void Update(int offsetX, int offsetY) override {};
    void Draw(int offsetX, int offsetY) override;

    inline ComponentType GetType() override { return ComponentType::TextType; };
};

#endif /* UiText_h */
