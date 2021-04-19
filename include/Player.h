#pragma once
#include "Pair.hpp"
#include "Field.h"
#include "cmath"
class Player
{
public:
    enum direction{Up=0,Down=1,Left=2,Right=3};
private:
    Pair_d position; //Koordinats of left up angle
    Pair_d size_player; // (width,height)
    double speed;
    Field& field;
    double* reserves;
    void initializing_reserves();
    void refresh(direction way);
    Pair_d convert_to_pair(double distance,direction way);
    void update_reserve(direction way); 
public:
    Pair_d get_size_player();
    Pair_d get_position(); 
    void move(direction way, double time);
    Player(Pair_d position,Pair_d size_player, double speed,Field& field);
    ~Player();
};


