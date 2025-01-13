#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    int health;
    int row, col; // Position on the map
    int movesLeft;

public:
    Player(int startRow, int startCol);
    int getHealth() const;
    int getRow() const;
    int getCol() const;
    int getMovesLeft() const;
    void setPosition(int newRow, int newCol);
    void updateHealth(int value);
    void decrementMove();
    void resetMoves();
    void displayStatus() const;
};

#endif // PLAYER_H