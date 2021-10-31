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
}

FloatSlider::~FloatSlider(){
    
}

void FloatSlider::Draw(){
    
}

void FloatSlider::Update(){
    
}
