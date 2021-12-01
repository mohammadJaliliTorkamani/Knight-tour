

/*
 *
 *              Open This Project With QT-Creator
 *      Run The Applciation (ctrl+R) & Full-Screen It (Fn+F11)
 *                  Then Input Knight's Position
 * */

#include <iostream>
#include <handler.h>
#include <horse.h>
#include <board.h>
using namespace std;

int main()
{
    Handler manager;
    Board board;
    Horse horse(board);

    horse.place();
    if(horse.cover())
        manager.display(horse.getPassed_elements(),board.getSize() * board.getSize());
    else
        cout<<"Couldn't Cover The Board";

    return 0;
}
