//
//  UiTextWithValue.cpp
//  EngineTemplate
//
//  Created by Gabriele Padovani on 25/12/21.
//

#include "UiTextWithValue.hpp"

UiTextWithValue::UiTextWithValue(const std::string& label, float* v){
    this->label = label;
    this->value = v;
    
    this->w = 400;
    this->h = 50;
    labelTexture = Engine::LoadTextureFromText(label.c_str() + std::to_string(*value));

}

UiTextWithValue::~UiTextWithValue(){
    Engine::DeleteTexture(labelTexture);
}

void UiTextWithValue::Update(int offsetX, int offsetY) {
    Engine::DeleteTexture(labelTexture); 
    labelTexture = Engine::LoadTextureFromText(label.c_str() + std::string(" ") + std::to_string(*value));
}

void UiTextWithValue::Draw(int offsetX, int offsetY){
    int labelWidth = textLetterSize * (int)(label.length() + std::to_string(*value).length() + 2);
    Engine::RenderTexture(labelTexture, offsetX, offsetY, labelWidth, h);
}
