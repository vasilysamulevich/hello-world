#include "Player.h"
Pair  Player::getPosition(){
    return position;
}

Player::Player(): position(Pair()), scores(0),damage(10),health(100),isReverse(false){}
void Player::setPosition(Pair coords){
    position=coords;
}
void Player::setScores(int val){
    scores=val;
}
int Player::getScores(){
    return scores;
}

void Player::setReverse(bool val){
    isReverse=val;

}

void Player::print(){
    std::cout<<"Позиция на карте -";
    position.print();
    std::cout <<"Очки - "<<scores<<'\n'<<"Урон - "<<damage<<'\n'<<"Жизни - "<<health<<'\n'<<"Реверс -"<<isReverse<<'\n';

}





