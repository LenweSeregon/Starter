//Include STD
#include <iostream>

#include "Ressource.h"

std::map<std::string, sf::Font>     Ressource::_fonts;
std::map<std::string, sf::Texture>  Ressource::_textures;

sf::Font& Ressource::getFont(std::string source)
{
    source = "/Users/nicolasserf/Desktop/ProjetPersonnel/MapEditor/MapEditor/Ressource/Fonts/"+source;
    if(_fonts.find(source) == _fonts.end())
    {
        //Not found, create it !
        _fonts[source] = sf::Font();
        if(!_fonts[source].loadFromFile(source))
            throw std::runtime_error("Chargement impossible, la font n'existe pas");
    }
    return _fonts[source];
}

sf::Texture& Ressource::getTexture(std::string source)
{
    source = "/Users/nicolasserf/Desktop/ProjetPersonnel/MapEditor/MapEditor/Ressource/Textures/"+source;
    if(_textures.find(source) == _textures.end())
    {
        //not found, create it !
        _textures[source] = sf::Texture();
        if(!_textures[source].loadFromFile(source))
            throw std::runtime_error("Chargement impossible, la texture n'existe pas");
    }
    return _textures[source];
}

sf::Sprite Ressource::getSprite(std::string source, sf::IntRect dimension)
{
    sf::Sprite sprite;
    try
    {
        sprite.setTexture(getTexture(source));
    }
    catch (std::runtime_error& exception) {
        std::cout<<exception.what()<<std::endl;
    }
    
    if(dimension.height > 0 && dimension.width > 0)
        sprite.setTextureRect(dimension);
    
    return sprite;
}