//
//  Checkbox.cpp
//  EngineTemplate
//
//  Created by Gabriele Padovani on 29/10/21.
//

#include "Checkbox.hpp"

Checkbox::Checkbox(std::string label, bool* c) {
    this->label = label;
    this->content = c;
    
    this->w = 50;
    this->h = 50;
    
    this->labelTexture = Engine::LoadTextureFromText(label.c_str());
}

Checkbox::~Checkbox(){

}

void Checkbox::Update(int offsetX, int offsetY){
    if (!mouseHasClickedAlready && Engine::MouseLeftKeyIsPressed()){
        mouseHasClickedAlready = true;
        SDL_Point mouse = Engine::GetMousePosition();
        
        if (mouse.x < offsetX + w && mouse.x > offsetX && mouse.y < offsetY + h && mouse.y > offsetY){
            *content = !(*content);
        }
    }
    if (!Engine::MouseLeftKeyIsPressed()){
        mouseHasClickedAlready = false;
    }
}

void Checkbox::Draw(int offsetX, int offsetY){
    
    Engine::SetEngineDrawColor(255, 255, 255, 255);
    Engine::DrawRectangle(offsetX, offsetY, 50, 50);
    
    if (*this->content) {
        Engine::FillRectangle(offsetX+5, offsetY+5, 40, 40);
    }
    
    Engine::RenderTexture(labelTexture, offsetX + w + 15, offsetY, 100, 50);

}
