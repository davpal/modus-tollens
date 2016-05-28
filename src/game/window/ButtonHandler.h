#pragma once

#include "Button.h"

class Button;
class FieldSelector;
class Player;

class ButtonHandler {
private:
    std::vector<Button*> buttons;
    FieldSelector * fieldSelector;
    Player * currentPlayer;
public:

    ButtonHandler(FieldSelector * fieldSelector, Player * currentPlayer);

    ~ButtonHandler();

    void handleClick(int x, int y);

    bool inRange(int x, int y);

    void initializeButtons(int x);

    void render(Renderer &renderer);

    Player *getCurrentPlayer() const {
        return currentPlayer;
    }

    void setCurrentPlayer(Player *currentPlayer) {
        this->currentPlayer = currentPlayer;
    }

    FieldSelector *getFieldSelector() const {
        return fieldSelector;
    }

    void addButton(Button * button) {
        buttons.push_back(button);
    }

    const std::vector<Button *> &getButtons() const {
        return buttons;
    }

};
