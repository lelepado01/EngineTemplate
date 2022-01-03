//
//  UiTextWithValue.h
//  EngineTemplate
//
//  Created by Gabriele Padovani on 25/12/21.
//

#ifndef UiTextWithValue_h
#define UiTextWithValue_h

#include <stdio.h>
#include <string>

#include "UiComponent.h"
#include "../../engine/Engine.h"

class UiTextWithValue : public UiComponent {
protected:
    float* value;
    
public:
    UiTextWithValue(const std::string& label, float* v);
    ~UiTextWithValue();
    
    void Update(int offsetX, int offsetY) override;
    void Draw(int offsetX, int offsetY) override;

    inline ComponentType GetType() override { return ComponentType::TextWithValueType; };
};

#endif /* UiTextWithValue_h */
