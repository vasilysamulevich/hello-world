#include "Player.h"

Player::Player(Pair_d position, Pair_d size_player,double speed,Field& field):size_player(size_player),position(position),speed(speed),field(field){
    if(!field.check_rectangle(position,position+size_player)){
        throw std::runtime_error("Invalid start position for player");
    }
    reserves=new double[4];
    initializing_reserves();
};

void Player::initializing_reserves(){  //инициализировать при необходимости
    double cell_size=field.get_cell_size();
    reserves[0]=fmod(position.y,cell_size);
    reserves[1]=cell_size - (fmod((position.y + size_player.y),cell_size));
    reserves[2]=fmod(position.x ,cell_size);
    reserves[3]=cell_size - (fmod((position.x + size_player.x),cell_size));
}


Pair_d Player::convert_to_pair(double distance,direction way){
    Pair_d res(0,0);
    switch(way){
        case Up:
            res.y=-distance;
        break;
    
        case Down:
            res.y=distance;
        break;
        case Left:
            res.x=-distance;
        break;

        case Right:
            res.x=distance;
        break;
    }

    return res;
}

void Player::move(direction way,double time){
    std::cout<<reserves[1]<<'\n';
    double distance=time*speed;
    if(reserves[way]==0)
        refresh(way);
 
    while(reserves[way] > 0)
    {
        if(distance < reserves[way]){
            reserves[way]=reserves[way]-distance;
            Pair_d shift=convert_to_pair(distance,way);
            position=position+shift;
            break;
        }
        distance=distance-reserves[way];
        Pair_d shift=convert_to_pair(reserves[way],way);
        position=position+shift;
        reserves[way]=0;
        refresh(way);
    }
    update_reserve(way);

    
}


void Player::update_reserve(direction way){
    double cell_size=field.get_cell_size();
    switch (way){
    case Up:
        reserves[1]=cell_size - (fmod((position.y + size_player.y),cell_size));
    break;

    case Down:
        reserves[0]=fmod(position.y,cell_size);
    break;

    case Left:
        reserves[3]=cell_size - (fmod((position.x + size_player.x),cell_size));            
    break;

    case Right:
        reserves[2]=fmod(position.x ,cell_size);
        break;     
    }
}


Pair_d Player::get_size_player(){
    return size_player;
}

Pair_d Player::get_position(){
    return position;
}

void Player::refresh(direction way){ ///???
    int cell_size=field.get_cell_size();
    Pair_d start=position;
    Pair_d finish=position;
    if(way == Up||way == Right)
        finish.x=finish.x+size_player.x;
                
    else{
        finish.y=finish.y+size_player.y;
    }

    if(way == Down || way == Right){
        start=start+size_player;
    }

    Pair_d shift=convert_to_pair(cell_size/2,way);
    start=start+shift;
    finish=finish+shift;
    std::cout<<position+size_player<<start<<finish;
    if(field.check_row(start,finish))
        reserves[way]=cell_size;
}


Player::~Player(){
    delete [] reserves;

}  



