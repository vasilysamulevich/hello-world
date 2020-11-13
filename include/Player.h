#pragma once
#include "Pair.h"
#include <iostream> //временно
class Player{
    Pair position;
    int scores;
    int damage;
    int health;
    bool isReverse;
public:
    Player();
    ///////
    Pair getPosition();
    void setPosition(Pair coords);
    void setScores(int val);
    int getScores();
    void setReverse(bool val);
    void print();//временная
    ///////
};

