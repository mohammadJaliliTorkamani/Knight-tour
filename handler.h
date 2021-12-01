#ifndef HANDLER_H
#define HANDLER_H
#include <iostream>
#include <element.h>
#include <stdio.h>
#include <thread>
#include <unistd.h>

using namespace std;

class Handler
{
public:
    Handler();
    void display(Element *blocks,int square_board_size);
private:
    void create_square();
    void color_block(Element element);
    void gotoxy(int x,int y);
    void delay();
};

#endif // HANDLER_H
