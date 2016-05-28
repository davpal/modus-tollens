#include <iostream>
#include <sstream>
#include <GameData.hpp>
#include "Field.h"

Field::Field(int x, int y, World * world) : x(x), y(y), world(world) {}

Field::~Field() {}

void Field::render(Renderer &renderer, bool dark)const {
    renderer.drawField(const_cast<Field*>(this), dark);
}

Field::operator std::string() {
    std::stringstream result;
    result << "(" << x << ", " << y << ") " << kind;
    return result.str();
}

std::string Field::getDescription() {
    return "No info";
}

std::string Field::getBuildingsDescription() {
    std::stringstream result;
    for(auto & building : getBuildings()){
        result << "  " << building->getDescription() << "\n";
    }
    return result.str();
}

void Field::randomize() {}

std::vector<Field*> Field::getNeighbors(){
    size_t width  = GameData::read<size_t>("world", "width");
    size_t height = GameData::read<size_t>("world", "height");
    std::vector<Field*> neighbors;
    if(id > 0)
        neighbors.push_back((*world)[id - 1]);
    if(id < getWorld()->getFields().size())
        neighbors.push_back(world->get(id + 1));
    if(id >= height)
        neighbors.push_back(world->get(getId() - height));
    if(id < height * (width - 1))
        neighbors.push_back(world->get(id + height));
    return neighbors;
}

void Field::takeOwnership(Character *character) {
    character->takeField(this);
    owner = character;
}
