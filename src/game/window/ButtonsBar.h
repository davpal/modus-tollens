#pragma once

#include "Button.h"

class Button;
class FieldSelector;
class Player;

class ButtonsBar {
private:
    std::vector<std::unique_ptr<Button>> buttons;
    FieldSelector * fieldSelector;
    Player * currentPlayer;
public:

    ButtonsBar(FieldSelector * fieldSelector, Player * currentPlayer);

    ~ButtonsBar();

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

    void addButton(std::unique_ptr<Button> button) {
        buttons.push_back(std::move(button));
    }

    const std::vector<std::unique_ptr<Button>> &getButtons() const {
        return buttons;
    }

};
