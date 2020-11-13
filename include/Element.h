#pragma once
#include "Player.h"
class Element{
public:
virtual void operator+(Player &player)=0;
virtual void print()=0;

};
