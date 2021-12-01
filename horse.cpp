#include "horse.h"

Horse::Horse()
{

}

Horse::Horse(Board &board)
{
    this->board=board;
    passed_elements=new Element[BOARD_SIZE*BOARD_SIZE];
}

void Horse::place()
{
    int x,y;
    cout<<"Enter Knight Position (x,y) : ";
    cin>>x>>y;
    this->position=Element(x,y,BOARD_SIZE);
    this->getBoard().getBlocks()[x][y]=true;
    this->setFirst_place(position);
    cout<<"Knight Started Trip from "<<position.getName();
    cout<<endl<<endl;


}

Board Horse::getBoard() const
{
    return board;
}

void Horse::setBoard(const Board &value)
{
    board = value;
}
Element *Horse::getPassed_elements() const
{
    return passed_elements;
}

void Horse::setPassed_elements(Element *value)
{
    passed_elements = value;
}
Element Horse::getFirst_place() const
{
    return first_place;
}

void Horse::setFirst_place(const Element &value)
{
    first_place = value;
}


Element *Horse::find_possible_places(const Element from)
{
    int new_x,new_y,counter=0;
    for(int i=0;i<8;i++)
    {
        new_x=from.getX()+possible_moves[i][0];
        new_y=from.getY()+possible_moves[i][1];
        if(new_x<BOARD_SIZE && new_x>=0 && new_y>=0 && new_y<BOARD_SIZE && !board.getBlocks()[new_x][new_y])
            counter++;
    }
    Element* probables=new Element[counter];
    counter=0;
    for(int i=0;i<8;i++)
    {
        new_x=from.getX()+possible_moves[i][0];
        new_y=from.getY()+possible_moves[i][1];
        if(new_x<BOARD_SIZE && new_x>=0 && new_y>=0 && new_y<BOARD_SIZE && !board.getBlocks()[new_x][new_y])
            probables[counter++]=Element(new_x,new_y,BOARD_SIZE);
    }
    return probables;

}
int Horse::get_size_of_element_array(const Element *item)
{
    int size_counter=0;
    while(item[size_counter++].getName()!="");
    return --size_counter;

}

Element Horse::find_min_prob_element(const int *probs_i, const Element *prob_p, int prob_size)
{
    int min_index=0,min_value=probs_i[min_index];
    for(int i=0;i<prob_size;i++)
        if(probs_i[i]<=min_value)
        {
            min_index=i;
            min_value=probs_i[i];
        }
    return prob_p[min_index];

}

Element Horse::decide_best_move(Element *probables)
{
    int prob_size=get_size_of_element_array(probables);
    if(prob_size==1)
        return probables[0];


    int* prob_ints=new int[prob_size];

    for(int i=0;i<prob_size;i++)
        prob_ints[i]=get_size_of_element_array(find_possible_places(probables[i]));

    return find_min_prob_element(prob_ints,probables,prob_size);
}

bool Horse::cover()
{
    Element* probable_places;
    probable_places=new Element[BOARD_SIZE];

    Element best_place;
    int counter=0;
    passed_elements[counter++]=position;
    while(true)
    {
        probable_places=find_possible_places(position);
        best_place=decide_best_move(probable_places);
        position=best_place;
        passed_elements[counter++]=best_place;
        this->getBoard().getBlocks()[best_place.getX()][best_place.getY()]=true;

        if(counter==64)
            return true;
    }
    return false;  //never been executed
}
