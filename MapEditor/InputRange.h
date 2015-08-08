#ifndef __MapEditor__InputRange__
#define __MapEditor__InputRange__

#include "Input.h"

#include <SFML/Graphics/RectangleShape.hpp>

class InputRange : public Input
{
    
private:

    int                 m_minValue;
    int                 m_maxValue;
    unsigned int                 m_value;
    
    sf::RectangleShape  m_cursor;
    sf::RectangleShape  m_boundRectangle;
    sf::RectangleShape  m_volumeRectangle;
    
    float               m_reductionCoefficient; //Used to back base 100
    
    void update();
    void updateSize();
    void updatePosition();
    virtual void updateGraphic(); //Herited from input
    void setCursorPosition();
    
public:
    
    InputRange(sf::Vector2f position, sf::Vector2f size, int currentVal);
    ~InputRange();
    
    void draw(sf::RenderWindow& renderer);
    
    //Herited from Input
    virtual void processEvent(sf::Event& event);
    virtual void onMouseMove(sf::Event& event);
    virtual void onMousePressed(sf::Event& event);
    virtual void onMouseReleased(sf::Event& event);
    
    virtual void setPosition(sf::Vector2f position);
    virtual void setPosition(int x, int y);
    virtual void setSize(sf::Vector2f size);
    virtual void setSize(int x, int y);
    //
    
    unsigned int getValue()const;
};

#endif /* defined(__MapEditor__InputRange__) */
