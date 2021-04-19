#pragma once
#include "Field.h"
#include <string>
#include <SFML/Graphics.hpp>


class DField: public sf::Drawable
{
private:
    Field& field;
    sf::Texture closed;
    sf::Texture opened;

public:
    DField(Field& source,std::string path_closed,Pair_i closed_start,std::string path_opened,Pair_i opened_start,int texture_size);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
