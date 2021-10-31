//
//  Gui.hpp
//  EngineTemplate
//
//  Created by Gabriele Padovani on 29/10/21.
//

#ifndef Gui_hpp
#define Gui_hpp

#include <stdio.h>
#include <math.h>

#include "Engine.hpp"
#include "FloatSlider.hpp"
#include "IntSlider.hpp"
#include "Checkbox.hpp"
#include "Widget.hpp"
#include "MathCommon.hpp"

class Gui {
private:
    static int widgetIndex;
    static int lastFrameWidgetsCount;
    static bool widgetHasMovedThisFrame; 
    
    static Widget widgets[10];
    static Widget tempWidget;
    
    static void widgetCheckForMouseDrag(Widget* widget);
    static void drawWidgetWindow(Widget* widget);

    
public:
    static void NewFrame(); 
    static void Begin(std::string label, int x, int y);
    static void End();
    
    static void Update();
    static void Draw();
        
    static void CreateCheckbox(std::string label, bool* v);
    static void CreateFloatSlider(std::string label, float* v, float min, float max);
    static void CreateIntSlider(std::string label, int* v, int min, int max);

};


#endif /* Gui_hpp */
