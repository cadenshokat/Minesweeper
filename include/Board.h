//
//  Board.h
//  Minesweeper
//
//  Created by Caden Shokat on 11/30/24.
//


#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "Tile.h"
using namespace std;


class Board {
private:
    int rows;
    int cols;
    int numMines;
    vector<vector <Tile>> tiles;
    
    int countAdjMines(int row, int col);
    void revealAdjTiles(int row, int col);
    
public:
    Board(int rows, int cols, int numMines);
    
    Tile& getTile(int row, int col);

    
    void initialize();
    void reset();
    
    bool revealedTile(int row, int col);
    void flagTile(int row, int col);
    
    bool checkWin() const;
    
    void render(sf::RenderWindow &window);
    
    void revealAllMines(bool reveal);
    
    
};

#endif // BOARD_H
