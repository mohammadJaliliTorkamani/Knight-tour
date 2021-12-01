#include "board.h"

Board::Board()
{
    /*    Start Initializing The Board      */

    size=BOARD_SIZE;
    allocate_blocks();
    initialize_blocks();

    /*    Finished Initializing The Board      */

}
int Board::getSize() const
{
    return size;
}
bool **Board::getBlocks() const
{
    return blocks;
}



void Board::allocate_blocks()
{
    blocks=new bool*[BOARD_SIZE];
    for(int i=0;i<BOARD_SIZE;i++)
        blocks[i]=new bool[BOARD_SIZE];
}

void Board::initialize_blocks()
{
    for(int i=0;i<BOARD_SIZE;i++)
        for(int j=0;j<BOARD_SIZE;j++)
            blocks[i][j]=false;
}
