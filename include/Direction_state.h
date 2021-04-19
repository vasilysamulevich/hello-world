#pragma once
#include <iostream>
class Direction_manager;
enum direction{Up=1,Down=10,Left=100,Right=1000};

class Direction_state{
protected:
    Direction_manager* manager;

public:
    void set_manager(Direction_manager* to_set);
    virtual void start_move(direction way)=0;
    virtual void move(float time)=0;
    virtual void stop_move(direction way)=0;



};
