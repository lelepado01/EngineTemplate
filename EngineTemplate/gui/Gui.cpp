//
//  Gui.cpp
//  EngineTemplate
//
//  Created by Gabriele Padovani on 29/10/21.
//

#include "Gui.hpp"

int Gui::widgetIndex = 0;
int Gui::lastFrameWidgetsCount = 0;
bool Gui::widgetIsBeingMoved = false;
bool Gui::widgetIsBeingResized = false;
bool Gui::widgetSliderIsBeingDragged = false;


Widget Gui::tempWidget = Widget{};
std::vector<Widget> Gui::widgets = std::vector<Widget>(10);

const SDL_Color windowColor = SDL_Color{0, 160, 145, 255};
const SDL_Color topBarColor = SDL_Color{50, 50, 50, 255};

void Gui::Begin(const std::string& label, int x, int y, bool moveable, bool resizeable){
    tempWidget.x = x;
    tempWidget.y = y;
    tempWidget.w = 2 * (Widget::WidgetPadding + initialWidgetHeight);
    tempWidget.h = initialWidgetHeight;
    tempWidget.minWidth = tempWidget.w;
    tempWidget.minHeight = tempWidget.h;
    tempWidget.moveable = moveable;
    tempWidget.resizeable = resizeable;
    
    if (!widgets[widgetIndex].labelTexture){
        tempWidget.labelTexture = Engine::LoadTextureFromText(label.c_str());
    }
    
    tempWidget.mouseMoveGrab = {};
}

void Gui::End(){
    if (widgetIsNew()) {
        widgets[widgetIndex] = tempWidget;
    }
    
    widgetIndex += 1;
    tempWidget = {};
}


void Gui::Update(){
    
    widgetSliderIsBeingDragged = false;
    
    /// Check for widget dragged
    for (int i = 0; i < widgetIndex; i++) {
        if (widgetSliderIsBeingDragged || widgetIsBeingResized) break;
        if (widgets[i].isBeingResized() || widgets[i].isBeingInteractedWith()) continue;

        if (!widgetIsBeingMoved || (widgetIsBeingMoved && widgets[i].isBeingMoved())){
            widgetIsBeingMoved = checkWidgetForMouseDrag(widgets[i]);
            if(widgetIsBeingMoved) break;
        }
    }

    /// Check for widget resize
    for (int i = 0; i < widgetIndex; i++) {
        if (widgetSliderIsBeingDragged || widgetIsBeingMoved) break;
        if (widgets[i].isBeingMoved() || widgets[i].isBeingInteractedWith()) continue;

        if (!widgetIsBeingResized || (widgetIsBeingResized && widgets[i].isBeingResized())){
            widgetIsBeingResized = checkWidgetForMouseResize(widgets[i]);
            if (widgetIsBeingResized) break;
        }
    }
    
    /// Check sliders
    for (int i = 0; i < widgetIndex; i++) {
        if (widgetIsBeingMoved || widgetIsBeingResized) break;
        if (widgets[i].isBeingResized() || widgets[i].isBeingMoved()) continue;
        
        if (!widgetSliderIsBeingDragged || (widgetSliderIsBeingDragged && widgets[i].isBeingInteractedWith())){
            widgetSliderIsBeingDragged = checkWidgetForSliderGrab(widgets[i]);
            if (widgetSliderIsBeingDragged) {
                updateWidgetComponents(widgets[i]);
                break;}
        }
    }
    
    /// Update all widgets
    if (widgetIsBeingMoved || widgetIsBeingResized || widgetSliderIsBeingDragged) return;
    for (int i = 0; i < widgetIndex; i++) {
        updateWidgetComponents(widgets[i]);
    }
}

void Gui::updateWidgetComponents(Widget& widget){
    int componentsOffsetY = 0;
    for (int j = 0; j < widget.componentIndex; j++) {
        
        int offsetX = widget.x + Widget::WidgetPadding;
        int offsetY = widget.y + topBarHeight + componentsOffsetY + Widget::WidgetPadding * (j+1);
        widget.components[j]->Update(offsetX, offsetY);

        componentsOffsetY += widget.components[j]->GetHeight();
    }
}

bool Gui::checkWidgetForSliderGrab(Widget &widget){
    for (int j = 0; j < widget.componentIndex; j++) {

        if (widget.components[j]->GetType() == ComponentType::SliderType){
            
            Slider* slider = (Slider*) widget.components[j];
            if (slider->SliderIsBeingGrabbed()) {
                return true;
            }
        }
    }
    
    return false;
}

