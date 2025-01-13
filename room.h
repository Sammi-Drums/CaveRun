#ifndef ROOM_H
#define ROOM_H
#include <string>

class Player; // Forward declaration

class Room {
private:
    int row, col; // Room's position on the map
    std::string description;
    int healthEffect; // Health impact of the room
    bool isTrapRoom;

public:
    Room();
    Room(int row, int col, const std::string& description, int healthEffect, bool isTrapRoom);
    void enter(Player& player);
};

#endif // ROOM_H