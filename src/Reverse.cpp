#include "Reverse.h"


void Reverse::operator+(Player &player){
    player.setReverse(true);
    //подправить
}
void Reverse::print(){
        std::cout<<"R";
}
