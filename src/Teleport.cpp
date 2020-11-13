#include "Teleport.h"


Teleport::Teleport(type content, Pair coords){
    this->content=content;
    this->coords=coords;
}

void Teleport::operator+(Player &player){
    if(content ==  entrance)
        player.setPosition(coords);
}

void Teleport::print(){
    if(content== entrance)
        std::cout<<"E";
    else{
        std::cout<<"Q";
    }
        
}



