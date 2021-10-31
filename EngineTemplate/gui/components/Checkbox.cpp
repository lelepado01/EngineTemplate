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
    Engine::DeleteTexture(labelTexture);
    delete content;
}

void Checkbox::Update(int offsetX, int offsetY){
    if (Engine::MouseLeftKeyIsPressed()){
        if (!mouseHasClickedAlready){
            mouseHasClickedAlready = true;
            SDL_Point mouse = Engine::GetMousePosition();
            
            if (MathCommon::RectangleContainsPoint(new SDL_Rect{offsetX, offsetY, w, h}, &mouse)){
                *content = !(*content);
            }
        }
    } else {
        mouseHasClickedAlready = false;
    }
}

void Checkbox::Draw(int offsetX, int offsetY){
    
    Engine::SetEngineDrawColor(255, 255, 255, 255);
    Engine::DrawRectangle(offsetX, offsetY, w, h);
    
    if (*this->content) {
        Engine::FillRectangle(offsetX + checkboxFillPadding,
                              offsetY + checkboxFillPadding,
                              w - 2*checkboxFillPadding,
                              h - 2*checkboxFillPadding);
    }
    
    Engine::RenderTexture(labelTexture, offsetX + w + textPadding, offsetY, textLetterSize * (int)label.length(), h);

}
