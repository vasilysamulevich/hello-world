#include <iostream>
#include <SFML/Graphics.hpp>
#include "DField.h"
using namespace std;

string strings[]={" w   ",
                  "wwwww",
                  " www ",
                  "   w ",
                  " w w "};



int main(){
    Field first(strings,5);
    DField second(first,"./source.png",Pair_i(387,702),"./source.png",Pair_i(356,613),28,100);
    sf::RenderWindow window(sf::VideoMode(1200, 1500), "My window");

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

         window.draw(second);

        window.display();
    }


}
