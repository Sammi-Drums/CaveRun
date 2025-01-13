#include "player.h"
#include <iostream>

Player::Player(int startRow, int startCol)
    : health(100), row(startRow), col(startCol), movesLeft(2) {}

int Player::getHealth() const { return health; }
int Player::getRow() const { return row; }
int Player::getCol() const { return col; }
int Player::getMovesLeft() const { return movesLeft; }

void Player::setPosition(int newRow, int newCol) {
    row = newRow;
    col = newCol;
}

void Player::updateHealth(int value) {
    health += value;
    if (health < 0) health = 0; // Prevent negative health
}

void Player::decrementMove() { movesLeft--; }
void Player::resetMoves() { movesLeft = 2; }

void Player::displayStatus() const {
    std::cout << "Player | Health: " << health
              << " | Position: (" << row << ", " << col << ")"
              << " | Moves Left: " << movesLeft << std::endl;
}