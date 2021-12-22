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


void Gui::Begin(const std::string& label, int x, int y){
    int initialWidgetHeight = 100;
    
    tempWidget.x = x;
    tempWidget.y = y;
    tempWidget.w = 2 * (Widget::WidgetPadding + initialWidgetHeight);
    tempWidget.h = initialWidgetHeight;
    
    if (!widgets[widgetIndex].labelTexture){
        tempWidget.labelTexture = Engine::LoadTextureFromText(label.c_str());
    }
    
    tempWidget.mouseGrab = {};
}

void Gui::End(){
    if (widgetIsNew()) {
        widgets[widgetIndex] = tempWidget;
    }
    
    widgetIndex += 1;

    tempWidget = {};
}


void Gui::Update(){
    
    bool sliderIsBeingDragged = false;
    for (int i = 0; i < widgetIndex; i++) {
        for (int j = 0; j < widgets[i].componentIndex; j++) {

            if (widgets[i].components[j]->IsSlider()){
                
                Slider* slider = (Slider*) widgets[i].components[j];
                if (slider->SliderIsBeingGrabbed()) {
                    sliderIsBeingDragged = true;
                    break;
                }
            }
        }
        if (sliderIsBeingDragged) break;
    }
    
    if(!sliderIsBeingDragged){
        widgetHasMovedThisFrame = false;
        for (int i = 0; i < widgetIndex; i++) {
            if (widgets[i].isBeingGrabbed()){
                widgetCheckForMouseDrag(widgets[i]);
                break;
            }
        }
    }
        
    for (int i = 0; i < widgetIndex; i++) {
        if (!sliderIsBeingDragged && !widgetHasMovedThisFrame) widgetCheckForMouseDrag(widgets[i]);
        
        int componentsOffsetY = 0;
        for (int j = 0; j < widgets[i].componentIndex; j++) {
            
            int offsetX = widgets[i].x + Widget::WidgetPadding;
            int offsetY = widgets[i].y + topBarHeight + componentsOffsetY + Widget::WidgetPadding * (j+1);
            widgets[i].components[j]->Update(offsetX, offsetY);

            componentsOffsetY += widgets[i].components[j]->GetHeight();
        }
    }
}


void Gui::widgetCheckForMouseDrag(Widget& widget){
    if (Engine::MouseLeftKeyIsPressed()){
        SDL_Point mouse = Engine::GetMousePosition();
        SDL_Rect widgetArea {widget.x, widget.y, widget.w, topBarHeight};
        
        if (MathCommon::RectangleContainsPoint(widgetArea, mouse) || widget.isBeingGrabbed()) {
            
            if (widget.isBeingGrabbed()){
                widget.x = mouse.x - widget.mouseGrab.value().x;
                widget.y = mouse.y - widget.mouseGrab.value().y;
                widgetHasMovedThisFrame = true;
            }
            
            widget.mouseGrab = SDL_Point{ mouse.x - widget.x , mouse.y - widget.y };
        }
    } else {
        widget.mouseGrab = {};
    }

}


void Gui::Draw(){
    for (int i = 0; i < widgetIndex; i++) {
        
        drawWidgetWindow(widgets[i]);
        
        int componentsOffsetY = 0;
        for (int j = 0; j < widgets[i].componentIndex; j++) {
            int offsetX = widgets[i].x + Widget::WidgetPadding;
            int offsetY = widgets[i].y + Widget::WidgetPadding + topBarHeight + componentsOffsetY;
            
            widgets[i].components[j]->Draw(offsetX, offsetY);
            
            componentsOffsetY += widgets[i].components[j]->GetHeight() + Widget::WidgetPadding;
        }
    }
}

void Gui::drawWidgetWindow(Widget& widget){
    Engine::SetEngineDrawColor(topBarColor.r, topBarColor.g, topBarColor.b, topBarColor.a);
    Engine::FillRectangle(widget.x - Widget::WidgetBorder,
                          widget.y,
                          widget.w + Widget::WidgetBorder * 2,
                          topBarHeight + widget.h + Widget::WidgetBorder);
    
    Engine::SetEngineDrawColor(windowColor.r, windowColor.g, windowColor.b, windowColor.a);
    Engine::FillRectangle(widget.x, widget.y + topBarHeight, widget.w, widget.h);
    
    Engine::RenderTexture(widget.labelTexture,
                          widget.x + Widget::WidgetPadding,
                          widget.y,
                          topBarHeight * 3,
                          topBarHeight);
}

void Gui::NewFrame(){
    lastFrameWidgetsCount = widgetIndex;
    widgetIndex = 0;
}

bool Gui::widgetIsNew(){
    return widgetIndex + 1 > lastFrameWidgetsCount;
}

void Gui::CreateCheckbox(const std::string& label, bool *v){
    if (widgetIsNew()) {
        UiComponent* c = new Checkbox(label, v);
        tempWidget.components[tempWidget.componentIndex] = c;
        
        tempWidget.w = std::max(tempWidget.w, c->GetWidth());
        tempWidget.h += c->GetHeight();
        
        tempWidget.componentIndex += 1;
    }
}


void Gui::CreateFloatSlider(const std::string& label, float *v, float min, float max){
    if (widgetIsNew()) {
        UiComponent* c = new FloatSlider(label, v, min, max);
        tempWidget.components[tempWidget.componentIndex] = c;
        
        tempWidget.w = std::max(tempWidget.w, c->GetWidth());
        tempWidget.h += c->GetHeight();
        
        tempWidget.componentIndex += 1;
    }
}


void Gui::CreateIntSlider(const std::string& label, int *v, int min, int max){
    if (widgetIsNew()) {
        UiComponent* c = new IntSlider(label, v, min, max);
        tempWidget.components[tempWidget.componentIndex] = c;
        
        tempWidget.w = std::max(tempWidget.w, c->GetWidth());
        tempWidget.h += c->GetHeight();
        
        tempWidget.componentIndex += 1;
    }
}

void Gui::CreateText(const std::string& label){
    if (widgetIsNew()) {
        UiComponent* c = new UiText(label);
        tempWidget.components[tempWidget.componentIndex] = c;
        
        tempWidget.w = std::max(tempWidget.w, c->GetWidth());
        tempWidget.h += c->GetHeight();
        
        tempWidget.componentIndex += 1;

    }
}
