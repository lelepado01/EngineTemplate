//
//  Gui.cpp
//  EngineTemplate
//
//  Created by Gabriele Padovani on 29/10/21.
//

#include "Gui.hpp"

int Gui::widgetIndex = 0;
int Gui::lastFrameWidgetsCount = 0;
bool Gui::widgetHasMovedThisFrame = false;

Widget Gui::tempWidget = Widget{};
Widget Gui::widgets[10];

const SDL_Color windowColor = SDL_Color{100, 100, 255, 255};
const SDL_Color topBarColor = SDL_Color{50, 50, 50, 255};
const int topBarHeight = 50;


bool Gui::mouseOnTopBar(Widget* widget, int x, int y){
    return x < widget->x + widget->w && x > widget->x && y < widget->y + widget->h && y > widget->y;
}


void Gui::Begin(std::string label, int x, int y, int width, int height){
    tempWidget.x = x;
    tempWidget.y = y;
    tempWidget.w = width;
    tempWidget.h = height;
    
    tempWidget.labelTexture = Engine::LoadTextureFromText(label.c_str());
    
    tempWidget.mouseGrab = {};
}

void Gui::End(){
    if (widgetIndex + 1 > lastFrameWidgetsCount) {
        widgets[widgetIndex] = tempWidget;
    }
    widgetIndex += 1;
    tempWidget = Widget{};
}


void Gui::Update(){
    
    widgetHasMovedThisFrame = false;
    for (int i = 0; i < widgetIndex; i++) {
        if (widgets[i].mouseGrab.has_value()){
            widgetCheckForMouseDrag(&widgets[i]);
            break;
        }
    }
        
    for (int i = 0; i < widgetIndex; i++) {
        if (!widgetHasMovedThisFrame) widgetCheckForMouseDrag(&widgets[i]);
        
        int componentsOffsetY = 0;
        for (int j = 0; j < widgets[i].componentIndex; j++) {
            int offsetX = widgets[i].x + 15;
            int offsetY = widgets[i].y + 15 + topBarHeight + componentsOffsetY + 15 * j;

            widgets[i].components[j]->Update(offsetX, offsetY);

            componentsOffsetY += widgets[i].components[j]->GetHeight();
        }
    }
}


void Gui::widgetCheckForMouseDrag(Widget* widget){
    if (Engine::MouseLeftKeyIsPressed()){
        SDL_Point mouse = Engine::GetMousePosition();
        
        if (mouseOnTopBar(widget, mouse.x, mouse.y) || widget->mouseGrab.has_value()) {
            
            if (widget->mouseGrab.has_value()){
                widget->x = mouse.x - widget->mouseGrab.value().x;
                widget->y = mouse.y - widget->mouseGrab.value().y;
                widgetHasMovedThisFrame = true;
            }
            
            widget->mouseGrab = SDL_Point{ mouse.x - widget->x , mouse.y - widget->y };
        }
    } else {
        widget->mouseGrab = {};
    }

}


void Gui::Draw(){
    for (int i = 0; i < widgetIndex; i++) {
        
        Engine::SetEngineDrawColor(topBarColor.r, topBarColor.g, topBarColor.b, topBarColor.a);
        Engine::FillRectangle(widgets[i].x, widgets[i].y, widgets[i].w, topBarHeight);
        Engine::SetEngineDrawColor(windowColor.r, windowColor.g, windowColor.b, windowColor.a);
        Engine::FillRectangle(widgets[i].x, widgets[i].y + topBarHeight, widgets[i].w, widgets[i].h);
        Engine::RenderTexture(widgets[i].labelTexture, widgets[i].x, widgets[i].y, widgets[i].w, topBarHeight );
        
        int componentsOffsetY = 0;
        for (int j = 0; j < widgets[i].componentIndex; j++) {
            int offsetX = widgets[i].x + 15;
            int offsetY = widgets[i].y + 15 + topBarHeight + componentsOffsetY + 15 * j;
            widgets[i].components[j]->Draw(offsetX, offsetY);
            
            componentsOffsetY += widgets[i].components[j]->GetHeight();
        }
    }
}

void Gui::NewFrame(){
    lastFrameWidgetsCount = widgetIndex;
    widgetIndex = 0;
}

void Gui::CreateCheckbox(std::string label, bool *v){
    UiComponent* c = new Checkbox(label, v);
    tempWidget.components[tempWidget.componentIndex] = c;
    tempWidget.componentIndex += 1;
}


void Gui::CreateFloatSlider(std::string label, float *v, float min, float max){
    UiComponent* c = new FloatSlider(label, v, min, max);
    tempWidget.components[tempWidget.componentIndex] = c;
    tempWidget.componentIndex += 1;
}


void Gui::CreateIntSlider(std::string label, int *v, int min, int max){
    UiComponent* c = new IntSlider(label, v, min, max);
    tempWidget.components[tempWidget.componentIndex] = c;
    tempWidget.componentIndex += 1;
}
