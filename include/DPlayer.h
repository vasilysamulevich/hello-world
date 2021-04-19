#pragma once
#include "Player.h"
#include <SFML/Graphics.hpp>
class DPlayer: public sf::Drawable {
private:
    Player& player;
    sf::Texture player_texture;

public:
    DPlayer(Player& player,std::string path,sf::IntRect texture_bounds);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const; 



};
