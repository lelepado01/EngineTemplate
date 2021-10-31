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
}

IntSlider::~IntSlider(){
    
}

void IntSlider::Draw(){
    
}

void IntSlider::Update(){
    
}
