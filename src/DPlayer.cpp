#include "DPlayer.h"


DPlayer::DPlayer(Player& player,std::string path,sf::IntRect texture_bounds):player(player){
    if(!player_texture.loadFromFile(path,texture_bounds))
        throw std::runtime_error("Unable to load texture for player");


}

void DPlayer::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    sf::Sprite player_sprite;
    player_sprite.setTexture(player_texture);
    sf::Vector2u texture_size=player_texture.getSize();
    Pair_d player_size=player.get_size_player();
    Pair_d player_position=player.get_position(); 
    sf::Vector2f zoom_level(player_size.x / (float) texture_size.x, player_size.y / (float) texture_size.y);
    player_sprite.setScale(zoom_level);
  //  std::cout<<player_position;
    player_sprite.setPosition(sf::Vector2f(player_position.x,player_position.y));
    target.draw(player_sprite);
}
