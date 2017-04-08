#include <string>
#include <iostream>
#include <game/world/fields/City.h>
#include "BuildCity.h"


void BuildCity::perform() {
    Field * field = getFieldSelector()->getSelectedField();
    Field * city  = new City(field->getX(), field->getY(), field->getWorld());
    field->getWorld()->setField(field->getId(), city);
    getFieldSelector()->setSelectedField(city);
    city->takeOwnership(static_cast<Character *>(player));
}

BuildCity::BuildCity(FieldSelector *fieldSelector, Player * player) : fieldSelector(fieldSelector), player(player) {}
