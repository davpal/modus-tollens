#include "Forest.h"
#include "TreesMode.h"

sf::Sprite TreesMode::getSprite(Field * field) const {
    sf::Uint8 green = 0;
    sf::Uint8 red   = 0;
    sf::Sprite sprite;

    if (field->getKind() == "forest") {
        Forest *forest = static_cast<Forest *>(field);
        green += forest->getTreesCount() / 4;
        if(forest->getTreesCount() == 0) {
            red = 200;
            green = 0;
        }
    }
    sprite.setColor(sf::Color(red, green, 0));
    return sprite;
}
