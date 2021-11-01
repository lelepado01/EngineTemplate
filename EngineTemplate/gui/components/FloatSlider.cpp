//
//  FloatSlider.cpp
//  EngineTemplate
//
//  Created by Gabriele Padovani on 30/10/21.
//

#include "FloatSlider.hpp"

FloatSlider::FloatSlider(std::string label, float* v, float min, float max){
    this->label = label; 
    this->content = v;
    this->min = min; 
    this->max = max;
    
    this->w = 400;
    this->h = 50;
    
    this->labelTexture = Engine::LoadTextureFromText(label.c_str());
    this->valueTexture = Engine::LoadTextureFromText(std::to_string(*content).c_str()); 
}

FloatSlider::~FloatSlider(){
    Engine::DeleteTexture(labelTexture);
    Engine::DeleteTexture(valueTexture);
    delete &label;
}

void FloatSlider::Draw(int offsetX, int offsetY){
    
    int labelWidth = textLetterSize * (int)label.length();
    Engine::RenderTexture(labelTexture, offsetX, offsetY, labelWidth, h);
    Engine::RenderTexture(valueTexture, offsetX + labelWidth + textPadding, offsetY, textLetterSize * (int)std::to_string(*(content)).length(), h);
    
    Engine::SetEngineDrawColor(50, 50, 50, 255);
    Engine::FillRectangle(offsetX, offsetY + h + sliderPadding, w, h / 2);
    
    int xstart = offsetX + w * (*content) / (max - min);
    Engine::SetEngineDrawColor(255, 255, 255, 255);
    Engine::FillRectangle(xstart, offsetY + h + sliderPadding, 30, h / 2);
}

void FloatSlider::Update(int offsetX, int offsetY){
    
}
