#include "Direction_manager.h"
#include "Direction_state.h"


Direction_manager::Direction_manager(Direction_state* state,Player& player):state(state),player(player) { //player(player)
    state->set_manager(this);
}


void Direction_manager::change_state(Direction_state* new_state){
    new_state->set_manager(this);
    delete state;
    state=new_state;
}



void Direction_manager::stop_move(direction way){
    state->stop_move(way);
}


void Direction_manager::move(float time){
    state->move(time);

}



void Direction_manager::start_move(direction way){
state->start_move(way);
}

Direction_manager::~Direction_manager(){
    delete state;
}



