#ifndef BOARD_H
#define BOARD_H

#include <iostream>

#define BOARD_SIZE 8

using namespace std;

class Board
{
public:
    Board();
    int getSize() const;
    bool **getBlocks() const;

private:
    bool **blocks;
    int size;
    void allocate_blocks();
    void initialize_blocks();
};
#endif // BOARD_H
