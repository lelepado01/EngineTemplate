//
//  Checkbox.h
//  EngineTemplate
//
//  Created by Gabriele Padovani on 29/10/21.
//

#ifndef Checkbox_h
#define Checkbox_h

#include <stdio.h>

#include "Engine.h"
#include "UiComponent.h"

class Checkbox : public UiComponent {
private:
    bool mouseHasClickedAlready = false;
    
    const int checkboxFillPadding = 5;

protected:
    bool* content;
        
public:
    Checkbox(const std::string& label, bool* c);
    ~Checkbox();
    
    void Update(int offsetX, int offsetY) override;
    void Draw(int offsetX, int offsetY) override;
    
    inline ComponentType GetType() override { return ComponentType::CheckboxType; };
};

#endif /* Checkbox_h */
