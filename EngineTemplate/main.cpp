
#include <stdio.h>
#include <iostream>
#include <math.h>

#include "Engine.hpp"
#include "Time.hpp"
#include "Vector2f.hpp"

int main(int, char**) {
    
    Engine::InitSDL();
    SDL_Color clearColor = {255,255,255,255};
    
    Vector2f pos = Vector2f(0,100);
    
    
    while (Engine::IsRunning()) {
        Time::Count();
        
        Engine::HandleEvents();
        Engine::ClearScreen(clearColor);
        
        Engine::SetEngineDrawColor(255, 0, 0, 255);
        Engine::DrawRectangle(pos.x, pos.y, 150, 150);
        
        pos.x += 1000 * Time::DeltaTime();
        if (pos.x > Engine::WINDOW_WIDTH) pos.x = 0;
                
        Engine::Render();
    }
    
    Engine::CleanupSDL();
    
    return 0;
}