bool Gui::checkWidgetForMouseDrag(Widget& widget){
    if (!widget.moveable) return false;
    
    if (Engine::MouseLeftKeyIsPressed()){
        SDL_Point mouse = Engine::GetMousePosition();
        SDL_Rect widgetArea {widget.x, widget.y, widget.w, topBarHeight};
        
        if (MathCommon::RectangleContainsPoint(widgetArea, mouse) || widget.isBeingMoved()) {
            
            if (widget.isBeingMoved()){
                widget.x = mouse.x - widget.mouseMoveGrab.value().x;
                widget.y = mouse.y - widget.mouseMoveGrab.value().y;
                widgetIsBeingMoved = true;
            }
            
            widget.mouseMoveGrab = SDL_Point{ mouse.x - widget.x , mouse.y - widget.y };
            
            return true;
        }
    } else {
        widget.mouseMoveGrab = {};
    }
    
    return false;
}

bool Gui::checkWidgetForMouseResize(Widget &widget){
    if (!widget.resizeable) return false;
    
    if (Engine::MouseLeftKeyIsPressed()){
        SDL_Point mouse = Engine::GetMousePosition();
        SDL_Rect resizeArea {
            widget.x + widget.w - Widget::ResizeTriangleSize,
            widget.y + topBarHeight + widget.h - Widget::ResizeTriangleSize,
            Widget::ResizeTriangleSize,
            Widget::ResizeTriangleSize
        };
        
        if (MathCommon::RectangleContainsPoint(resizeArea, mouse) || widget.isBeingResized()) {
            
            if (widget.isBeingResized()){
                widget.w = mouse.x - widget.mouseResizeGrab.value().x;
                widget.h = mouse.y - widget.mouseResizeGrab.value().y;
                
                widgetIsBeingResized = true;
            }
            
            if (widget.w < widget.minWidth || widget.h < widget.minHeight){
                if (widget.w < widget.minWidth) widget.w = widget.minWidth;
                if (widget.h < widget.minHeight) widget.h = widget.minHeight;
            } else {
                widget.mouseResizeGrab = SDL_Point{ mouse.x - widget.w , mouse.y - widget.h };
            }
            
            return true;
        }
    } else {
        widget.mouseResizeGrab = {};
    }
    
    return false;
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
    drawWidgetTopBar(widget);
    
    Engine::SetEngineDrawColor(windowColor.r, windowColor.g, windowColor.b, windowColor.a);
    Engine::FillRectangle(widget.x, widget.y + topBarHeight, widget.w, widget.h);
        
    if (widget.resizeable){
        drawWidgetResizeTriangle(widget);
    }
}

void Gui::drawWidgetTopBar(Widget &widget){
    Engine::SetEngineDrawColor(topBarColor.r, topBarColor.g, topBarColor.b, topBarColor.a);
    Engine::FillRectangle(widget.x - Widget::WidgetBorder,
                          widget.y,
                          widget.w + Widget::WidgetBorder * 2,
                          topBarHeight + widget.h + Widget::WidgetBorder);
    
    Engine::RenderTexture(widget.labelTexture,
                          widget.x + Widget::WidgetPadding,
                          widget.y,
                          topBarHeight * 3,
                          topBarHeight);
}

void Gui::drawWidgetResizeTriangle(Widget &widget){
    std::vector<SDL_Point> points = {
        SDL_Point{widget.x + widget.w, widget.y + topBarHeight + widget.h - Widget::ResizeTriangleSize},
        SDL_Point{widget.x + widget.w, widget.y + topBarHeight + widget.h},
        SDL_Point{widget.x + widget.w - Widget::ResizeTriangleSize, widget.y + topBarHeight + widget.h}
    };
    
    Engine::SetEngineDrawColor(topBarColor.r, topBarColor.g, topBarColor.b, topBarColor.a);
    Engine::FillPolygon(points);
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
        tempWidget.addComponent(c);
    }
}

void Gui::CreateFloatSlider(const std::string& label, float *v, float min, float max){
    if (widgetIsNew()) {
        UiComponent* c = new FloatSlider(label, v, min, max);
        tempWidget.addComponent(c);
    }
}

void Gui::CreateIntSlider(const std::string& label, int *v, int min, int max){
    if (widgetIsNew()) {
        UiComponent* c = new IntSlider(label, v, min, max);
        tempWidget.addComponent(c);
    }
}

void Gui::CreateText(const std::string& label){
    if (widgetIsNew()) {
        UiComponent* c = new UiText(label);
        tempWidget.addComponent(c);
    }
}
