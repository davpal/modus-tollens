#include "Meadow.h"
#include "FertilityMode.h"

sf::Sprite FertilityMode::getSprite(Field * field) const {
    sf::Uint8 green = 0;
    sf::Uint8 red   = 0;
    sf::Sprite sprite;

    if (field->getKind() == "meadow") {
        Meadow *meadow = static_cast<Meadow *>(field);
        if (meadow->getSoil().getName() != "") {
            green += meadow->getSoil().getFertility() * 2;
        } else {
            red = 200;
        }
    }

    sprite.setColor(sf::Color(red, green, 0));
    return sprite;
}

