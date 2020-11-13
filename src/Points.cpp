#include "Points.h"

Points::Points(int scores): scores(scores) {}



void Points::operator+(Player& player){
    player.setScores(player.getScores()+scores);
}

void Points::print(){
    std::cout<<"P";

}

