#ifndef HORSE_H
#define HORSE_H

#include <board.h>
#include <element.h>

class Horse
{
public:
    //constructor(s)
    Horse();
    Horse(Board &board);
    //non-static methods
    void place();
    bool cover();

    //  Getters & Setters
    Board getBoard() const;
    Element *getPassed_elements() const;

    void setBoard(const Board &value);
    void setPassed_elements(Element *value);

    Element position;

    Element getFirst_place() const;
    void setFirst_place(const Element &value);

private:
    Board board;
    Element *passed_elements;
    int possible_moves[8][2]={{1,2},{2,1},{-1,2},{-2,1},
                              {1,-2},{2,-1},{-1,-2},{-2,-1}};
    Element first_place;
    Element* find_possible_places(const Element from);
    Element decide_best_move(Element* probalbes);
    int get_size_of_element_array(const Element*);
    Element find_min_prob_element(const int*,const Element*,int);
};

#endif // HORSE_H
