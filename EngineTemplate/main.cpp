
#include <stdio.h>
#include <iostream>
#include <math.h>

#include "Gui.hpp"
#include "Engine.hpp"
#include "Time.hpp"
#include "Vector2f.hpp"

//#include "networking/netcommon/net_common.h"

int main(int, char**) {
    
    Engine::InitSDL();
    SDL_Color clearColor = {255,255,255,255};
    
    Vector2f pos = Vector2f(0,100);
    
    bool varbool1 = false;
    bool varbool2 = true;
    
    while (Engine::IsRunning()) {
        Time::Count();
        
        Gui::NewFrame();
        
        Engine::HandleEvents();
        Engine::ClearScreen(clearColor);
        
        Engine::SetEngineDrawColor(255, 0, 0, 255);
        Engine::DrawRectangle(pos.x, pos.y, 150, 150);

        pos.x += 1000 * Time::DeltaTime();
        if (pos.x > Engine::WINDOW_WIDTH) pos.x = 0;
        
        
        Gui::Begin("Window 1", 10,10);
        Gui::CreateCheckbox("Checkbox 1", &varbool1);
        Gui::CreateCheckbox("Checkbox 2", &varbool2);
        Gui::CreateCheckbox("Checkbox 3", &varbool2);
        Gui::End();
        
        Gui::Begin("Window 2", 100,600);
        
        Gui::End();


        Gui::Update();
        Gui::Draw(); 
        
        Engine::Render();
    }
    
    Engine::CleanupSDL();
    
    return 0;
}
