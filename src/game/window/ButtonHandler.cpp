#include <GameData.hpp>
#include <game/window/listeners/NewBuilding.h>
#include <game/window/listeners/BuildCity.h>
#include <game/world/Building.h>
#include <game/window/listeners/BuildCity.h>
#include "ButtonHandler.h"

ButtonHandler::ButtonHandler(FieldSelector * fieldSelector) : fieldSelector(fieldSelector) {}

void ButtonHandler::handleClick(int x, int y) {
    if(inRange(x,y)){
        for(auto &button : getButtons()) {
            if((x > button->getX() && x < button->getX() + 150) && (y > button->getY() && y < button->getY() + 18 )){
                button->click();
            }
        }
    }
}

bool ButtonHandler::inRange(int x, int y) {
    int tileSize = GameData::read<int>("world", "tileSize");
    int width    = GameData::read<int>("world", "width")  * tileSize;
    return (x > width);
}

void ButtonHandler::initializeButtons(int x){
    int y = 300;

    Button    * buildCity         = new Button(x, y, "Build City");
    BuildCity * buildCityListener = new BuildCity(fieldSelector);
    buildCity->setListener(buildCityListener);
    y+=25;
    Button      * newSawmill          = new Button(x, y, "Build Sawmill");
    NewBuilding * newSawmillListener  = new NewBuilding(BuildingKinds::SAWMILL, fieldSelector);
    newSawmill->setListener(newSawmillListener);

    y+=25;
    Button      * newFarm          = new Button(x, y, "Build Farm");
    NewBuilding * newFarmListener  = new NewBuilding(BuildingKinds::FARM, fieldSelector);
    newFarm->setListener(newFarmListener);

    addButton(buildCity);
    addButton(newSawmill);
    addButton(newFarm);
}

void ButtonHandler::render(Renderer &renderer) {
    renderer.drawButtons(*this);
}

ButtonHandler::~ButtonHandler() {
    buttons.clear();
}
