#include "DField.h"

DField::DField(Field& source,std::string closed_path,Pair_i closed_start,std::string opened_path,Pair_i opened_start,int texture_size): field(source)
{
    if(!opened.loadFromFile(opened_path,sf::IntRect(opened_start.x,opened_start.y,texture_size,texture_size)))
        throw std::runtime_error("Unable to load texture for opened cell"); 

    if(!closed.loadFromFile(closed_path,sf::IntRect(closed_start.x,closed_start.y,texture_size,texture_size)))
        throw std::runtime_error("Unable to load texture for closed cell");


}

void DField::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    int texture_size=opened.getSize().x;
    int sprite_size=field.get_cell_size();
    Pair_i bounds=field.get_field_size();
    for(int i=0;i<bounds.x;i++){
        for(int j=0; j<bounds.y;j++){
            Pair_i current_coord(i,j);
            sf::Sprite current_sprite;
            float zoom_level=(float)sprite_size/(float) texture_size;
            sf::Vector2f position(i*sprite_size,j*sprite_size);    
        Cell* current_cell=field.get_cell(current_coord);
        switch(current_cell->get_content()){
        case Cell::pass:
            current_sprite.setTexture(opened);
            current_sprite.setScale(sf::Vector2f(zoom_level,zoom_level));
            current_sprite.setPosition(position);
            target.draw(current_sprite);
        break;
    
        case Cell::unpass:
            current_sprite.setTexture(closed);
            current_sprite.setScale(sf::Vector2f(zoom_level,zoom_level));
            current_sprite.setPosition(position);
            target.draw(current_sprite);
        break;

        }
         
        } 
    }



}
