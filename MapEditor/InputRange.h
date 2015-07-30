#ifndef __MapEditor__InputRange__
#define __MapEditor__InputRange__

#include "Input.h"

#include <SFML/Graphics/RectangleShape.hpp>

class InputRange : public Input
{
    
private:
    
    sf::Vector2f        m_position;
    sf::Vector2f        m_size;
    
    int                 m_minValue;
    int                 m_maxValue;
    int                 m_value;
    
    sf::RectangleShape  m_cursor;
    sf::RectangleShape  m_boundRectangle;
    sf::RectangleShape  m_volumeRectangle;
    
    float               m_reductionCoefficient; //Will be use to come to a base
    
    void update();
    void setCursorPosition();
    
public:
    
    InputRange(sf::Vector2f position, sf::Vector2f size, int currentVal);
    ~InputRange();
    
    void draw(sf::RenderWindow& renderer);
    
    //Herited from Input
    void processEvent(sf::Event& event);
    void onMouseMove(sf::Event& event);
    void onMousePressed(sf::Event& event);
    void onMouseReleased(sf::Event& event);
    
    int getValue()const;
};

#endif /* defined(__MapEditor__InputRange__) */
