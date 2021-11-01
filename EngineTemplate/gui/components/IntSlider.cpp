//
//  IntSlider.cpp
//  EngineTemplate
//
//  Created by Gabriele Padovani on 30/10/21.
//

#include "IntSlider.hpp"

IntSlider::IntSlider(std::string label, int* v, int min, int max){
    this->label = label; 
    this->content = v;
    this->min = min;
    this->max = max;
    
    this->w = 300;
    this->h = 50;
    
    this->labelTexture = Engine::LoadTextureFromText(label.c_str());
    this->valueTexture = Engine::LoadTextureFromText(std::to_string(*content).c_str());
}

IntSlider::~IntSlider(){
    Engine::DeleteTexture(labelTexture);
    Engine::DeleteTexture(valueTexture);
    delete &label;
}

void IntSlider::Draw(int offsetX, int offsetY){
    int labelWidth = textLetterSize * (int)label.length();
    Engine::RenderTexture(labelTexture, offsetX, offsetY, labelWidth, h);
    Engine::RenderTexture(valueTexture, offsetX + labelWidth + textPadding, offsetY, textLetterSize * (int)std::to_string(*(content)).length(), h);
    
    Engine::SetEngineDrawColor(50, 50, 50, 255);
    Engine::FillRectangle(offsetX, offsetY + h + sliderPadding, w, h / 2);
    
    int xstart = offsetX + w * (*content) / (max - min);
    Engine::SetEngineDrawColor(255, 255, 255, 255);
    Engine::FillRectangle(xstart, offsetY + h + sliderPadding, 30, h / 2);

}

void IntSlider::Update(int offsetX, int offsetY){
    
}
