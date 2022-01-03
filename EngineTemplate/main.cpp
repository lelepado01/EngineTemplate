
#include <stdio.h>
#include <iostream>

#include "Gui.h"
#include "Engine.h"
#include "Time.h"

int main(int, char**) {
    
    Engine::InitSDL();
    SDL_Color clearColor = {255,255,255,255};
        
    bool varbool1 = false;
    bool varbool2 = true;
    float range1 = 75;
    float range2 = 75;

    float fps = 0;
    while (Engine::IsRunning()) {
        Time::Count();
        
        Gui::NewFrame();
        
        Engine::HandleEvents();
        Engine::ClearScreen(clearColor);
        
        Gui::Begin("Window 2", 100,600, true, true);
        
        Gui::CreateCheckbox("Checkbox 1", &varbool1);
        Gui::CreateFloatSlider("Slider 1", &range1, 30, 80);

        Gui::End();

        Gui::Begin("Window 1", 100,100, true, true);

        Gui::CreateCheckbox("Checkbox 2", &varbool2);
        Gui::CreateCheckbox("Checkbox 3", &varbool2);
        Gui::CreateFloatSlider("Slider 1", &range2, 30, 80);

        Gui::CreateText("Ciao mamma");
        fps = (int)Time::FPS();
        Gui::CreateTextWithValue("Ciao mamma", &fps);

        Gui::End();


        Gui::Update();
        Gui::Draw();

        Engine::Render();
    }
    
    Engine::CleanupSDL();
    
    return 0;
}
