#include "Button.h"

Button::Button(int x, int y, std::string name) : x(x), y(y), name(name) {}

void Button::click() {
    listener->perform();
}

void Button::render(Renderer &renderer, bool dark) const {
    std::string fieldKind = renderer.getFieldSelector()->getSelectedField()->getKind();
    if(fieldKind != "water")
        renderer.drawButton(*this);
}
