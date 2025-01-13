#ifndef MONSTER_H
#define MONSTER_H

class Player; // Forward declaration

class Monster {
private:
    int row, col; // Position on the map

public:
    Monster(int startRow, int startCol);
    int getRow() const;
    int getCol() const;
    void moveTowardPlayer(int playerRow, int playerCol);
    bool sensePlayer(int playerRow, int playerCol) const;
    void attack(Player& player) const;
};

#endif // MONSTER_H