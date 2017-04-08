#pragma once

#include "Observer.h"
#include "World.h"
#include "Stock.h"
#include "Renderer.h"
#include "Character.h"
#include "Field.h"

class World;
class Stock;
class Renderer;
class Field;

class Player : public Observer, public Character {
private:
    World * world;
    Stock stock;
public:
    Player();
    Stock &getStock();
    void render(Renderer & renderer);
    void update(Observable * o);
    void gather();
};