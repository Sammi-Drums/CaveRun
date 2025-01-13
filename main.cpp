#include "player.h"
#include "monster.h"
#include "room.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// --- Constants ---
const int ROWS = 4;
const int COLUMNS = 4;

// --- Helper Function ---
bool isAdjacent(int currentRow, int currentCol, int newRow, int newCol) {
    int rowDiff = std::abs(currentRow - newRow);
    int colDiff = std::abs(currentCol - newCol);
    return (rowDiff + colDiff == 1); // Manhattan distance = 1
}

int main() {
    // Initialize player and monster
    Player player(0, 0);  // Top-left corner
    Monster monster(4, 6); // Bottom-right corner

    // Initialize rooms
    std::vector<std::vector<Room>> map(ROWS, std::vector<Room>(COLUMNS));
    srand(time(nullptr)); // Seed for randomization

    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLUMNS; c++) {
            int effect = 0;
            bool isTrap = false;

            if ((rand() % 10) < 3) { // 30% chance of a trap
                isTrap = true;
            } else if ((rand() % 10) < 2) { // 20% chance of a poison room
                effect = -10;
            } else if ((rand() % 10) < 2) { // 20% chance of a cure room
                effect = 25;
            }

            map[r][c] = Room(r, c, "A mysterious room.", effect, isTrap);
        }
    }

    // Game loop
    bool gameRunning = true;
    while (gameRunning) {
        player.displayStatus();

        // Player's turn
        while (player.getMovesLeft() > 0) {
            std::cout << "Enter your move (row col, -1 to exit): ";
            int newRow, newCol;
            std::cin >> newRow;
            if (newRow == -1) {
                std::cout << "You chose to exit the game. Goodbye!\n";
                gameRunning = false;
                break;
            }
            std::cin >> newCol;

            // Validate input
            if (!isAdjacent(player.getRow(), player.getCol(), newRow, newCol)) {
                std::cout << "You can only move to adjacent rooms! Try again.\n";
                continue;
            }
            if (newRow < 0 || newRow >= ROWS || newCol < 0 || newCol >= COLUMNS) {
                std::cout << "Invalid position. Try again.\n";
                continue;
            }

            // Move player
            player.setPosition(newRow, newCol);
            map[newRow][newCol].enter(player);

            if (player.getHealth() <= 0) {
                std::cout << "You have died! Game over.\n";
                gameRunning = false;
                break;
            }

            player.decrementMove();
        }

        if (!gameRunning) break;

        // Monster's turn
        monster.moveTowardPlayer(player.getRow(), player.getCol());
        std::cout << "Monster moved to (" << monster.getRow() << ", " << monster.getCol() << ").\n";

        // Check if monster and player are in the same room
        if (monster.getRow() == player.getRow() && monster.getCol() == player.getCol()) {
            std::cout << "The monster has caught you! Game over.\n";
            gameRunning = false;
            break;
        }

        // Check win condition
        if (player.getRow() == 4 && player.getCol() == 6 && gameRunning) {
            std::cout << "Congratulations! You have reached the exit and escaped the cave!\n";
            gameRunning = false;
        }

        player.resetMoves();
    }

    std::cout << "Thank you for playing Cave Escape!\n";
    return 0;
}