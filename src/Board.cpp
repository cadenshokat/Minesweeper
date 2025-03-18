//
//  Board.cpp
//  Minesweeper
//
//  Created by Caden Shokat on 11/30/24.
//

#include "Board.h"
#include "Tile.h"
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

Board::Board(int rows, int cols, int numMines) {
    this->rows = rows;
    this->cols = cols;
    this->numMines = numMines;
    tiles.resize(rows, vector<Tile>(cols));
    
    initialize();
}

int Board::countAdjMines(int row, int col) {
    int mineCount = 0;
    for (int rowOff = -1; rowOff <= 1; rowOff ++) {
        for (int colOff = -1; colOff <= 1; colOff ++) {
            
            if (rowOff == 0 && colOff == 0) {
                continue;
            }
            
            int newRow = row + rowOff;
            int newCol = col + colOff;
            
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                if (tiles[newRow][newCol].getMine()) {
                    mineCount ++;
                }
            }
        }
    }
    
    return mineCount;
}

void Board::revealAdjTiles(int row, int col) {    
    for (int rowOff = -1; rowOff <= 1; rowOff ++) {
        for (int colOff = -1; colOff <= 1; colOff ++) {
            int newRow = row + rowOff;
            int newCol = col + colOff;
            
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                Tile &tile = tiles[newRow][newCol];
                
                if (!tile.getRevealed() && !tile.getMine() && !tile.getFlagged()) {
                    tile.setRevealed(true);
                    
                    if(tile.getAdjMines() == 0) {
                        revealAdjTiles(newRow, newCol);
                    }
                }
            }
        }
    }
}

void Board::initialize() {
    for (int row = 0; row < rows; row ++) {
        for (int col = 0; col < cols; col ++) {
            tiles[row][col].reset();
        }
    }
    
    srand(static_cast<unsigned>(time(0)));
    int minesPlaced = 0;
    
    while (minesPlaced < numMines) {
        int row = rand() % rows;
        int col = rand() % cols;
        if (!tiles[row][col].getMine()) {
            tiles[row][col].setMine(true);
            minesPlaced ++;
        }
    }
    
    for (int row = 0; row < rows; row ++) {
        for (int col = 0; col < cols; col ++) {
            tiles[row][col].setAdjMines(countAdjMines(row, col));
        }
    }
}

void Board::reset() {
    initialize();
}

bool Board::revealedTile(int row, int col) {
    if (row == 0 || row >= rows || col == 0 || col >= cols ) {
        return false;
    }
    
    Tile &tile = tiles[row][col];
    
    if (tile.getRevealed() || tile.getFlagged()) {
        return false;
    }
    
    tile.setRevealed(true);
    
    if (tile.getMine()) {
        return true;
    }
    
    if (tile.getAdjMines() == 0) {
        revealAdjTiles(row, col);
    }
    
    return false;
    
}

void Board::flagTile(int row, int col) {
    if (row < 0 || row >= rows || col < 0 || col >= cols ) {
        return;
    }
    
    Tile &tile = tiles[row][col];
    
    if (!tile.getRevealed()) {
        tile.setFlagged(!tile.getFlagged());
    }
}

bool Board::checkWin() const {
    
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            
            const Tile &tile = tiles[row][col];
            
            if (!tile.getMine() && !tile.getRevealed()) {
                return false;
            }
            
        }
    }
    
    return true;
}

//void Board::render(sf::RenderWindow &window) {
//    for (int row = 0; row < rows; ++row) {
//            for (int col = 0; col < cols; ++col) {
//                tiles[row][col].render(window, col * 32, row * 32);
//            }
//        }
//}

void Board::revealAllMines(bool reveal) {
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            Tile &tile = tiles[row][col];
            
            if (tile.getMine()) {
                tile.setRevealed(reveal);
            }
        }
    }
}

Tile& Board::getTile(int row, int col) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("Invalid tile position"); // Optional error handling
    }
    return tiles[row][col];
}
