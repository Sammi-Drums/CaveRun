#include "room.h"
#include "player.h"
#include <iostream>
#include <cmath>

Room::Room()
    : row(0), col(0), description("A plain room."), healthEffect(0), isTrapRoom(false) {}

Room::Room(int row, int col, const std::string& description, int healthEffect, bool isTrapRoom)
    : row(row), col(col), description(description), healthEffect(healthEffect), isTrapRoom(isTrapRoom) {}

void Room::enter(Player& player) {
    std::cout << "You entered Room (" << row << ", " << col << "): " << description << std::endl;
    if (isTrapRoom) {
        std::cout << "It's a trap room! You lose one move and 20% of your health.\n";
        player.updateHealth(-std::ceil(player.getHealth() * 0.2));
        player.decrementMove();
    } else if (healthEffect != 0) {
        if (healthEffect > 0) {
            std::cout << "It's a cure room! Health increased by " << healthEffect << " points.\n";
        } else {
            std::cout << "It's a poison room! Health reduced by " << -healthEffect << " points.\n";
        }
        player.updateHealth(healthEffect);
    }
}