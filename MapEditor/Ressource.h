#ifndef __MapEditor__Ressource__
#define __MapEditor__Ressource__

//Include STD
#include <map>

//Include SFML
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Ressource
{
    
private:
    
    static std::map<std::string, sf::Font>     _fonts;
    static std::map<std::string, sf::Texture>  _textures;
    
public:
    
    static sf::Font& getFont(std::string source);
    static sf::Texture& getTexture(std::string source);
    static sf::Sprite getSprite(std::string source, sf::IntRect dimension);
    
};


#endif /* defined(__MapEditor__Ressource__) */
