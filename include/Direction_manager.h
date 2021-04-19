#pragma once
#include "Player.h"
#include <iostream>
#include "Direction_state.h"


class Direction_manager{
public:
//type

    class Direction_list{
    private:
        int hash;
        int counter;
    public:
        Direction_list():hash(0),counter(0){}

        void add_direction(direction to_set){
            hash=hash+to_set;
            counter++;
        }

        
        void remove_direction(direction to_remove){
            hash=hash-to_remove;
            if(remove_check(hash)){
                hash=hash+to_remove;
                throw  std::runtime_error("Invalid remove\n");
            }
            counter--;        
        }

        int get_count(){
            return counter;
        }


        direction get_direction(){
            if(hash!=1 && hash!=10&& hash!=100 && hash!=1000)
                throw  std::runtime_error("wtf?!!");

            return (direction) hash;   

        }

    private:
        bool remove_check(int hash){
            if(hash < 0)
                return true;
            
            while(hash > 0){
                int temp=hash%10;
                if(temp!=1 && temp!=0){
                    return true;
                }
                hash=hash/10;
            }
        return false;
        }

        };




//data
    Player& player;
    Direction_list list;
private:
    Direction_state* state;


public:
    Direction_manager (Direction_state* state,Player& player);
    void change_state(Direction_state* new_state);
    void stop_move(direction way);
    void move(float time);
    void start_move(direction way);
    ~Direction_manager();    
    




    };    



