
#include <stdio.h>
#include <iostream>

#include "Gui.hpp"
#include "Engine.hpp"
#include "Time.hpp"

int main(int, char**) {
    
    Engine::InitSDL();
    SDL_Color clearColor = {255,255,255,255};
        
    bool varbool1 = false;
    bool varbool2 = true;
    float range1 = 75;
    
    while (Engine::IsRunning()) {
        Time::Count();
        
        Gui::NewFrame();
        
        Engine::HandleEvents();
        Engine::ClearScreen(clearColor);
        
        Gui::Begin("Window 2", 100,600, true, true);
        
        Gui::CreateCheckbox("Checkbox 1", &varbool1);
        Gui::CreateFloatSlider("Slider 1", &range1, 30, 80);

        Gui::End();

        Gui::Begin("Window 1", 100,100);

        Gui::CreateCheckbox("Checkbox 2", &varbool2);
        Gui::CreateCheckbox("Checkbox 3", &varbool2);
        Gui::CreateText("Ciao mamma");

        Gui::End();


        Gui::Update();
        Gui::Draw();

        Engine::Render();
    }
    
    Engine::CleanupSDL();
    
    return 0;
}
