//
//  Tile.cpp
//  Minesweeper
//
//  Created by Caden Shokat on 11/30/24.
//

#include "Tile.h"
#include <SFML/Graphics.hpp>

Tile::Tile() {
    isMine = false;
    isRevealed = false;
    isFlagged = false;
    adjMines = 0;
}

void Tile::setMine(bool mine) {
    isMine = mine;
}

void Tile::setRevealed(bool revealed) {
    isRevealed = revealed;
}

void Tile::setFlagged(bool flagged) {
    isFlagged = flagged;
}

void Tile::setAdjMines(int count) {
    adjMines = count;
}

//void Tile::setTexture(const sf::Texture &texture) {
//    sprite.setTexture(texture);
//}

bool Tile::getMine() const {
    return isMine;
}

bool Tile::getFlagged() const {
    return isFlagged;
}

bool Tile::getRevealed() const {
    return isRevealed;
}

int Tile::getAdjMines() const {
    return adjMines;
}

//void Tile::render(sf::RenderWindow &window, int x, int y) {
//    sprite.setPosition(x, y);
    
//    window.draw(sprite);
//}

void Tile::reset() {
    isMine = false;
    isFlagged = false;
    isRevealed = false;
    adjMines = 0;
}
