#include <iostream>
#include <SFML/Graphics.hpp>
#include "DField.h"
#include "Direction_manager.h"
#include "states.h"
#include "DPlayer.h"
using namespace std;

string strings[]={"     ww  w  ",
                  "     ww w   ",
                  " www wwwwwww",
                  "   w  wwwwww",
                  " w w  w w   "};



int main(){
    Field field(strings,5,100);
    DField field_texture(field,"./source.png",Pair_i(387,702),"./source.png",Pair_i(356,613),28);
    sf::RenderWindow window(sf::VideoMode(1200, 1500), "My window");
    window.setKeyRepeatEnabled(false);
    Player player(Pair_d(100,100),Pair_d(50,50),50,field);
    DPlayer player_texture(player,"./source.png",sf::IntRect(290,367,80,49));
    sf::Clock clock;
    Empty_state* start_state=new Empty_state;     
    Direction_manager controller(start_state,player); 
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();


            if(event.type == sf::Event::KeyReleased){
                switch(event.key.code){
                    case sf::Keyboard::Left:
                    controller.stop_move(Left);
                    break;

                    case sf::Keyboard::Right:
                    controller.stop_move(Right);
                    break;

                    case sf::Keyboard::Up:
                    controller.stop_move(Up);
                    break;

                    case sf::Keyboard::Down:
                    controller.stop_move(Down);
                    break;
                }


            }


            if (event.type == sf::Event::KeyPressed){
                switch(event.key.code){
                    case sf::Keyboard::Left:
                    controller.start_move(Left);
                    break;

                    case sf::Keyboard::Right:
                    controller.start_move(Right);
                    break;

                    case sf::Keyboard::Up:
                    controller.start_move(Up);
                    break;

                    case sf::Keyboard::Down:
                    controller.start_move(Down);
                    break;
                }
        

            }



        }
        //если начали идти в этот цикл,не двигаться
        float time=clock.getElapsedTime().asSeconds();
        clock.restart();
        controller.move(time);

        window.clear(sf::Color::Black);

        window.draw(field_texture);
        window.draw(player_texture);
        window.display();
    }


}

