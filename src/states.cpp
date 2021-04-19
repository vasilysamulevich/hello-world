#include "states.h"


void Empty_state::start_move(direction way){
   (manager->list).add_direction(way); 
    Direction_state* temp=new One_direction_state;
    manager->change_state(temp); 
}


void Empty_state::move(float time){
}



void Empty_state::stop_move(direction way){
    throw  std::runtime_error("wtf?!!");

}


void One_direction_state::start_move(direction way){
    (manager->list).add_direction(way);
    Many_direction_state* temp=new Many_direction_state;
    manager->change_state(temp);

}

void One_direction_state::move(float time){
    int way=(int)(manager->list).get_direction();
    Player& player=manager->player;
    int new_direction=-1;
    while(way > 0){
    way=way/10;
    new_direction++;
    }
    player.move((Player::direction) new_direction,time);
}

void One_direction_state:: stop_move(direction way){
    (manager->list).remove_direction(way);
    Empty_state* temp=new Empty_state;
    manager->change_state(temp);
}       




void Many_direction_state::start_move(direction way){
    (manager->list).add_direction(way);
}

void Many_direction_state::stop_move(direction way){
    (manager->list).remove_direction(way);
    if((manager->list).get_count()==1){
        (manager->list).get_direction();
        One_direction_state* temp=new One_direction_state();
        manager->change_state(temp);
    }

}


void Many_direction_state::move(float time){
}










