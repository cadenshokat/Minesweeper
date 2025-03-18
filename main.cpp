//
//  main.cpp
//  Minesweeper
//
//  Created by Caden Shokat on 11/30/24.
//

/* #include <iostream>
#include <SFML/Graphics.hpp>
#include "Board.h"

int main() {
    const int rows = 10;
    const int cols = 10;
    const int numMines = 20;
    
    sf::RenderWindow window(sf::VideoMode(cols * 32, rows * 32 + 50), "Minesweeper");

    sf::Event event{};

    
    Board board(rows, cols, numMines);
    
    while (window.isOpen()) {
        
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                
                int col = mousePos.x /32;
                int row = mousePos.y /32;
                
                if (event.mouseButton.button == sf::Mouse::Button::Left) {
                    bool gameOver = board.revealedTile(row, col);
                    
                    if (gameOver) {
                        board.revealAllMines(true);
                    }
                } else if (event.mouseButton.button == sf::Mouse::Button::Right) {
                    board.flagTile(row, col);
                }
            }
        }
    }
    
    if (board.checkWin()) {
        board.revealAllMines(true);
    }
    
    window.clear(sf::Color::White);
    board.render(window);
    window.display();
    
    return 0;
}

*/
#include <iostream>
#include <vector>
#include "Board.h"

int main() {
    const int rows = 10; // Number of rows in the board
    const int cols = 10; // Number of columns in the board
    const int numMines = 20; // Number of mines

    // Create the game board
    Board board(rows, cols, numMines);

    // Print the initial board state
    std::cout << "Initial Minesweeper Board:\n";
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            // Check the state of each tile and print the corresponding symbol
            if (board.getTile(row, col).getRevealed()) {
                if (board.getTile(row, col).getMine()) {
                    std::cout << "* "; // Mine
                } else {
                    std::cout << board.getTile(row, col).getAdjMines() << " "; // Adjacent mines
                }
            } else if (board.getTile(row, col).getFlagged()) {
                std::cout << "F "; // Flagged tile
            } else {
                std::cout << ". "; // Hidden tile
            }
        }
        std::cout << "\n";
    }

    return 0;
}


