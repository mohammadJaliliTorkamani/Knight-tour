#include "handler.h"
Handler::Handler()
{

}

void Handler::display(Element *blocks, int square_board_size)
{
    for(int i=0;i<square_board_size;i++)
        cout<<(i+1)<<". "<<blocks[i].getName()
           <<endl;

    create_square();

    for(int i=0;i<square_board_size;i++){
        color_block(blocks[i]);
        delay();


    }
    gotoxy(0,170);
}

void Handler::create_square()
{
    for(int j=5;j<=29;j+=3)
        for(int i=55;i<=119;i++)
        {
            gotoxy(i,j);
            cout<<"_";
        }
    for(int j=55;j<=120;j+=8)
        for(int i=6;i<30;i++)
        {
            gotoxy(j,i);
            cout<<"|";
        }


}

void Handler::color_block(Element element)
{
    int x=element.getX(),y=element.getY();
    gotoxy(8*x+58,3*y+7);
    cout<<"$";
}

void Handler::gotoxy(int x, int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}

void Handler::delay()
{
    cin.get();
}
