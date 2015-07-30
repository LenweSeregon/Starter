#ifndef __MapEditor__InputCheck__
#define __MapEditor__InputCheck__

//Include SFML
#include <SFML/Graphics/RectangleShape.hpp>

//Include Personnel
#include "Input.h"

class InputCheck : public Input
{
    
private:
    
    sf::RectangleShape  m_checkBox;
    sf::RectangleShape  m_rectangleChecker;
    bool                m_isCheck;
    
    sf::Vector2f        m_position;
    sf::Vector2f        m_size;    
    
public:
    
    InputCheck(sf::Vector2f position, sf::Vector2f size, bool valueBox);
    ~InputCheck();
    
    //Herited from Input
    void processEvent(sf::Event& event);
    void onMouseMove(sf::Event& event);
    void onMousePressed(sf::Event& event);
    void onMouseReleased(sf::Event& event);
    
    bool getEtat()const;
    
    void draw(sf::RenderWindow& renderer);
};

#endif /* defined(__MapEditor__InputCheck__) */
