#include "iostream"
#include "Direction_state.h"
#include "Direction_manager.h"


class Empty_state:public Direction_state{
    
public:
    //Добавить конструктор и деструктор
    void start_move(direction way); //Direction_manager::direction
    void move(float time);
    void stop_move(direction way);
};


class One_direction_state:public Direction_state{
public:
    void start_move(direction way);
    void move(float time);
    void stop_move(direction way);




};


class Many_direction_state: public Direction_state{
public:
    void start_move(direction way);
    void move(float time);
    void stop_move(direction way);




};



