//
//  Checkbox.cpp
//  EngineTemplate
//
//  Created by Gabriele Padovani on 29/10/21.
//

#include "Checkbox.hpp"

Checkbox::Checkbox(std::string label, bool* c, int x, int y) {
    this->label = label;
    this->content = c;
    this->w = 50;
    this->h = 50;
    this->x = x;
    this->y = y;
    
    this->labelTexture = Engine::LoadTextureFromText(label.c_str());
}

Checkbox::~Checkbox(){
    
}

void Checkbox::Update(){
    if (Engine::MouseLeftKeyIsPressed()){
        SDL_Point mouse = Engine::GetMousePosition();
        
        if (mouse.x < x + w && mouse.x > x && mouse.y < y + h && mouse.y > y){
            *content = !content; 
        }
    }
}

void Checkbox::Draw(int offsetX, int offsetY){
    
    Engine::SetEngineDrawColor(255, 255, 255, 255);
    Engine::DrawRectangle(offsetX, offsetY, 50, 50);
    
    if (*content) {
        Engine::FillRectangle(offsetX+5, offsetY+5, 40, 40);
    }
    
    Engine::RenderTexture(labelTexture, offsetX + w + 15, offsetY, 100, 50);

}
