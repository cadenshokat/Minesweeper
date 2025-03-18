//
//  Tile.h
//  Minesweeper
//
//  Created by Caden Shokat on 11/30/24.
//

#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>

class Tile {
private:
    bool isMine;
    bool isRevealed;
    bool isFlagged;
    int adjMines;
    //sf::Sprite sprite;
    
public:
    Tile();
    
    void setMine(bool mine);
    void setRevealed(bool revealed);
    void setFlagged(bool flagged);
    void setAdjMines(int count);
    //void setTexture(const sf::Texture &texture);
    
    bool getMine() const;
    bool getRevealed() const;
    bool getFlagged() const;
    int getAdjMines() const;
    
    //void render(sf::RenderWindow &window, int x, int y);
    
    void reset();
    
};

#endif // TILE_H
