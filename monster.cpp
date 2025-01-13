#include "monster.h"
#include "player.h"
#include <iostream>

Monster::Monster(int startRow, int startCol) : row(startRow), col(startCol) {}

int Monster::getRow() const { return row; }
int Monster::getCol() const { return col; }

void Monster::moveTowardPlayer(int playerRow, int playerCol) {
    if (row < playerRow) row++;
    else if (row > playerRow) row--;

    if (col < playerCol) col++;
    else if (col > playerCol) col--;
}

bool Monster::sensePlayer(int playerRow, int playerCol) const {
    return row == playerRow && col == playerCol;
}

void Monster::attack(Player& player) const {
    std::cout << "Monster attacks! Player loses 20 health points.\n";
    player.updateHealth(-20);
}